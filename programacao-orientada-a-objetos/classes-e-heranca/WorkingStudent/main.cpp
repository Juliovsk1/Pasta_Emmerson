#include <iostream>
#include "WorkingStudent.h"

using namespace std;

int main() {
    cout << "=== Objeto 1: construtor default ===" << endl;
    WorkingStudent ws1;
    ws1.setName("Carlos");
    ws1.setBirthYear(2001);
    ws1.setCourse("Ciencia da Computacao");
    ws1.setGradeAverage(8.7);
    ws1.setCompany("Tech Solutions");
    ws1.setSalary(1800.0);
    ws1.setWeeklyHours(30);
    ws1.print();

    cout << "\n=== Objeto 2: construtor com parametros ===" << endl;
    WorkingStudent ws2("Ana", 2000, "Engenharia de Software", 9.2,
                       "Inova Systems", 2500.0, 20);
    ws2.print();

    cout << "\n=== Objeto 3: construtor de copia ===" << endl;
    WorkingStudent ws3(ws2);
    ws3.print();

    cout << "\n=== Objeto 4: operador de atribuicao ===" << endl;
    WorkingStudent ws4;
    ws4 = ws1;
    ws4.print();

    cout << "\n=== Operador + na parte Employee ===" << endl;
    Employee emp1("Marcos", 1995, "Empresa X", 3000.0);
    Employee emp2 = emp1 + 500.0;

    cout << "Funcionario original:" << endl;
    emp1.print();

    cout << "\nFuncionario com aumento:" << endl;
    emp2.print();

    cout << "\n=== Operador == na parte Student ===" << endl;
    Student st1("Julia", 2002, "ADS", 8.5);
    Student st2("Julia", 2002, "ADS", 8.5);

    if (st1 == st2) {
        cout << "Os estudantes sao iguais." << endl;
    } else {
        cout << "Os estudantes sao diferentes." << endl;
    }

    return 0;
}