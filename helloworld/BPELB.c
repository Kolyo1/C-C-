#include <stdio.h>

int main(){
    printf("Good morning! \n");
    printf("Good afternoon! \n");
    printf("Good night! \n");    
    int a;
    scanf("%d", &a);
    printf("\nA: %d\n", a);

    // ZAD 1
    int b;
    scanf("%d", &a);
    if (a > 6){printf("Greater than 6");}
    else{printf("Lower than 6");}

    // ZAD 2
    int c;
    scanf("%d", &c);
    if(c%8 > 4){printf("Greater than 4");}

    // ZAD 3
     int a; int b; int c;
     scanf("%d", &a);
     scanf("%d",&b);
     scanf("%d",&c);
    if(a < b && a < c){
        printf("A: %d", a);
    }     
    else if (b < a & b < c){
        printf("B: %d", b);
    }
    else{
        printf("C: %d", c);
    }

    // ZAD 4
    int d;
    scanf("%d", &d);
    switch (d)
    {
    case 1 :
        printf("one\n");
        break;
    case 2:
        printf("two\n");
        break;
    case 3:
        printf("three\n");
        break;
    default:
        break;
    }

    // ZAD 5
    int a;
    scanf("%d", &a);
    if(a >= 1 && a <= 7){
        switch (a)
        {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;    
        default:
            break;
        }
    }
    else{
        printf("No day in the week like this. From 1 to 7.");
    }


    // ZAD 6
    int a;
    scanf("%d", &a);
    for(int i = 0; i < a; i++){
        for (int k = 1; k <=i; k++)
        {
            printf("%d", i);
        }
        printf("\n");
    }

    // ZAD 7
    int a; int b; int sum = 0; int result;
    scanf("%d", &a);
    scanf("%d", &b);
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    for(int i = a+1; i < b; i++){
        sum += i;
    }
    result = sum;
    printf("\n");
    printf("%d", result);

    // ZAD 8
    int a; int b; int sumeven = 0; int proizvodd = 1; int ressum; int resproizv;
    scanf("%d %d", &a, &b);
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    for(int i = a; i <=b; i++){
        if(i%2 == 0){
            sumeven += i;
        }
        else if(i%2 != 0){
          proizvodd *= i;
        }
    }
    ressum = sumeven;
    resproizv = proizvodd;
    printf("\n");
    printf("Sum even: %d\n", ressum);
    printf("Proizv odd : %d", resproizv);

    // ZAD 9
    int n; int k; int count = 0; int num;
    scanf ("%d %d", &n, &k);
    for(int i = 0; i <n; i++){
        scanf("%d", &num);
        if(num > k && num%3 == 0){
            count++;
        }
    }    
    printf("Брой числа, които са по-големи от %d и се делят на 3: %d\n", K, count);

    // ZAD 10
    int n; int sum = 0;
    while(1){
        scanf("%d", &n);
        if(n == 0){
         break;
        }
        sum += n;
    }
    int result = sum;
    printf("Sum of number: %d", result);

    // ZAD 11
    double a, b, step, x, fx;
    step = 0.01;
    scanf("%lf", &a);
    scanf("%lf", &b);
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    printf("Стойности на f(x) = x*x - 4 за x в интервала [%.2lf, %.2lf]:\n", a, b);
    for(x = a; x < b +0.01; x += step){
        fx = x * x - 4;
        printf("f(%.2lf) = %.4lf\n",x,fx);
    }
    return 0;
} 