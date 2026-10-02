#include <stdio.h>
#include <string.h>
#include "reports.h"

/* Helper function for menu input validation */
static int readIntegerInput(void) {
    int value;
    if (scanf("%d", &value) != 1) {
        while (getchar() != '\n'); /* Clear invalid input stream */
        return -1;
    }
    return value;
}

/* 1. Employee Report: Calculates Total, Average, Highest, and Lowest Salary */
void generateEmployeeReport(const Employee employees[], int count) {
    printf("\n=========================================\n");
    printf("            EMPLOYEE REPORT              \n");
    printf("=========================================\n");

    if (count <= 0) {
        printf("No employee records found.\n");
        printf("=========================================\n");
        return;
    }

    double totalSalarySum = 0.0;
    double highestSalary = 0.0;
    double lowestSalary = 0.0;

    for (int i = 0; i < count; i++) {
        double totalSalary = employees[i].basicSalary + 
                             employees[i].housingAllowance + 
                             employees[i].transportAllowance;

        totalSalarySum += totalSalary;

        if (i == 0) {
            highestSalary = totalSalary;
            lowestSalary = totalSalary;
        } else {
            if (totalSalary > highestSalary) {
                highestSalary = totalSalary;
            }
            if (totalSalary < lowestSalary) {
                lowestSalary = totalSalary;
            }
        }
    }

    double averageSalary = totalSalarySum / count;

    printf("Total Employees : %d\n", count);
    printf("Average Salary  : N$%.2f\n", averageSalary);
    printf("Highest Salary  : N$%.2f\n", highestSalary);
    printf("Lowest Salary   : N$%.2f\n", lowestSalary);
    printf("=========================================\n");
}

/* 2. Budget Report: Calculates Allocated, Expenditure, Remaining, & Exceeded Departments */
void generateBudgetReport(const Budget budgets[], int count) {
    printf("\n=========================================\n");
    printf("             BUDGET REPORT               \n");
    printf("=========================================\n");

    if (count <= 0) {
        printf("No department budget records found.\n");
        printf("=========================================\n");
        return;
    }

    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;

    for (int i = 0; i < count; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    double remainingBudget = totalAllocated - totalExpenditure;

    printf("Total Allocated Budget : N$%.2f\n", totalAllocated);
    printf("Total Expenditure      : N$%.2f\n", totalExpenditure);
    printf("Remaining Budget       : N$%.2f\n", remainingBudget);
    printf("-----------------------------------------\n");
    printf("Departments Exceeding Budget:\n");

    int exceededCount = 0;
    for (int i = 0; i < count; i++) {
        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            double deficit = budgets[i].expenditure - budgets[i].allocatedBudget;
            printf(" - %s (Over budget by N$%.2f)\n", budgets[i].name, deficit);
            exceededCount++;
        }
    }

    if (exceededCount == 0) {
        printf(" None. All departments are operating within allocated budgets.\n");
    }
    printf("=========================================\n");
}

/* 3. Supplier Report: Lists registered suppliers */
void generateSupplierReport(const Supplier suppliers[], int count) {
    printf("\n=========================================================================\n");
    printf("                             SUPPLIER REPORT                             \n");
    printf("=========================================================================\n");

    if (count <= 0) {
        printf("No supplier records found.\n");
        printf("=========================================================================\n");
        return;
    }

    printf("%-5s | %-20s | %-20s | %-12s | %-10s\n", "ID", "Name", "Email", "Phone", "Location");
    printf("-------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d | %-20s | %-20s | %-12s | %-10s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].location);
    }
    printf("-------------------------------------------------------------------------\n");
    printf("Total Registered Suppliers: %d\n", count);
    printf("=========================================================================\n");
}

/* 4. Asset Report: Lists registered assets and total valuation */
void generateAssetReport(const Asset assets[], int count) {
    printf("\n=========================================================================\n");
    printf("                              ASSET REPORT                               \n");
    printf("=========================================================================\n");

    if (count <= 0) {
        printf("No asset records found.\n");
        printf("=========================================================================\n");
        return;
    }

    printf("%-5s | %-18s | %-12s | %-12s | %-15s | %-10s\n", 
           "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
    printf("-------------------------------------------------------------------------\n");

    double totalAssetValue = 0.0;
    for (int i = 0; i < count; i++) {
        totalAssetValue += assets[i].purchaseValue;
        printf("%-5d | %-18s | %-12s | %-12.2f | %-15s | %-10s\n",
               assets[i].id,
               assets[i].name,
               assets[i].type,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
    }
    printf("-------------------------------------------------------------------------\n");
    printf("Total Assets Registered : %d\n", count);
    printf("Total Asset Value      : N$%.2f\n", totalAssetValue);
    printf("=========================================================================\n");
}

/* Reports Menu Implementation */
void displayReportsMenu(const Employee employees[], int empCount,
                        const Budget budgets[], int budgetCount,
                        const Supplier suppliers[], int suppCount,
                        const Asset assets[], int assetCount) {
    int choice = 0;

    while (choice != 6) {
        printf("\n=== REPORTS MANAGEMENT MENU ===\n");
        printf("1. Display Employee Report\n");
        printf("2. Display Budget Report\n");
        printf("3. Display Supplier Report\n");
        printf("4. Display Asset Report\n");
        printf("5. Display All Reports\n");
        printf("6. Return to Main Menu\n");
        printf("Enter option (1-6): ");

        choice = readIntegerInput();

        switch (choice) {
            case 1:
                generateEmployeeReport(employees, empCount);
                break;
            case 2:
                generateBudgetReport(budgets, budgetCount);
                break;
            case 3:
                generateSupplierReport(suppliers, suppCount);
                break;
            case 4:
                generateAssetReport(assets, assetCount);
                break;
            case 5:
                generateEmployeeReport(employees, empCount);
                generateBudgetReport(budgets, budgetCount);
                generateSupplierReport(suppliers, suppCount);
                generateAssetReport(assets, assetCount);
                break;
            case 6:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid selection! Please enter a number between 1 and 6.\n");
                break;
        }
    }
}