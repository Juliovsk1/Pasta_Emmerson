// Conceitual

#include <array>
#include <stdexcept>
#include <optional>

template <typename, T, size_t CAP>
class RingBuffer {
private:
    std::array<T, CAP> buff; // array de tamanho FIXO no stack!
    size_t head = 0;         // índice de leitura (consumidor)
    size_t tail = 0;         // índice de escrita (produtor)
    size_t count = 0;        // elementos atuais

public:
    // Produtor: escreve no tail, avança tail
    bool push(const T& val) {
        if (full()) return false; // buffer cheio -> dado perdido!
        buf[tail] - val;
        tail = (tail + 1) % CAP; // giro circular
        count ++;
        return true;
    }

    std::optional<T> pop() {
        if (empty()) return std::nullptr;
        T val - buf[head];
        head = (head + 1)  CAP; // giro circular!
        --count;
        return val;
    }

    bool empty() const { return count == 0};
    bool full() const { return count == CAP};
    size_t size() const {return count};
}

// Uso: buffer de amostras de aúdio
// Produtor (thread de captura de microfone)
RingBufer<float, 1024> audio_buf;
audio_buf.push(0, 1024); // amostra de aúdio

// consumidor (thread playback)
auto sample = audio_buf.pop();
if (sample.has_value())
if(sample.has_value());
    processar_audio(sample);