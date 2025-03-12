#include <stdio.h>

int main(){
    //Zad 1
    int a, b;
    int max = 0;
    int min = 0;
    while(1){
        scanf("%d %d", &a, &b);
        if(a == 0 || b == 0){
            break;
        }
        if(a > b){
            max = a;
            min = b;
        }
        else{
            max = b;
            min = a;
        }
    }
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    //Zad 2
    int hours, minutes;
    scanf("%d %d", &hours, &minutes);
    if(minutes + 15 >= 60){
        hours++;
        minutes = (minutes + 15) - 60;
    }
    else{
        minutes += 15;
    }
    if(hours > 23){
        hours = 0;
    }
    printf("%02d:%02d\n", hours, minutes);

    //Zad 3
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == b && b == c){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }

    //Zad 4
    int points;
    scanf("%d", &points);
    double bonus = 0;
    if(points <= 100){
        bonus = 5;
    }
    else if(points > 100 && points <= 1000){
        bonus = points * 0.2;
    }
    else if(points > 1000){
        bonus = points * 0.1;
    }
    if(points % 2 == 0){
        bonus += 1;
    }
    if(points % 10 == 5){
        bonus += 2;
    }
    printf("Bonus: %.2lf\n", bonus);
    printf("Total points: %.2lf\n", points + bonus);

    //Zad 5
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int total = a + b + c;
    int minutes = total / 60;
    int seconds = total % 60;
    printf("%d:%02d\n", minutes, seconds);

    //Zad 6
    double x1, y1, x2, y2, x, y;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x, &y);
    if(x >= x1 && x <= x2 && y >= y1 && y <= y2){
        printf("Inside\n");
    }
    else{
        printf("Outside\n");
    }

    //Zad 7
    double km;
    char period;
    scanf("%lf %c", &km, &period);
    double taxi_rate;
    if (period == 'D') {
        taxi_rate = 0.79;
    } else {
        taxi_rate = 0.90;
    }
    double taxi = 0.70 + (taxi_rate * km);
    if (km >= 100) {
        printf("Train: %.2lf\n", 0.06 * km);
    } else if (km >= 20) {
        double bus = 0.09 * km;
        if (taxi < bus) {
            printf("Taxi: %.2lf\n", taxi);
        } else {
            printf("Bus: %.2lf\n", bus);
        }
    } else {
        printf("Taxi: %.2lf\n", taxi);
    }

    //Zad 8
    double V, p1, p2, h;
    scanf("%lf %lf %lf %lf", &V, &p1, &p2, &h);
    V *= 1000;
    double total = (p1 * h) + (p2 * h);
    if(total <= V){
        printf("The pool is %.2lf full\n", (total / V) * 100);
        printf("Pipe 1: %.2lf\n", (p1 * h) / total * 100);
        printf("Pipe 2: %.2lf\n", (p2 * h) / total * 100);
    }
    else{
        printf("The pool overflows with %.2lf liters\n", total - V);
    }

    //Zad 9
    double X, Y, Z;
    int workers;
    scanf("%lf %lf %lf %d", &X, &Y, &Z, &workers);
    double total = X * 0.4 * Y;
    double wine = total / 2.5;
    if(total >= Z * 2.5){
        double leftovers = total - Z;
        printf("Good harvest this year! Total wine: %.2lf liters\n", total / 2.5);
        printf("Leftover wine: %.2lf liters\n", total - (Z * 2.5));
        printf("Each worker gets: %.2lf liters\n", leftovers / workers);
    }
    else{
        printf("It will be a tough year! Total wine: %.2lf liters\n", total / 2.5);
        printf("Needed wine: %.2lf liters\n", (Z * 2.5) - total);
    }

    //Zad 10
    int n;
    scanf("%d", &n);
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0;
    int p5 = 0;
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        if(num < 200){
            p1++;
        }
        else if(num >= 200 && num < 400){
            p2++;
        }
        else if(num >= 400 && num < 600){
            p3++;
        }
        else if(num >= 600 && num < 800){
            p4++;
        }
        else{
            p5++;
        }
    }
    printf("%.2lf%%\n", (p1 / (double)n) * 100);
    printf("%.2lf%%\n", (p2 / (double)n) * 100);
    printf("%.2lf%%\n", (p3 / (double)n) * 100);
    printf("%.2lf%%\n", (p4 / (double)n) * 100);
    printf("%.2lf%%\n", (p5 / (double)n) * 100);

    //Zad 11
    int n;
    scanf("%d", &n);
    int width = 2 * n;
    int leftRight = n / 2;
    int middle = width - (2 * leftRight) - 4;
    printf("+");
    for (int j = 0; j < leftRight; j++) {
        printf("/");
    }
    printf("**");
    for (int j = 0; j < leftRight; j++) {
        printf("\\");
    }
    printf("+\n");
    for (int i = 0; i < n - 2; i++) {
        printf("|");
        for (int j = 0; j < width - 2; j++) {
            printf(" ");
        }
        printf("|\n");
    }
    printf("+");
    for (int j = 0; j < leftRight; j++) {
        printf("\\");
    }
    printf("**");
    for (int j = 0; j < leftRight; j++) {
        printf("/");
    }
    printf("+\n");


    //Zad 12
    int n;
    scanf("%d", &n);
    int width = 2 * n - 1;
    int leftRight = n - 1;
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            printf("*");
        } else {
            printf("-");
        }

        for (int j = 0; j < leftRight - 1; j++) {
            printf(" ");
        }

        if (i % 2 == 0) {
            printf("*");
        } else {
            printf("-");
        }

        printf(" ");

        if (i % 2 == 0) {
            printf("*");
        } else {
            printf("-");
        }

        for (int j = 0; j < leftRight - 1; j++) {
            printf(" ");
        }

        if (i % 2 == 0) {
            printf("*");
        } else {
            printf("-");
        }

        printf("\n");
    }
    for (int i = 0; i < n - 1; i++) {
        printf(" ");
    }
    printf("@\n");
    for (int i = n - 2; i >= 0; i--) {
        if (i % 2 == 0) {
            printf("*");
        } else {
            printf("-");
        }

        for (int j = 0; j < leftRight - 1; j++) {
            printf(" ");
        }

        if (i % 2 == 0) {
            printf("*");
        } else {
            printf("-");
        }
    }
    return 0;
}