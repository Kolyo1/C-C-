// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #include <math.h>

// typedef struct {
//     char ownerName[30];
//     char code[10]; // A12345B
//     double price;
// }Animals;


// Animals WriteToTxt(){
//     Animals animal;
//     FILE* fp = fopen("animals.txt", "w");
//     if(fp == NULL){
//         printf("Error opening file.\n");
//         return animal;
//     }
//     printf("Enter owner name: ");
//     scanf("%s", animal.ownerName);
//     printf("Enter code: ");
//     scanf("%s", animal.code);
//     printf("Enter price: ");
//     scanf("%lf", &animal.price);
    
//     fprintf(fp, "%s %s %.2f\n", animal.ownerName, animal.code, animal.price);
//     fclose(fp);
    
//     return animal;
// }

// void FindByPrice(Animals animal[], int n, double price){

//     int found = 0;
//     double epsilon = 0.01;
//     for(int i = 0; i < n; i++){
//         if(animal[i].price == price){
//             printf("Owner Name: %s - Code: %s\n", animal[i].ownerName, animal[i].code);
//             found = 1;
//         }
//     }
//     if(!found){
//         printf("No animals");
//     }
// }
// int main(){
//     Animals animal[100];
//     int n;
//     animal[n++] = WriteToTxt();
    
//     double price;
//     printf("Enter the price to search: ");
//     scanf("%lf", &price);
//     FindByPrice(animal, n, price);


//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define CHIP_LENGTH 10
#define MAX_PETS 100

typedef struct {
    char ownerName[MAX_NAME_LENGTH];
    char chipNumber[CHIP_LENGTH]; // Format: A12345B
    double price;
} Pet;

// Function to create a pet and write to a text file
Pet createPet() {
    Pet pet;
    FILE *fp = fopen("animalsText.txt", "a"); // Open in append mode
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter owner's name: ");
    fgets(pet.ownerName, sizeof(pet.ownerName), stdin);
    pet.ownerName[strcspn(pet.ownerName, "\n")] = 0; // Remove newline

    printf("Enter chip number (format A12345B): ");
    fgets(pet.chipNumber, sizeof(pet.chipNumber), stdin);
    pet.chipNumber[strcspn(pet.chipNumber, "\n")] = 0; // Remove newline

    printf("Enter price for examination: ");
    scanf("%lf", &pet.price);
    getchar(); // Consume newline

    // Write to text file
    fprintf(fp, "%s,%.2f\n", pet.ownerName, pet.price);
    fclose(fp);

    return pet;
}

// Function to find pets by price
void findPetsByPrice(Pet pets[], int size, double price) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (pets[i].price == price) {
            printf("%s - %s\n", pets[i].ownerName, pets[i].chipNumber);
            found = 1;
        }
    }
    if (!found) {
        printf("No pets found with the given price.\n");
    }
}

// Function to read from a binary file and print pets with price >= given price
void printPetsFromBin(double minPrice) {
    FILE *fp = fopen("animals.bin", "rb");
    if (fp == NULL) {
        printf("Error opening binary file.\n");
        return;
    }

    while (!feof(fp)) {
        int nameLength;
        if (fread(&nameLength, sizeof(int), 1, fp) != 1) break; // Read length of owner name

        Pet pet;
        fread(pet.ownerName, sizeof(char), nameLength, fp); // Read owner name
        pet.ownerName[nameLength] = '\0'; // Null-terminate the string
        fread(pet.chipNumber, sizeof(char), CHIP_LENGTH, fp); // Read chip number
        fread(&pet.price, sizeof(double), 1, fp); // Read price

        if (pet.price >= minPrice) {
            printf("Bin OwnerName: %s\n", pet.ownerName);
            printf("Bin Chip: %s\n", pet.chipNumber);
            printf("Bin Price: %.2f\n", pet.price);
            printf("----------\n");
        }
    }

    fclose(fp);
}

int main() {
    Pet pets[MAX_PETS];
    int petCount = 0;

    // Task 1: Create a pet and write to text file
    pets[petCount++] = createPet();

    // Task 2: Find pets by price
    double searchPrice;
    printf("Enter price to search for: ");
    scanf("%lf", &searchPrice);
    findPetsByPrice(pets, petCount, searchPrice);

    // Task 3: Print pets from binary file
    double minPrice;
    printf("Enter minimum price to filter pets from binary file: ");
    scanf("%lf", &minPrice);
    printPetsFromBin(minPrice);

    return 0;
}
