#include <stdio.h>
#include<math.h>

void Switch(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    printf("After: %d %d\n", a, b);
}

void OddOrEven(int a){
    if(a%2 == 0){
        printf("Even\n");
    }
    else{
        printf("Odd\n");
    }
}

void DecimalToBinaryWithPointer(int a){
    if( a == 0){
        printf("0");
    }

    int binary[32];
    int i = 0;
    int *ptr = binary;
    while (a > 0)
    {
        *(ptr + i) = a % 2;
        a /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", *(ptr + j));
    }
    printf("\n");
    
}

void Square(double a){
    double areaK;
    areaK = a * a;
    printf("S: %.2lf\n", areaK);
}

void Rectangle(double a, double b){
    double areaP;
    areaP = a * b;
    printf("S: %.2lf\n", areaP);
}

void Triangle(double a, double b){
    double areaT;
    areaT = (a * b) / 2;
    printf("S: %.2lf\n", areaT);
}

void Circle(int r){
    double areaO;
    areaO = M_PI * r * r;
    printf("S: %.2lf\n", areaO);
}

int main(){
    // 1
    int figure;
    printf("Enter a figure: 1(квадрат) 2(правоъгълник) 3(правоъгълен триъгълник) 4(окръжност)");
    scanf("%d", &figure);
    switch (figure)
    {
        case 1: {
            double ak;
            printf("Enter side: ");
            scanf("%lf", &ak);
            Square(ak);
            break;
        }
        case 2: {
            double aP, bP;
            printf("Enter first side: ");
            scanf("%lf", &aP);
            printf("Enter second side: ");
            scanf("%lf", &bP);
            Rectangle(aP, bP);
            break;
        }
        case 3: {
            double aT, bT;
            printf("Enter first side: ");
            scanf("%lf", &aT);
            printf("Enter second side: ");
            scanf("%lf", &bT);
            Triangle(aT, bT);
            break;
        }
        case 4: {
            double rO, areaO;
            printf("Enter radius: ");
            scanf("%lf", &rO);
            Circle(rO);
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }
   // 2
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("\n");
    printf("Before: %d %d\n", a, b);
    Switch(a, b);

    // 3
    int a; 
    scanf("%d", &a);
    OddOrEven(a);

    // 4
    int a;
    scanf("%d", &a);
    DecimalToBinaryWithPointer(a);
    

    //5 
    int p;
    scanf("%d", &p);
    int *pt;
    pt = &p;
    printf("Address: %p\n", pt);
    printf("Value: %d\n", *pt);

    // 6
    double a;
    scanf("%lf", &a);
    double *pta;
    double b;
    scanf("%lf", &b);
    double *ptb;
    pta = &a;
    ptb = &b;
    printf("Sum: %.2lf\n", *pta + *ptb);
    printf("Difference: %.2lf\n", *pta - *ptb);
    printf("Product: %.2lf\n", *pta * *ptb);
    printf("Quotient: %.2lf\n", *pta / *ptb);
   return 0;
}