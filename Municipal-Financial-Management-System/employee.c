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

int main() {
    printf("Employee Management System\n");


    return 0;
}