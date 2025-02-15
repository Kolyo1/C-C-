#include <stdio.h>
#include<stdbool.h>
#include <string.h>

int main(){

    /*escape sequence = character combination consisting of a backlash/ 
                                    folowed by a leter or combination of digits.
                                    They specify actions within a line or a string of text.
                                    \n = newline
                                    \t = tab           
    */
        //printf("1\t2\t3\n4\t5\t6\n7\t8\t9");
    /* variables = Allocated space in memory to store value.
                    We refer to a variable's name to access the stored value.
                    That variable now behaves as if it was the value it contains.
                    BUT we need to declare what type of data we are storing.
    */

    //int x;//declaration
    //x = 123;//initialization
    //int y = 321;//declaration + initialization

    //int age = 21;
    ///float gpa = 2.05; //floating point number
    //char grade = 'C'; // single characrter
    //char name[]= "Bro"; // array of characters

    //printf("Hello %s\n", name);
    //printf("You are %d years old\n", age);
    //printf("Your average grave is %c\n", grade);
    //printf("Your gpa is %f\n", gpa);

    //char a = 'C'; // single character %c
    //char b[] = "Bro"; // array of characters %s

    //float c = 3.141592653589793; // 4 bytes (32bits of presicion) 6 - 7 digts %f
    //double d =  3.141592653589793; // 8 bytes (64 bites of precision) 15-16 digits %lf
    //printf("%0.15f\n",c);//float
    //printf("%0.15lf\n", d);//double

    //bool e = true; // 1 byte (true or false) %d
    //printf("%d\n",e);

    //char f = 100; // 1 byte (-128 to +127) %d ot %c
    //printf("%c",f); // char
    //unsigned char g = 255; // 1 byte (0 to +255) %d or %c
    //printf("%d\n",g);// usigned char

    //short or short int h = 32767; // 2 bytes (-32,768 to + 32,767) %d
    //unsigned short or  unsigned short int i = 65535; // 2 bytes (0 to +65,535) %d
    //printf("%d\n", h);// short int
    //printf("%d\n", i);// unsigned short int

    //int j = 2147483647; // 4 bytes (-2,147,483,648 to +2,147,483,647) %d
    //unsigned int k = 4294967295; // 4 bytes (0 to +4,294,967,295) %u
    //printf("%d\n", j); // int
    //printf("%u\n", k);// unsigned int

    //long long l = 900000; // 8 bytes (-9 quintillion to +9 quintilion) %lld
    //unsigned long long m = 9; //8 bytes(0 to +18 quintillion) %llu
    //printf("%lld\n", l); // long long
    //pritnf("%llu\n" , m); // usigned long long


    // format specifier % = define and formats a type of data to be displayed

    // %c = character
    // %s = string (array of characters)
    // %f = float
    // %lf = double
    // %d = integer

    //%.1 = decimal precision
    // %1 = minimum field width
    // %- = left align

    //const float PI = 3.14159;  // constant = fixed value that cannot be altered by the program during its execution

    // arithmetic operators

    // + (addition)
    // - (subraction)
    // * (multiplication)
    // / (division)
    // % (modulus)
    // ++ increment
    // - decrement

    // augmented assigned operators = used to replace a statement whre an operator takes a variable as one of its arguments and then assigns the result back to the same variable

    // User input

    // int age;
    // char name[25];

    // printf("\nWhat's your name?");
    // //scanf("%s" , name);
    // fgets(name , 25, stdin);
    // name[strlen(name)-1] = '\0';

    // printf("\nHow old are you?");
    // scanf("%d", &age);

    // printf("\nYou are %d years old" , age);
    // printf("\nHello %s, how are you ?" , name);


    //math functions 
    // #include <math.h>
    // sqrt - корен
    // pow - степен
    //round - заклръгаляне (3.14 = 3)
    //ceil - закръгляне нагоре (3.14 = 4)
    // floor - закрлъгяне надолу (3.99 = 3)
    // fabs - абсолутна стойност
    // log - логаритъм
    // sin - синус
    // cos - косинус
    // tan - тангенс

    
    return 0;
}
