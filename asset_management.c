#include <stdio.h>
#include <string.h>

struct Asset {
    int id;
    char name[50];
    char type[30];
    float value;
    char department[50];
    char condition[30];
};

int main() {
    struct Asset registry[100];
    int assetCount = 0;
    int choice;
    int searchID;
    int found;
do {
        printf("\n================ ASSET REGISTER ================\n");
        printf("1. Add New Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {

            case 1:
                printf("\n--- ADD NEW ASSET ---\n");

                printf("Enter Asset ID: ");
                scanf("%d", &registry[assetCount].id);
                getchar();

                printf("Enter Asset Name: ");
                fgets(registry[assetCount].name, 50, stdin);
                registry[assetCount].name[strcspn(registry[assetCount].name, "\n")] = 0;

                printf("Enter Asset Type: ");
                fgets(registry[assetCount].type, 30, stdin);
                registry[assetCount].type[strcspn(registry[assetCount].type, "\n")] = 0;

                printf("Enter Purchase Value: ");
                scanf("%f", &registry[assetCount].value);
                getchar();

                printf("Enter Department: ");
                fgets(registry[assetCount].department, 50, stdin);
                registry[assetCount].department[strcspn(registry[assetCount].department, "\n")] = 0;

                printf("Enter Condition: ");
                fgets(registry[assetCount].condition, 30, stdin);
                registry[assetCount].condition[strcspn(registry[assetCount].condition, "\n")] = 0;

                assetCount++;

                printf("Asset added successfully!\n");
                break;

            case 2:
                printf("\n--- DISPLAY ASSETS ---\n");

                if (assetCount == 0) {
                    printf("No assets recorded yet.\n");
                } else {
                    for (int i = 0; i < assetCount; i++) {
                        printf("\nAsset ID: %d\n", registry[i].id);
                        printf("Asset Name: %s\n", registry[i].name);
                        printf("Asset Type: %s\n", registry[i].type);
                        printf("Purchase Value: %.2f\n", registry[i].value);
                        printf("Department: %s\n", registry[i].department);
                        printf("Condition: %s\n", registry[i].condition);
                    }
                }
                break;

            case 3:
                printf("\n--- SEARCH ASSET ---\n");
                printf("Enter Asset ID: ");
                scanf("%d", &searchID);

                found = 0;

                for (int i = 0; i < assetCount; i++) {
                    if (registry[i].id == searchID) {
                        printf("\nAsset ID: %d\n", registry[i].id);
                        printf("Asset Name: %s\n", registry[i].name);
                        printf("Asset Type: %s\n", registry[i].type);
                        printf("Purchase Value: %.2f\n", registry[i].value);
                        printf("Department: %s\n", registry[i].department);
                        printf("Condition: %s\n", registry[i].condition);
                        found = 1;
                    }
                }

                if (found == 0) {
                    printf("Asset not found.\n");
                }
                break;

            case 4:
                printf("Exiting system.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}