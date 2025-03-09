#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure
typedef struct {
    int partNumber;
    char partName[50];
    float partSize;
    char partSizeMetric[10];
    float partCost;
} Part;

// Global variables
Part *database = NULL; // Pointer to hold the database
int recordCount = 0;    // Number of records

// Function prototypes
void printAllRecords();
void printRecordCount();
void printDatabaseSize();
void addRecord();
void deleteRecord();
void freeMemory();

int main() {
    int choice;
    while (1) {
        // Display menu
        printf("\nMENU\n");
        printf("=======\n");
        printf("1. Print all records\n");
        printf("2. Print number of records\n");
        printf("3. Print size of database\n");
        printf("4. Add record\n");
        printf("5. Delete record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printAllRecords();
                break;
            case 2:
                printRecordCount();
                break;
            case 3:
                printDatabaseSize();
                break;
            case 4:
                addRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                freeMemory();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

// Function to print all records
void printAllRecords() {
    if (recordCount == 0) {
        printf("No records found.\n");
        return;
    }
    for (int i = 0; i < recordCount; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("Part Number: %d\n", database[i].partNumber);
        printf("Part Name: %s\n", database[i].partName);
        printf("Part Size: %.2f %s\n", database[i].partSize, database[i].partSizeMetric);
        printf("Part Cost: $%.2f\n", database[i].partCost);
    }
}

// Function to print the number of records
void printRecordCount() {
    printf("Total Records: %d\n", recordCount);
}

// Function to print the database size in bytes
void printDatabaseSize() {
    printf("Database Size: %ld bytes\n", recordCount * sizeof(Part));
}

// Function to add a new record
void addRecord() {
    // Allocate new memory manually (instead of using realloc)
    Part *newDatabase = (Part *)malloc((recordCount + 1) * sizeof(Part));
    if (!newDatabase) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Copy old records to new memory
    for (int i = 0; i < recordCount; i++) {
        newDatabase[i] = database[i];
    }
    
    // Free old memory
    free(database);
    
    // Point database to new memory
    database = newDatabase;
    
    // Get new record details
    printf("Enter Part Number: ");
    scanf("%d", &database[recordCount].partNumber);
    printf("Enter Part Name: ");
    scanf("%s", database[recordCount].partName);
    printf("Enter Part Size: ");
    scanf("%f", &database[recordCount].partSize);
    printf("Enter Part Size Metric: ");
    scanf("%s", database[recordCount].partSizeMetric);
    printf("Enter Part Cost: ");
    scanf("%f", &database[recordCount].partCost);

    recordCount++;
    printf("Record added successfully!\n");
}

// Function to delete the last record
void deleteRecord() {
    if (recordCount == 0) {
        printf("No records to delete.\n");
        return;
    }
    
    // Allocate new memory
    Part *newDatabase = (Part *)malloc((recordCount - 1) * sizeof(Part));
    if (!newDatabase && recordCount > 1) {
        printf("Memory reallocation failed!\n");
        return;
    }
    
    // Copy records except last one
    for (int i = 0; i < recordCount - 1; i++) {
        newDatabase[i] = database[i];
    }
    
    // Free old memory
    free(database);
    
    // Update database pointer
    database = newDatabase;
    recordCount--;
    printf("Last record deleted successfully!\n");
}

// Function to free allocated memory
void freeMemory() {
    if (database != NULL) {
        free(database);
        database = NULL;
    }
}
