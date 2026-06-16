#include <vector>
#include <random>
#include <climits>

using namespace std;

const int MAX_LEVEL = 4; // log2(n) para n esperado

struct SkipNode {
    int key;
    // forward[i] = ponteiro para próximo nó no NÍVEL i
    vector<SkipNode*> forward;

    SkipNode(int k, int lvl) 
        : key(k), forward(lvl + 1, nullptr) {}
};

class SkipList {
private: 
    SkipNode* head;     // sentinela com key = -infinito]
    int       level;    // nível máximo atual
    mt19937   rng;      

    // Nível aleatório: p=0.5 -> cada nível tem 50% de probabilidade
    int randomlevel() {
        int lvl = 0;
        uniform_real_distribution<float> dist(0.0f, 1.0f);
        while (dist(rng) < 0.5f && lvl < MAX_LEVEL-1)
        ++lvl;
        return lvl;
    };

public:
    SkipList() : level(0), rng(random_device{}()) {
        head = new SkipNode(INT_MIN, MAX_LEVEL);
    }

    // Busca: começa no nível mais alto, desce quando necessário
    bool search(int key) {
        SkipNode* cur = head;
        for (int i = level; i >= 0; --i) {
            // avança no nível i enquanto o próximo é menor que kay
            while (cur->forward[i] && cur->forward[i]->key < key)
            cur = cur->forward[i];
            // Desce para o nível inferior (mais granular)
        }
        cur = cur->forward[0];
        return cur && cur->key == key;
    }

    // Inserção: determina nível aleátorio, atualiza ponteiros
    void insert(int key) {
        vector<SkipNode*> update(MAX_LEVEL, nullptr);
        SkipNode* cur = head;


        // Encontro o ponto de inserção em cada nível
        for (int i = level; i >= 0; --i) {
            while (cur->forward[i] && cur->forward[i]->key < key)
                cur = cur ->forward[i];
            update[i] = cur;
        }
        int newLvl = randomlevel();
    }
};