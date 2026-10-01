#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50
struct Employee {
    int id;
    char name[50];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    char email[50];
};

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

int main() {
    printf("Employee Management System\n");
    printf("welcome to employee management");

    return 0;
}