#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Write(const char* filename, int* arr, int length) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        exit(5);
    }
    if (fwrite(&length, sizeof(int), 1, fp) != 1) {
        exit(6);
    }
    if (fwrite(arr, sizeof(int), length, fp) != length) {
        exit(6);
    }

    fclose(fp);
}

int main(){
    FILE *fp;
    char str[100];
    char *filename = "tet.txt";
    char *mode = "r";
    fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fscanf(fp, "%s", str);
    printf("First line: %s\n", str);

    while (fgets(str, sizeof(str), fp) != NULL) {
        printf("%s", str);
    }
    
    fclose(fp);
    
    return 0;
}