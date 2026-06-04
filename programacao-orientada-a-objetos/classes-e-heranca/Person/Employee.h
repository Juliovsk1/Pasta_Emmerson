#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : virtual public Person {
protected:
    std::string company;
    double salary;

public:
    Employee();
    Employee(const std::string& name, int birthYear,
             const std::string& company, double salary);
    Employee(const Employee& other);

    Employee& operator=(const Employee& other);

    // Operador +
    Employee operator+(double increase) const;

    virtual ~Employee();

    std::string getCompany() const;
    double getSalary() const;

    void setCompany(const std::string& company);
    void setSalary(double salary);

    void print() const override;
};

#endif