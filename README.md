# 📚 Estudos de POO & Estrutura de Dados (C++)

Repositório dedicado ao armazenamento e organização de códigos de estudo em C++, com foco em **Programação Orientada a Objetos (POO)**, **Estruturas de Dados básicas** e **Algoritmos**.

---

## 📂 Estrutura do Repositório

O repositório está organizado da seguinte forma:

```text
.
├── 💻 programacao-orientada-a-objetos/   # Códigos de POO
│   ├── classes-e-heranca/                # Herança, classes virtuais, múltipla herança
│   │   ├── Derivadas/                    # Exemplos práticos de herança derivada
│   │   ├── Forma/                        # Polimorfismo com formas geométricas
│   │   ├── Person/                       # Classes Person e Employee (Base/Derivada)
│   │   ├── Student/                      # Classe Student com herança virtual de Person
│   │   └── WorkingStudent/               # Exemplo de herança múltipla (Student & Employee)
│   ├── tratamento-de-erros/              # Tratamento de exceções (try/catch, re-throw)
│   └── templates-e-polimorfismo/         # Templates e polimorfismo dinâmico
│
├── ⚡ estrutura-de-dados-e-algoritmos/     # ED & Algoritmos de ordenação
│   ├── estruturas-encadeadas/            # Nós e Listas Encadeadas (simples e dupla)
│   └── algoritmos-ordenacao/             # Algoritmos clássicos de ordenação (Bubble, Quick, TimSort, etc.)
│
├── 🏆 competitiva/                       # Códigos de Programação Competitiva (ex: OBI)
└── 📄 documentacao/                      # Anotações e resumos em formato .odt
```

---

## 🛠️ Como Compilar e Executar

Para compilar e executar os códigos em C++, você precisará de um compilador C++ (como o `g++` do GCC).

### Compilação Geral (Terminal)
Abra a pasta do arquivo que deseja rodar no seu terminal e execute:

```bash
g++ -std=c++17 -Wall nome_do_arquivo.cpp -o executavel
./executavel
```

### Exemplo de Compilação com Múltiplas Classes (Herança Múltipla)
Para o exemplo de `WorkingStudent`, que depende das classes `Student`, `Employee` e `Person`, você deve compilar os arquivos fontes juntos. A partir do diretório `programacao-orientada-a-objetos/classes-e-heranca/WorkingStudent/`:

```bash
g++ -std=c++17 -Wall main.cpp WorkingStudent.cpp ../Student/Student.cpp ../Person/Person.cpp ../Person/Employee.cpp -I. -I../Student -I../Person -o main
./main
```

---

## 📝 Assuntos Cobertos

### 1. Programação Orientada a Objetos (POO)
* **Encapsulamento e Abstração**: Modelagem de classes com atributos públicos, protegidos e privados.
* **Herança Simples e Múltipla**: Reutilização de código entre classes.
* **Herança Virtual**: Resolução do problema do "Diamante" na herança múltipla em C++.
* **Polimorfismo**: Sobrecarga de operadores e métodos virtuais puros (`override`).
* **Tratamento de Exceções**: Uso de `try`, `catch`, `throw`, relançamento de exceções (`re-throw`) e classes customizadas de exceção herdando de `std::exception`.

### 2. Estrutura de Dados & Algoritmos
* **Listas Encadeadas**: Implementação de Nós Simples (`no.cpp`) e Nós Duplos (`noDuplo.cpp`).
* **Algoritmos de Ordenação**:
  * Bubble Sort
  * Insertion Sort
  * Selection Sort
  * Merge Sort
  * Quick Sort
  * TimSort (híbrido)

---

## 👤 Professor
* **Emmerson**
