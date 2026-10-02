#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50
#define STR_LEN 100

// Structure to store supplier details
typedef struct {
    char supplierID[STR_LEN];
    char supplierName[STR_LEN];
    char email[STR_LEN];
    char telephone[STR_LEN];
    char location[STR_LEN];
} Supplier;

// Function declarations
void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);
void supplierMenu(Supplier suppliers[], int *count);

#endif
