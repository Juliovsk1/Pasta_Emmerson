#include <iostream>
#include "WorkingStudent.h"

using namespace std;

WorkingStudent::WorkingStudent()
    : Person(), weeklyHours(0)
{
    // Inicializar membros de Student e Employee
    course = "Undefined";
    gradeAverage = 0.0;
    company = "Undefined";
    salary = 0.0;
   
    cout << "WorkingStudent: construtor default" << endl;
}

WorkingStudent::WorkingStudent(const string& name, int birthYear,
                               const string& course, double gradeAverage,
                               const string& company, double salary,
                               int weeklyHours)
    : Person(name, birthYear),
      weeklyHours(weeklyHours)
{
    // Inicializar membros herdados
    this->course = course;
    this->gradeAverage = gradeAverage;
    this->company = company;
    this->salary = salary;
   
    cout << "WorkingStudent: construtor com parametros" << endl;
}

WorkingStudent::WorkingStudent(const WorkingStudent& other)
    : Person(other),
      weeklyHours(other.weeklyHours)
{
    // Copiar membros herdados
    course = other.course;
    gradeAverage = other.gradeAverage;
    company = other.company;
    salary = other.salary;
   
    cout << "WorkingStudent: construtor de copia" << endl;
}

WorkingStudent& WorkingStudent::operator=(const WorkingStudent& other)
{
    cout << "WorkingStudent: operador de atribuicao" << endl;

    if (this != &other) {
        Person::operator=(other);  // Atribuir parte Person uma vez
       
        // Atribuir membros herdados
        course = other.course;
        gradeAverage = other.gradeAverage;
        company = other.company;
        salary = other.salary;
        weeklyHours = other.weeklyHours;
    }
    return *this;
}

WorkingStudent::~WorkingStudent() {
    cout << "WorkingStudent: destrutor" << endl;
}

int WorkingStudent::getWeeklyHours() const {
    return weeklyHours;
}

void WorkingStudent::setWeeklyHours(int weeklyHours) {
    this->weeklyHours = weeklyHours;
}

void WorkingStudent::print() const {
    cout << "===== Working Student =====" << endl;
    Person::print();  // Melhor prática: chamar print da base
    cout << "Curso: " << course << endl;
    cout << "Media: " << gradeAverage << endl;
    cout << "Empresa: " << company << endl;
    cout << "Salario: " << salary << endl;
    cout << "Horas semanais de trabalho: " << weeklyHours << endl;
}