#ifndef REPORTS_H
#define REPORTS_H
#include "employees.h"
#include "suppliers.h"

#define MAX_NAME 50
#define MAX_EMAIL 50
#define MAX_PHONE 20
#define MAX_LOCATION 50
#define MAX_TYPE 30
#define MAX_CONDITION 20

typedef struct {
    char name[MAX_NAME];
    double allocatedBudget;
    double expenditure;
} Budget;
typedef struct {
    int id;
    char name[MAX_NAME];
    char type[MAX_TYPE];
    double purchaseValue;
    char department[MAX_NAME];
    char condition[MAX_CONDITION];
} Asset;

/* Function Declarations */
void generateEmployeeReport(const Employee employees[], int count);
void generateBudgetReport(const Budget budgets[], int count);
void generateSupplierReport(const Supplier suppliers[], int count);
void generateAssetReport(const Asset assets[], int count);
void displayReportsMenu(const Employee employees[], int empCount,
                        const Budget budgets[], int budgetCount,
                        const Supplier suppliers[], int suppCount,
                        const Asset assets[], int assetCount);

#endif /* REPORTS_H */