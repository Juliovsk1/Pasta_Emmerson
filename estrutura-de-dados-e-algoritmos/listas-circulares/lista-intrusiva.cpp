#include <cstdint>
#include <cstddef>
#include <iostream>

// Exemplo basico de Free List.
//
// A ideia e administrar manualmente um bloco fixo de memoria.
// Quando um pedaco esta livre, ele entra em uma lista encadeada de blocos
// livres. Quando alguem pede memoria, removemos um bloco dessa lista.
class FreeList {
private:
    struct BlockHeader {
        std::size_t size;     // tamanho da area util depois do header
        BlockHeader* next;    // proximo bloco livre
        bool free;            // true = livre, false = em uso
    };

    static constexpr std::size_t CAPACITY = 256;

    // std::uint8_t representa bytes crus.
    // alignas(std::max_align_t) ajuda o buffer a servir para tipos comuns.
    alignas(std::max_align_t) std::uint8_t memory[CAPACITY];

    BlockHeader* free_head;

    static constexpr std::size_t header_size() {
        return sizeof(BlockHeader);
    }

public:
    FreeList() {
        // No inicio, todo o buffer e um unico bloco livre.
        free_head = reinterpret_cast<BlockHeader*>(memory);
        free_head->size = CAPACITY - header_size();
        free_head->next = nullptr;
        free_head->free = true;
    }

    void* allocate(std::size_t bytes) {
        BlockHeader* previous = nullptr;
        BlockHeader* current = free_head;

        // Procura o primeiro bloco livre grande o suficiente.
        while (current != nullptr && current->size < bytes) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            return nullptr; // nao ha espaco suficiente
        }

        // Se sobrar espaco para outro bloco, dividimos o bloco atual.
        const std::size_t remaining = current->size - bytes;
        if (remaining > header_size()) {
            std::uint8_t* raw_current = reinterpret_cast<std::uint8_t*>(current);

            auto* new_block = reinterpret_cast<BlockHeader*>(
                raw_current + header_size() + bytes
            );

            new_block->size = remaining - header_size();
            new_block->next = current->next;
            new_block->free = true;

            current->size = bytes;

            if (previous == nullptr) {
                free_head = new_block;
            } else {
                previous->next = new_block;
            }
        } else {
            // Se a sobra for pequena demais, entregamos o bloco inteiro.
            if (previous == nullptr) {
                free_head = current->next;
            } else {
                previous->next = current->next;
            }
        }

        current->next = nullptr;
        current->free = false;

        // O usuario recebe o endereco logo depois do header.
        return reinterpret_cast<std::uint8_t*>(current) + header_size();
    }

    void deallocate(void* pointer) {
        if (pointer == nullptr) {
            return;
        }

        // Volta do endereco util para o inicio do bloco, onde esta o header.
        auto* block = reinterpret_cast<BlockHeader*>(
            static_cast<std::uint8_t*>(pointer) - header_size()
        );

        // Reinsere o bloco no comeco da lista de livres.
        block->free = true;
        block->next = free_head;
        free_head = block;
    }

    void print_free_blocks() const {
        const BlockHeader* current = free_head;

        std::cout << "Blocos livres:\n";
        while (current != nullptr) {
            std::cout << "- " << current->size << " bytes\n";
            current = current->next;
        }
    }
};

int main() {
    FreeList allocator;

    void* a = allocator.allocate(32);
    void* b = allocator.allocate(48);

    std::cout << "Depois de alocar 32 e 48 bytes:\n";
    allocator.print_free_blocks();

    allocator.deallocate(a);

    std::cout << "\nDepois de liberar o bloco de 32 bytes:\n";
    allocator.print_free_blocks();

    void* c = allocator.allocate(16);

    std::cout << "\nDepois de alocar 16 bytes, reaproveitando a free list:\n";
    allocator.print_free_blocks();

    allocator.deallocate(b);
    allocator.deallocate(c);

    return 0;
}
