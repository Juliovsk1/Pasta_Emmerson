#include <iostream>
#include "Student.h"

using namespace std;

Student::Student() : Person(), course("Undefined"), gradeAverage(0.0) {
    cout << "Student: construtor default" << endl;
}

Student::Student(const string& name, int birthYear,
                 const string& course, double gradeAverage)
    : Person(name, birthYear), course(course), gradeAverage(gradeAverage) {
    cout << "Student: construtor com parametros" << endl;
}

Student::Student(const Student& other)
    : Person(other), course(other.course), gradeAverage(other.gradeAverage) {
    cout << "Student: construtor de copia" << endl;
}

Student& Student::operator=(const Student& other) {
    cout << "Student: operador de atribuicao" << endl;

    if (this != &other) {
        Person::operator=(other);
        course = other.course;
        gradeAverage = other.gradeAverage;
    }

    return *this;
}

bool Student::operator==(const Student& other) const {
    return Person::operator==(other) &&
           course == other.course &&
           gradeAverage == other.gradeAverage;
}

Student::~Student() {
    cout << "Student: destrutor" << endl;
}

string Student::getCourse() const {
    return course;
}

double Student::getGradeAverage() const {
    return gradeAverage;
}

void Student::setCourse(const string& course) {
    this->course = course;
}

void Student::setGradeAverage(double gradeAverage) {
    this->gradeAverage = gradeAverage;
}

void Student::print() const {
    Person::print();
    cout << "Curso: " << course << endl;
    cout << "Media: " << gradeAverage << endl;
}