#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>


// Zad 1
void WritingToFile(const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        exit(1);
    }

    int n;
    scanf("%d", &n); 
    if (n < 0) {
        exit(2);
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (fwrite(&n, sizeof(int), 1, fp) != 1) {
        exit(3);
    }

    if (fwrite(arr, sizeof(int), n, fp) != n) {
        exit(4);
    }

    fclose(fp);
}

void Sort(int* arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void EvenOdd(int* even, int* odd, int* arr, int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] % 2 == 0) {
            (*even)++;
        } else {
            (*odd)++;
        }
    }
}

void WriteToTxt(const char* txt, int* arr, int length) {
    FILE* fp = fopen(txt, "w");
    if (fp == NULL) {
        exit(9);
    }

    for (int i = 0; i < length; i++) {
        if (fprintf(fp, "%d ", arr[i]) < 0) {
            exit(10);
        }
    }

    if (fclose(fp) != 0) {
        exit(11);
    }
}

void ReadFromFile(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        exit(5);
    }

    int length;
    if (fread(&length, sizeof(int), 1, fp) != 1) {
        exit(6);
    }

    int arr[length];
    if (fread(arr, sizeof(int), length, fp) != length) {
        exit(7);
    }

    if (fclose(fp) != 0) {
        exit(8);
    }

    Sort(arr, length);
    const char* txt = "test.txt";
    WriteToTxt(txt, arr, length);
    
    int even = 0;
    int odd = 0;
    EvenOdd(&even, &odd, arr, length);
    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);
}

// Zad 2
void WriteToFile2(const char* filename2){
    FILE* fp = fopen(filename2, "wb");
    if (fp == NULL) {
        exit(12);
    }
    int number, count;
    printf("Enter the number of elements: ");
    scanf("%d", &count);
    for(int i = 0; i < count; i ++){
        scanf("%d", &number);
        if (fwrite(&number, sizeof(int), 1, fp) != 1) {
            exit(13);
        }
    }
    if(fclose(fp) != 0){
        exit(14);
    }
}

void EvenOdd2(int* even2, int* odd2, int* arr, int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] % 2 == 0) {
            (*even2)++;
        } else {
            (*odd2)++;
        }
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void SortAndWriteTotxt(const char* filename2, const char* filename3) {
    FILE* fp1 = fopen(filename2, "rb");
    if (fp1 == NULL) {
        exit(15);
    }
    int* arr = NULL;
    int length = 0, capacity = 10, num;
    arr = malloc(capacity * sizeof(int));
    if (arr == NULL) {
        exit(16);
        if(fclose(fp1) != 0){
            exit(17);
        }
    }
    while (fread(&num, sizeof(int), 1, fp1) == 1) {
        if (length >= capacity) {
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                exit(18);
                if (fclose(fp1) != 0){
                    exit(19);
                }
            }
        }
        arr[length++] = num;
    }
    if (fclose(fp1) != 0) {
        exit(20);
    }
    qsort(arr, length, sizeof(int), compare);
    FILE* fp2 = fopen(filename3, "w");
    if (fp2 == NULL) {
        exit(21);
        free(arr);
    }
    for (int i = 0; i < length; i++) {
        if (fprintf(fp2, "%d ", arr[i]) < 0) {
            exit(22);
        }
    }

    if (fclose(fp2) != 0) {
        exit(23);
        free(arr);
    }

    int even2 = 0;
    int odd2 = 0;
    EvenOdd2(&even2, &odd2, arr, length);
    printf("Even: %d\n", even2);
    printf("Odd: %d\n", odd2);
}

// Zad 3
typedef struct{
    char brand[50];
    char model[6];
    double volume;
    double price;
    char registration;
}car;

void Fill(car* c1){
    fgets(c1->brand, sizeof(c1->brand), stdin);
    if(strlen(c1->brand) == sizeof(c1->brand) - 1){
        c1->brand[sizeof(c1->brand) - 1] = '\0';
    }
    fgets(c1->model, sizeof(c1->model), stdin);
    if(strlen(c1->model) == sizeof(c1->model) - 1){
        c1->model[sizeof(c1->model) - 1] = '\0';
    }
    scanf("%lf", &c1->volume);
    scanf("%lf", &c1->price);
    getchar();
    scanf(" %c", &c1->registration);
    char reg = tolower(c1->registration);
    if (reg != 'y' && reg != 'n') {
    exit(24);
    }
    
}

void PrintCar(car c1){
    printf("Brand: %s", c1.brand);
    printf("Model: %s", c1.model);
    printf("Volume: %.2lf\n", c1.volume);
    printf("Price: %.2lf\n", c1.price);
    printf("Registration: %c\n", c1.registration);
}

void Write(const char* filename4, car c1, const char* filename5) {
    FILE* fp1 = fopen(filename4, "ab");
    if (fp1 == NULL) {
        exit(25);
    }

    if (fwrite(&c1, sizeof(car), 1, fp1) != 1) {
        exit(26);
    }

    
    FILE* fp2 = fopen(filename5, "a");
    if (fp2 == NULL) {
        exit(27);
    }

    fprintf(fp2, "%s %s %lf %lf %c", c1.brand, c1.model, c1.volume, c1.price, c1.registration);
    if (fclose(fp1) != 0) {
        exit(28);
    }

    if (fclose(fp2) != 0) {
        exit(29);
    }
}

void ReadCompare(const char* filename4, const char* filename5) {
    FILE* fp1 = fopen(filename4, "rb");
    if (fp1 == NULL) exit(30);

    car c1;

    while (fread(&c1, sizeof(car), 1, fp1) == 1) {
        PrintCar(c1);
    }
    if (fclose(fp1) != 0) {
        exit(31);
    }

    FILE* fp2 = fopen(filename5, "r");
    if (fp2 == NULL) exit(32);

    while (fscanf(fp2, "%49s %5s %lf %lf %c", c1.brand, c1.model, &c1.volume, &c1.price, &c1.registration) == 5) {
        PrintCar(c1);
    }
    if (fclose(fp2) != 0) {
        exit(33);
    }
}

int main() {
    // Zad 1
    // const char* filename1 = "first.bin";
    // WritingToFile(filename1);
    // ReadFromFile(filename1);

    // Zad 2
    // const char*  filename2 = "second.bin";
    // const char* filename3 = "second.txt";
    // WriteToFile2(filename2);
    // SortAndWriteTotxt(filename2, filename3);
    // Zad 3
    const char* filename4 = "car.bin";
    const char* filename5 = "car.txt";
    car c1;
    Fill(&c1);
    PrintCar(c1);
    Write(filename4, c1, filename5);
    ReadCompare(filename4, filename5);
}
