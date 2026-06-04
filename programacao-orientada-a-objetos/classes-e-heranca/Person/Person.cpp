#include <iostream>
#include "Person.h"

using namespace std;

Person::Person() : name("Unknown"), birthYear(0) {
    cout << "Person: construtor default" << endl;
}

Person::Person(const string& name, int birthYear)
    : name(name), birthYear(birthYear) {
    cout << "Person: construtor com parametros" << endl;
}

Person::Person(const Person& other)
    : name(other.name), birthYear(other.birthYear) {
    cout << "Person: construtor de copia" << endl;
}

Person& Person::operator=(const Person& other) {
    cout << "Person: operador de atribuicao" << endl;

    if (this != &other) {
        name = other.name;
        birthYear = other.birthYear;
    }

    return *this;
}

bool Person::operator==(const Person& other) const {
    return name == other.name && birthYear == other.birthYear;
}

Person::~Person() {
    cout << "Person: destrutor" << endl;
}

string Person::getName() const {
    return name;
}

int Person::getBirthYear() const {
    return birthYear;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setBirthYear(int birthYear) {
    this->birthYear = birthYear;
}

void Person::print() const {
    cout << "Nome: " << name << endl;
    cout << "Ano de nascimento: " << birthYear << endl;
}