#include <string>
#include <optional>
using namespace std;

enum class Kind { VAR, FUNC, TYPE, PARAM};

struct Symbol {
    string name;
    string type;
    Kind kind;
    int scope;
    int offset;
    Symbol* next;

    Symbol(string n, string t, Kind k, int s, int off=0)
        : name(n), type(t), kind(k), scope(s), offset(off), next(nullptr) {}
};

class SymbolTable {
static constexpr size_t BUCKETS = 7; // prime -> melhor distribuição
    
private: 
    Symbol* table[BUCKETS] = {}; // array de cabeças da lista

    // Função de hash obj2 (Dan Bernstein) - usada em muitos compiladores
    size_t hash(const string& s) const {
        size_t h = 5381;
        for (char c : s) h = ((h << 5) + h) + c;  // h*33 + c
        return h % BUCKETS;
    }

public:
    // Insere símbolo (no início do bucket - 0(1))
    void insert(string n, string t, Kind k, int s) {
        size_t idx = hash(n);
        Symbol* sym = new Symbol(n, t, k, s);
        sym->next = table[idx]; // insense na frente da lista
        table[idx] = sym;
    }

    // Busca símbolo no escopo mais interno primeiro - 0(k) chains
    Symbol* lookup(const string& n) const {
        Symbol* sym = table[hash(n)];
        while (sym) {
            if (sym->name == n) return sym;
            sym = sym->next;
        }
        return nullptr; //símbolo não declarado -> erro de compilação
    }

    // Erro símbolos do escopo ao sair de um bloco
    void exitScop(int scope) {
        for (auto& head : table) {
            while (head && head->scope == scope) {
                Symbol* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
    }
    
};