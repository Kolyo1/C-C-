#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void add(int **arr, int *size, int n){
    if(*size <= n){
        int new_size = n + 1;
        int *temp = realloc(*arr, new_size * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        *arr = temp;
        for (int i = *size; i < new_size; i++) {
            (*arr)[i] = 0;
        }
        *size = new_size;
    } else {
        int new_size = n + 1;
        int *temp = realloc(*arr, new_size * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        *arr = temp;
        for (int i = *size; i < n; i--) {
            (*arr)[i] = (*arr)[i - 1];
        }
    }
    (*arr)[n] = n;
}

void print(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(){
    int n;
    int size;
    scanf("%d", &size);
    int *arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &n);
    add(&arr, &size,n);
    printf("\n");
    print(arr, size);

    free(arr);
}