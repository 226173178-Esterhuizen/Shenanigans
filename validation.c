#include <stdio.h>
#include <string.h>
#include "validation.h"

float getValidFloat(const char* prompt) {
    float value;
    int itemsRead;
    do {
        printf("%s", prompt);
        itemsRead = scanf("%f", &value);
        
        while (getchar() != '\n'); 

        if (itemsRead != 1 || value < 0) {
            printf("Error: Invalid entry. Please enter a positive number.\n");
        }
    } while (itemsRead != 1 || value < 0);
    return value;
}

int getValidInt(const char* prompt) {
    int value;
    int itemsRead;
    do {
        printf("%s", prompt);
        itemsRead = scanf("%d", &value);
        while (getchar() != '\n'); 

        if (itemsRead != 1 || value < 0) {
            printf("Error: Invalid entry. Please enter a valid positive whole number.\n");
        }
    } while (itemsRead != 1 || value < 0);
    return value;
}

void getValidString(const char* prompt, char* output, int maxLength) {
    do {
        printf("%s", prompt);
        fgets(output, maxLength, stdin);
        
        output[strcspn(output, "\n")] = '\0';

        if (strlen(output) == 0) {
            printf("Error: Field cannot be empty. Please try again.\n");
        }
    } while (strlen(output) == 0);
}