//A herança virtual garante que apenas uma única instância da classe base Person seja compartilhada entre todas as classes derivadas, mesmo quando a herança ocorre em múltiplos caminhos (herança múltipla).

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : virtual public Person {
protected:
    std::string course;
    double gradeAverage;

public:
    Student();
    Student(const std::string& name, int birthYear,
            const std::string& course, double gradeAverage);
    Student(const Student& other);

    Student& operator=(const Student& other);

    // Operador para comparar estudantes
    bool operator==(const Student& other) const;

    virtual ~Student();

    std::string getCourse() const;
    double getGradeAverage() const;

    void setCourse(const std::string& course);
    void setGradeAverage(double gradeAverage);

    void print() const override;
};

#endif