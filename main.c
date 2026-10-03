#include <stdio.h>
#include <stdlib.h>
#include "validation.h"

int manageEmployees() { printf("\n--- Employee Module (Under Construction) ---\n"); return 0; }
int manageBudgets()   { printf("\n--- Budget Module (Under Construction) ---\n"); return 0; }
int manageAssets()    { printf("\n--- Asset Module (Under Construction) ---\n"); return 0; }

int main() {
    int choice = 0;

    do {
        printf("\n========================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Asset Management\n");
        printf("4. Exit\n");
        printf("========================================\n");
        
        
        choice = getValidInt("Enter your choice (1-4): ");

        switch (choice) {
            case 1: manageEmployees(); break;
            case 2: manageBudgets(); break;
            case 3: manageAssets(); break;
            case 4: printf("\nExiting system. Goodbye!\n"); break;
            default: printf("\nInvalid option. Please choose a number from 1 to 4.\n"); break;
        }
    } while (choice != 4);

    return 0;
}