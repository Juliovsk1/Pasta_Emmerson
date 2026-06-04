#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
std::string name;
int birthYear;

public:
    // Construtor defoult
    Person();

    // Cosntrutor com parâmetros
    Person(const std::string& name, int birthYear);

    // Construtor de cópia
    Person(const Person& other);

    // Operador de distribuição
    Person& operator=(const Person& other);

    // Operador de comparação
    bool operator==(const Person& other) const;

    // Destrutor
    virtual ~Person();     // Prevenção de memory leak

    // Métodos de acesso
    std::string getName() const;
    int getBirthYear() const;

    void setName(const std::string& name);
    void setBirthYear(int birthYear);

    virtual void print() const; // Polimorfismo dinâmico, garante que sobrescreva a função em uma classe derivada
};

#endif // PERSON_H