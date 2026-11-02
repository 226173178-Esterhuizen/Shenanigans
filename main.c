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

    Supplier suppliersArray[MAX_SUPPLIERS];
    int supplierCount = 0;
        // Missing Employee Arrays & Counters
    Employee employeesArray[100];
    int employeeCount = 0;

    // Missing Budget Arrays & Counters
    Budget budgetsArray[20];
    int budgetCount = 0;

    // Missing Asset Arrays & Counters
    Asset assetsArray[100];
    int assetCount = 0;

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
        

        choice = getValidInt("Enter your choice (1-7): ");

        if (choice == 7) {
            printf("\nExisting system. Goodbye.\n");
            break;      
        }

        switch (choice) {
            case 1: 
            printf("\nEntering Employee Management Functons...\n");
            addEmployee();
            break;
            case 2: budgetMenu();
            break;
            case 3: supplierMenu(suppliersArray, &supplierCount);
            break;
            case 4: manageAssets();
            break;
            case 5: displayReportsMenu(employeesArray, employeeCount, budgetsArray, budgetCount, suppliersArray, supplierCount, assetsArray, assetCount);
            break;
            case 6: runSystemTests(); //calls code in testing.c
            break;
            default: printf("\nInvalid choice. Try again. Please enter a number between 1 and 7.\n");
            break;
        }
    }
    return 0;
}