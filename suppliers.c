#include <stdio.h>
#include <string.h>
#include "suppliers.h"

// Add a new supplier
void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_SUPPLIERS) {
        printf("\nError: Supplier database is full!\n");
        return;
    }

    Supplier newSupplier;
    printf("\n--- Add New Supplier ---\n");

    // ID
    printf("Enter Supplier ID: ");
    scanf("%s", newSupplier.supplierID);

    // Name
    printf("Enter Supplier Name: ");
    getchar(); 
    fgets(newSupplier.supplierName, STR_LEN, stdin);
    newSupplier.supplierName[strcspn(newSupplier.supplierName, "\n")] = '\0';

    if (strlen(newSupplier.supplierName) == 0) {
        printf("Error: Supplier Name cannot be empty.\n");
        return;
    }

    // Email
    printf("Enter Email Address: ");
    scanf("%s", newSupplier.email);

    // Telephone
    printf("Enter Telephone Number: ");
    scanf("%s", newSupplier.telephone);

    // Location
    printf("Enter Town/Location: ");
    getchar();
    fgets(newSupplier.location, STR_LEN, stdin);
    newSupplier.location[strcspn(newSupplier.location, "\n")] = '\0';

    // Save
    suppliers[*count] = newSupplier;
    (*count)++;
    printf("Supplier added!\n");
}

// Show all suppliers
void displaySuppliers(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n=================================================================================\n");
    printf("%-12s | %-20s | %-20s | %-12s | %-15s\n", 
           "Supplier ID", "Name", "Email", "Telephone", "Location");
    printf("=================================================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%-12s | %-20s | %-20s | %-12s | %-15s\n", 
               suppliers[i].supplierID, suppliers[i].supplierName, 
               suppliers[i].email, suppliers[i].telephone, suppliers[i].location);
    }
}

// Search supplier by ID or Name
void searchSupplier(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers to search.\n");
        return;
    }

    char searchTerm[STR_LEN];
    printf("\nEnter Supplier ID or Name: ");
    getchar();
    fgets(searchTerm, STR_LEN, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    int found = 0;
    printf("\n--- Search Results ---\n");

    for (int i = 0; i < count; i++) {
        if (strcmp(suppliers[i].supplierID, searchTerm) == 0 || 
            strstr(suppliers[i].supplierName, searchTerm) != NULL) {
            
            printf("\nSupplier ID: %s\n", suppliers[i].supplierID);
            printf("Name: %s\n", suppliers[i].supplierName);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Location: %s\n", suppliers[i].location);
            printf("-----------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No supplier found for '%s'.\n", searchTerm);
    }
}

// Supplier menu
void supplierMenu(Supplier suppliers[], int *count) {
    int choice;
    do {
        printf("\n--- SUPPLIER MENU ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Return to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Numbers only.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: addSupplier(suppliers, count); break;
            case 2: displaySuppliers(suppliers, *count); break;
            case 3: searchSupplier(suppliers, *count); break;
            case 4: printf("Returning...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

