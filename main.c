#include <stdio.h>
#include <stdlib.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"
#include "testing.h"
#include "validation.h"

int main() {
    int choice;
    while (1) {
        printf("\n================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
        printf("\n================\n");
        printf("1. Employees Management\n");
        printf("2. Budget Management\n");
        printf("3. Suppliers Management\n");
        printf("4. Assets Management\n");
        printf("5. Reports\n");
        printf("6 Run System Diagnostics\n");
        printf("7. Exit\n");
        printf("====================\n");
        printf("Enter your choice: ");

        choice = getValidTnt("Enter your chaice (1-7): ");

        if (choice == 7) {
            printf("\nExisting system. Goodbye.\n");
            break;      
        }

        switch (choice) {
            case 1: printf("\n[Employee Module Selected]\n");
            break;
            case 2: printf("\n[Budget Module Selected]\n");
            break;
            case 3: printf("\n[Suppliers Module Selected]\n");
            break;
            case 4: printf("\n[Assets Module Selected]\n");
            break;
            case 5: printf("\n[Reports Module Selected]\n");
            break;
            case 6: runSystemTests(); //calls code in testing.c
            break;
            default: printf("\nInvalid choice. Try again. Please enter a number between 1 and 7.\n");
        }
    }
    return 0;
}