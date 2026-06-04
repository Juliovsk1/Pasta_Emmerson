#ifndef WORKINGSTUDENT_H
#define WORKINGSTUDENT_H

#include "Student.h"
#include "Employee.h"

class WorkingStudent : public Student, public Employee {
private:
    int weeklyHours;

public:
    WorkingStudent();
    WorkingStudent(const std::string& name, int birthYear,
                   const std::string& course, double gradeAverage,
                   const std::string& company, double salary,
                   int weeklyHours);
    WorkingStudent(const WorkingStudent& other);

    WorkingStudent& operator=(const WorkingStudent& other);

    virtual ~WorkingStudent();

    int getWeeklyHours() const;
    void setWeeklyHours(int weeklyHours);

    void print() const override;
};

#endif