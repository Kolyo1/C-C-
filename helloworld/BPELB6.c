#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Add(int **arr, int *size, int x, int y) {
    if (y >= *size) {
        int new_size = y + 1;
        int *temp = realloc(*arr, new_size * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        *arr = temp;
        
        for (int i = *size; i < new_size; i++) {
            (*arr)[i] = 0;
        }
        *size = new_size;
    } else {
        int new_size = size + 1;
        int *temp = realloc(*arr, new_size * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        *arr = temp;

        for (int i = *size; i > y; i--) {
            (*arr)[i] = (*arr)[i - 1];
        }
        *size = new_size;
    }
    (*arr)[y] = x;
}

void Delete(int **arr, int *size, int x, int y) {
    if (y >= *size || (*arr)[y] != x) {
        printf("Element not found.\n");
        return;
    }

    for (int i = y; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    *size -= 1;
    if (*size == 0) {
        free(*arr);
        *arr = NULL;
        return;
    }

    int *temp = realloc(*arr, (*size) * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    *arr = temp;
}

void Print(int *arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    char choice[20];
    int x, y;
    while (1) {
        printf("Enter choice: \n");
        scanf("%s", choice);
        if (strcmp(choice, "exit") == 0) {
            break;
        } else if (strcmp(choice, "add") == 0) {
            scanf("%d %d", &x, &y);
            Add(&arr, &size, x, y);
            Print(arr, size);
        } else if (strcmp(choice, "delete") == 0) {
            scanf("%d %d", &x, &y);
            Delete(&arr, &size, x, y);
            Print(arr, size);
        } else {
            printf("Invalid command. Please enter add(x,y), delete(x,y), or exit().\n");
        }
    }

    free(arr);
    return 0;
}