#include <stdio.h>
#include <string.h>
#include "employees.h"

struct Employee employees[MAX_EMPLOYEES];
int count = 0;

void addEmployee() {
    if (count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    struct Employee e;
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Employee Name: ");
    scanf("%s", e.name);
    printf("Enter Department: ");
    scanf("%s", e.department);
    printf("Enter Basic Salary: ");
    scanf("%f", &e.basicSalary);
    printf("Enter Housing Allowance: ");
    scanf("%f", &e.housingAllowance);
    printf("Enter Transport Allowance: ");
    scanf("%f", &e.transportAllowance);
    printf("Enter Email: ");
    scanf("%s", e.email);
 
    employees[count++] = e;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nDepartment: %s\nBasic Salary: %.2f\nHousing: %.2f\nTransport: %.2f\nEmail: %s\n",
               employees[i].id, employees[i].name, employees[i].department,
               employees[i].basicSalary, employees[i].housingAllowance,
               employees[i].transportAllowance, employees[i].email);
    }
}

void searchEmployee() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Employee Found!\nName: %s\nDepartment: %s\nEmail: %s\n", 
                   employees[i].name, employees[i].department, employees[i].email);
            return;
        }
    }
    printf("Employee not found.\n");
}

void calculateSalary() {
    int id;
    printf("Enter Employee ID to calculate salary: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            float total = employees[i].basicSalary +
                          employees[i].housingAllowance +
                          employees[i].transportAllowance;
            printf("Total Salary for %s: %.2f\n", employees[i].name, total);
            return;
        }
    }
    printf("Employee not found.\n");
}
int main_employee_test() {
    printf("Employee Management System\n");
    printf("welcome to employee management");

    return 0;
}