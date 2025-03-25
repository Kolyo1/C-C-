#include <stdio.h>

void inputMatrix(int n, int matrix[n][n]) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("C[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int n, int matrix[n][n]) {
    printf("The entered matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintMainDiagonal(int n, int matrix[n][n]){
    printf("Main diagonal: ");
    for (int i = 0; i < n; i++){
        printf("%d", matrix[i][i]);
    }
    printf("\n");
}

void PrintSecondaryDiagonal(int n, int matrix[n][n]){
    printf("Secondary diagonal: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", matrix[i][n-i-1]);
    }
    printf("\n");
}

void PrintAboveDiagonal(int n, int matrix[n][n]){
    printf("Above main diagonal: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            printf("%d", matrix[i][j]);
        }
    }
    printf("\n");
}

void PrintBellowDiagonal(int n, int matrix[n][n]){
    printf("Bellow main diagonal: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d", matrix[i][j]);
        }
    }
    printf("\n");
}
void isMagicCube(int n, int matrix[n][n]){
    int magicSum = 0, sum;
    for(int j = 0; j < n; j++){
        magicSum += matrix[0][j];
    }

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += matrix[i][j];
        }
    }
    if (sum != magicSum)
    {
        printf("Not a magic cube");
        return;
    }

    for (int j = 0; j < n; j++)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += matrix[i][j];
        }
    }
    if (sum != magicSum)
        {
            printf("Not a magic cube");
            return;
        }

    sum = 0;
    for (int i = 0; i < n; i++){
        sum += matrix[i][i];
    }
    if (sum != magicSum)
        {
            printf("Not a magic cube");
            return;
        }

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][n-i-1];
    }
    if (sum != magicSum)
        {
            printf("Not a magic cube");
            return;
        }

    printf("Magic Cube");
}

int main(){
    int n;
    printf("Enter the number of rows and columns: ");
    scanf("%d",&n);
    int matrix[n][n];
    inputMatrix(n, matrix);
    printMatrix(n, matrix);
    PrintMainDiagonal(n, matrix);
    PrintSecondaryDiagonal(n,matrix);
    PrintAboveDiagonal(n,matrix);
    PrintBellowDiagonal(n,matrix);
    isMagicCube(n,matrix);

    return 0;
}