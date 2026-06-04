
#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee() : Person(), company("Undefined"), salary(0.0) {
    cout << "Employee: construtor default" << endl;
}

Employee::Employee(const string& name, int birthYear,
                   const string& company, double salary)
    : Person(name, birthYear), company(company), salary(salary) {
    cout << "Employee: construtor com parametros" << endl;
}

Employee::Employee(const Employee& other)
    : Person(other), company(other.company), salary(other.salary) {
    cout << "Employee: construtor de copia" << endl;
}

Employee& Employee::operator=(const Employee& other) {
    cout << "Employee: operador de atribuicao" << endl;

    if (this != &other) {
        Person::operator=(other);
        company = other.company;
        salary = other.salary;
    }

    return *this;
}

Employee Employee::operator+(double increase) const {
    Employee temp(*this);
    temp.salary += increase;
    return temp;
}

Employee::~Employee() {
    cout << "Employee: destrutor" << endl;
}

string Employee::getCompany() const {
    return company;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setCompany(const string& company) {
    this->company = company;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

void Employee::print() const {
    Person::print();
    cout << "Empresa: " << company << endl;
    cout << "Salario: " << salary << endl;
}