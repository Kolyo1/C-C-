#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void Sort(int n, int m, int arr[n][m]){
    bool rows_sorted = true;
    for(int i = 0; i < n && rows_sorted;i++){
            for (int j = 0; j < m - 1; j++) {
                if (arr[i][j] > arr[i][j + 1]) {
                    rows_sorted = false;
                    break;
                }
            }
    }
    bool columns_sorted = true;
    for(int j = 0; j < m && columns_sorted; j++){
            for (int i = 0; i < n - 1; i++) {
                if (arr[i][j] < arr[i + 1][j]) {
                    columns_sorted = false;
                    break;
                }
            }
    }
    
    if(rows_sorted){
        printf("Rows are in ascending order\n");
    }
    else{
        printf("Rows are not in ascending order\n");
    }
    if(columns_sorted){
        printf("Columns are in descending order\n");
    }
    else{
        printf("Columns are not in descending order\n");
    }
}

int Sum(int n, int m, int arr[n][m], int i, int j){
    int sum = 0;
    for(int di = -1; di <= 1; di++){
        for(int dj = -1; dj <= 1; dj++){
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !(di == 0 && dj == 0)) {
                sum += arr[ni][nj];
            }
        }
    }
    return sum;
}

void Switch(int n, int m, int arr[n][m]){
    for(int j = 0; j <m; j++){
           int temp = arr[0][j];
           arr[0][j] = arr[n-1][j];
            arr[n-1][j] = temp;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void Friedship(int m, int count[]){
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        count[a]++;
        count[b]++;
    }
    
}

int Persons(int count[], int x){
    return count[x];
}

#define OFFSET 100000
#define MAX 200001

int freq[MAX] = {0};
int total = 0;

void add(int x){
    freq[x + OFFSET]++;
    total++;
}

void delete(int x){
    total -= freq[x + OFFSET];
    freq[x + OFFSET] = 0;
}

void smallest(int k) {
    if (k > total) {
        printf("Not enough elements\n");
        return;
    }

    int count = 0;
    for (int i = 0; i < MAX; i++) {
        count += freq[i];
        if (count >= k) {
            printf("%d\n", i - OFFSET);
            return;
        }
    }
}

bool Prime(int num){
    if(num < 2) return false;
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int main(){
    // Zad 1
    int n1, m1;
    scanf("%d %d", &n1, &m1);
    int arr1[n1][m1];
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    Sort(n1, m1, arr1);

    // Zad 2
    int n2, m2;
    scanf("%d %d", &n2, &m2);
    int arr2[n2][m2];
    for(int i = 0; i < n2; i++){
        for(int j = 0; j < m2; j++){
            scanf("%d", &arr2[i][j]);
        }
    }
    int i, j;
    int maxSum = -1;
    int maxRow = -1, maxCol = -1;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            int sum = Sum(n2,m2,arr,i,j);
            if (sum > maxSum)
            {
                maxSum = sum;
                maxRow = i;
                maxCol = j;
            }
        }
    }
    printf("Number: %d\n", arr[maxRow][maxCol]);
    printf("Position: (%d, %d)\n", maxRow, maxCol);

    // Zad 3
    int n3, m3;
    scanf("%d %d", &n3, &m3);
    int arr3[n3][m3];
    for(int i = 0; i < n3; i++){
        for(int j = 0; j < m3; j++){
            scanf("%d", &arr3[i][j]);
        }
    }
    Switch(n3, m3, arr3);

    // Zad 4
    int m4;
    scanf("%d", &m4);
    int count[100001] = {0};
    Friedship(m4, count);
    int x4;
    scanf("%d", &x4);
    int res = Persons(count, x4);
    printf("%d\n", res);
    
    // Zad 5
    int x5;
    char comm[20];
    while (strcmp(comm, "exit") != 0)
    {
        scanf("%s", comm);
        if (strcmp(comm, "add") == 0)
        {
            scanf("%d", &x5);
            add(x5);
        }
        else if (strcmp(comm, "delete") == 0)
        {
            scanf("%d", &x5);
            delete(x5);
        }
        else if (strcmp(comm, "smallest") == 0){
            int k;
            scanf("%d", &k);
            smallest(k);
        }
    } 

    // Zad 6
    int n6;
    scanf("%d", &n6);
    int* arr = (int*)malloc(n6 * sizeof(int));  
    int* prime = (int*)malloc(n6 * sizeof(int));  
    int* notPrime = (int*)malloc(n6 * sizeof(int));    

    if(!arr || !prime || !notPrime){
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n6; i++) {
        scanf("%d", &arr[i]);
    }

    int primeC = 0, notPrimeC = 0;
    for (size_t i = 0; i < n6; i++)
    {
        if(Prime(arr[i])){
            prime[primeC] = arr[i];
            primeC++;
        }
        else{
            notPrime[notPrimeC] = arr[i];
            notPrimeC++;
        }
    }
    
    printf("Prime numbers:\n");
    for (size_t i = 0; i < primeC; i++)
    {
        printf("%d ", prime[i]);
    }
    printf("\n");
    printf("Not prime numbers:\n");
    for (size_t i = 0; i < notPrimeC; i++)
    {
        printf("%d ", notPrime[i]);
    }
    printf("\n");

    free(arr);
    free(prime);
    free(notPrime);

    // Zad 7
    int n7, m7;
    scanf("%d %d", &n7, &m7);
    if (n7 < 3 || m7 < 3) {
        printf("Matrix size is too small\n");
        return 1;
    }
    int arr7[n7][m7];
    for(int i = 0; i < n7; i++){
        for(int j = 0; j < m7; j++){
            scanf("%d", &arr7[i][j]);
        }
    }
    int maxSum = -1;
    int maxRow = 0, maxCol = 0;
    for (int i = 0; i <= n7-3; i++)
    {
        for (int j = 0; j <= m7-3; j++)
        {
            int sum = 0;
            for (int di = 0; di <3; di++)
            {
                for (int dj = 0; dj < 3; dj++)
                {
                    sum = arr7[i+di][j+dj];
                }
                
            }
            if (sum>maxSum)
            {
                maxSum = sum;
                maxRow = i;
                maxCol = j;
            }
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr7[maxRow+i][maxCol+j]);
        }
        printf("\n");
    }
    
    // Zad 8
    int* arr8 = (int*)malloc(10 * sizeof(int));
    if (arr8 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int n8 = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr8[i]);
        n8++;
    }

    while (1) {
        int x, pos;
        scanf("%d", &x);  
        if (x == 0) { 
            break;
        }
        scanf("%d", &pos);  
        if (n8 >= 10) {
            arr8 = realloc(arr8, (n8 + 1) * sizeof(int));
            if (arr8 == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
        }
        for (int i = n8; i > pos; i--) {
            arr8[i] = arr8[i - 1];
        }
        arr8[pos] = x;
        n8++;  
    }
    for (int i = 0; i < n8; i++) {
        printf("%d ", arr8[i]);
    }
    free(arr8);
}