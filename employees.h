#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50

// Employee structure
struct Employee {
    int id;
    char name[50];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    char email[50];
};

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateSalary();

#endif
