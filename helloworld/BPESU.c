#include <stdio.h>
#include <math.h>

int main(){
    //1
    //printf("one, two, three, four, five, six, seven, eight, nine, ten");
    
    //2
    //printf("*\n**\n***\n****\n*****\n******\n*******\n********\n*********\n**********\n");

    //3
    // char symbol;
    // printf("Enter a symbol for the frame: ");
    // scanf(" %c", &symbol);
    // printf("%c%c%c%c%c%c%c%c%c%c\n", symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol);
    // printf("%c        %c\n", symbol, symbol);
    // printf("%c        %c\n", symbol, symbol);
    // printf("%c        %c\n", symbol, symbol);
    // printf("%c%c%c%c%c%c%c%c%c%c\n", symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol);

    //4
    // char symbol;
    // printf("Enter a symbol for the frame: ");
    // scanf(" %c", &symbol);
    // printf("%c%c%c%c%c%c%c%c%c%c\n", symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol);
    // printf("%c        %c\n", symbol, symbol);
    // printf("%c        %c\n", symbol, symbol);
    // printf("%c        %c\n", symbol, symbol);
    // printf("%c%c%c%c%c%c%c%c%c%c\n", symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol);

    //5
    // double inches;
    // printf("Enter length in inches: ");
    // scanf("%lf", &inches);
    // double mm = inches * 25.4;
    // double cm = inches * 2.54;
    // double dm = cm / 10;
    // double m = cm / 100;
    // printf("%.2lf inches is equal to:\n", inches);
    // printf("%.2lf mm\n", mm);
    // printf("%.2lf cm\n", cm);
    // printf("%.2lf dm\n", dm);
    // printf("%.2lf m\n", m); 

    //6
    // double celsius, fahrenheit;
    // printf("Enter temperature in Celsius: ");
    // scanf("%lf", &celsius);
    // fahrenheit = (celsius * 9 / 5) + 32;
    // printf("Temperature in Fahrenheit: %.2lf\n", fahrenheit);

    //7
    // double degrees, radians;
    // printf("Enter angle in degrees: ");
    // scanf("%lf", &degrees);
    // radians = degrees * (M_PI / 180.0);
    // printf("Angle in radians: %.6lf\n", radians);

    //8
    // double pounds, dollars, euros;
    // double pound_to_dollar = 1.25;
    // double pound_to_euro = 1.16;
    // printf("Enter amount in British pounds: ");
    // scanf("%lf", &pounds);
    // dollars = pounds * pound_to_dollar;
    // euros = pounds * pound_to_euro;
    // printf("%.2lf pounds is equivalent to:\n", pounds);
    // printf("%.2lf dollars\n", dollars);
    // printf("%.2lf euros\n", euros);

    //9
    // double a, b, h, area;
    // printf("Enter first side: ");
    // scanf("%lf", &a);
    // printf("Enter second side: ");
    // scanf("%lf", &b);
    // printf("Enter height: ");
    // scanf("%lf", &h);
    // area = ((a + b) * h) / 2;
    // printf("S: %.2lf\n", area);

    //10
    // double degrees, radians, sin_value, cos_value, tan_value, cot_value;
    // printf("Въведете ъгъл в градуси: ");
    // scanf("%lf", &degrees);
    // radians = degrees * (M_PI / 180.0);
    // sin_value = sin(radians);
    // cos_value = cos(radians);
    // tan_value = tan(radians);
    // if (tan_value != 0) {
    //     cot_value = 1 / tan_value;
    //     printf("sin(%.2lf) = %.6lf\n", degrees, sin_value);
    //     printf("cos(%.2lf) = %.6lf\n", degrees, cos_value);
    //     printf("tan(%.2lf) = %.6lf\n", degrees, tan_value);
    //     printf("cot(%.2lf) = %.6lf\n", degrees, cot_value);
    // } else {
    //     printf("sin(%.2lf) = %.6lf\n", degrees, sin_value);
    //     printf("cos(%.2lf) = %.6lf\n", degrees, cos_value);
    //     printf("tan(%.2lf) = Undefined (деление на 0)\n");
    //     printf("cot(%.2lf) = Undefined (деление на 0)\n");
    // }

    //11
    // double x1, y1, x2, y2, width, height, area;
    // printf("Enter x1 y1: ");
    // scanf("%lf %lf", &x1, &y1);
    // printf("Enter x2 y2: ");
    // scanf("%lf %lf", &x2, &y2);
    // width = fabs(x2 - x1);
    // height = fabs(y2 - y1)
    // area = width * height;
    // printf("S: %.2lf\n", area);

    //12
    // double x1, y1, x2, y2, x3, y3, area;
    // printf("Enter x1 y1: ");
    // scanf("%lf %lf", &x1, &y1);
    // printf("Enter x2 y2: ");
    // scanf("%lf %lf", &x2, &y2);
    // printf("Enter x3 y3: ");
    // scanf("%lf %lf", &x3, &y3);
    // area = 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    // printf("S: %.2lf\n", area);

    //13
    // int length, width;
    // scanf("%d %d", &length, &width);
    // length -= 100;
    // int desks_per_row = width / 70;
    // int rows = length / 120;
    // int total_seats = desks_per_row * rows;
    // printf("%d\n", total_seats);

    //14
    // double price_veg, price_fruit;
    // int kg_veg, kg_fruit;
    // scanf("%lf %lf %d %d", &price_veg, &price_fruit, &kg_veg, &kg_fruit);
    // double total_income = (price_veg * kg_veg) + (price_fruit * kg_fruit);
    // double total_euro = total_income / 1.95;
    //printf("%.2lf\n", total_euro);

    //15
    // int N, W, L, M, O;
    // printf("Enter square side (N), tile width (W), tile length (L), bench width (M), bench length (O):\n");
    // scanf("%d %d %d %d %d", &N, &W, &L, &M, &O);
    // int tiles_needed = (int)ceil((double)(N * N - M * O) / (W * L));
    // int time_needed = tiles_needed * 3;
    // printf("Tiles needed: %d\n", tiles_needed);
    // printf("Time needed: %d minutes\n", time_needed);

    //16
    // int N_days;
    // double M_dollars, exchange_rate;
    // printf("Enter average workdays per month (N), daily income in dollars (M), and dollar to lev exchange rate:\n");
    // scanf("%d %lf %lf", &N_days, &M_dollars, &exchange_rate);
    // double monthly_salary = N_days * M_dollars;
    // double yearly_salary = monthly_salary * 12;
    // double bonus = monthly_salary * 2.5;
    // double total_income = yearly_salary + bonus;
    // double taxed_income = total_income * 0.75;
    // double daily_income_lev = (taxed_income / 365) * exchange_rate;
    // printf("Ivan's net daily income in leva: %.2lf\n", daily_income_lev);

    return 0;
}