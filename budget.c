
#include <stdio.h>
#include <string.h>
#include "budget.h"

char  deptName[MAX_DEPARTMENTS][50];
float deptAllocated[MAX_DEPARTMENTS];
float deptSpent[MAX_DEPARTMENTS];
int   deptCount = 0;

void  addDepartmentBudget(void);
void  enterExpenditure(void);
void  displayBudgets(void);
void  showOverBudgetDepartments(void);
int   findDepartment(char name[]);
float calculateRemaining(float allocated, float spent);

void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n--- BUDGET MANAGEMENT ---\n");
        printf("1. Add Department Budget\n");
        printf("2. Enter Expenditure\n");
        printf("3. Display All Budgets\n");
        printf("4. Show Over-Budget Departments\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addDepartmentBudget();       break;
            case 2: enterExpenditure();          break;
            case 3: displayBudgets();            break;
            case 4: showOverBudgetDepartments(); break;
            case 5: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}

void addDepartmentBudget(void)
{
    char  name[50];
    float amount;

    if (deptCount >= MAX_DEPARTMENTS)
    {
        printf("Budget list is full.\n");
        return;
    }

    printf("Enter department name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == 0)
    {
        printf("Name cannot be empty.\n");
        return;
    }

    if (findDepartment(name) != -1)
    {
        printf("Department already exists.\n");
        return;
    }

     printf("Enter allocated budget: ");
    scanf("%f", &amount);
    getchar();

    if (amount < 0)
    {
        printf("Budget cannot be negative.\n");
        return;
    }

    strcpy(deptName[deptCount], name);
    deptAllocated[deptCount] = amount;
    deptSpent[deptCount]     = 0;
    deptCount++;

    printf("Department added.\n");
}

void enterExpenditure(void)
{
    char  name[50];
    float amount;
    int   index;

    if (deptCount == 0)
    {
        printf("No departments yet.\n");
        return;
    }

    printf("Enter department name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    index = findDepartment(name);

    if (index == -1)
    {
        printf("Department not found.\n");
        return;
    }

    printf("Enter expenditure amount: ");
    scanf("%f", &amount);
    getchar();

    if (amount < 0)
    {
        printf("Expenditure cannot be negative.\n");
        return;
    }

    deptSpent[index] = deptSpent[index] + amount;
    printf("Expenditure recorded.\n");
}

void displayBudgets(void)
{
    int   i;
    float remaining;

    if (deptCount == 0)
    {
        printf("No budgets to display.\n");
        return;
    }

    printf("\n%-20s %12s %12s %12s  %s\n",
           "Department", "Allocated", "Spent", "Remaining", "Status");
    printf("--------------------------------------------------------------------\n");

    for (i = 0; i < deptCount; i++)
    {
        remaining = calculateRemaining(deptAllocated[i], deptSpent[i]);

        if (remaining >= 0)
        {
            printf("%-20s %12.2f %12.2f %12.2f  WITHIN BUDGET\n",
                   deptName[i], deptAllocated[i], deptSpent[i], remaining);
        }
        else
        {
            printf("%-20s %12.2f %12.2f %12.2f  OVER BUDGET\n",
                   deptName[i], deptAllocated[i], deptSpent[i], remaining);
        }
    }
}

void showOverBudgetDepartments(void)
{
    int   i;
    int   found = 0;
    float remaining;

    if (deptCount == 0)
    {
        printf("No departments yet.\n");
        return;
    }

    printf("\nOver-budget departments:\n");

    for (i = 0; i < deptCount; i++)
    {
        remaining = calculateRemaining(deptAllocated[i], deptSpent[i]);

        if (remaining < 0)
        {
            printf(" - %s (over by %.2f)\n", deptName[i], -remaining);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf(" None. All within budget.\n");
    }
}

int findDepartment(char name[])
{
    int i;

    for (i = 0; i < deptCount; i++)
    {
        if (strcmp(deptName[i], name) == 0)
        {
            return i;
        }
    }

    return -1;
}

float calculateRemaining(float allocated, float spent)
{
    return allocated - spent;
}


