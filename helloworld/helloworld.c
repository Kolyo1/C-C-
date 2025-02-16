#include <stdio.h>
#include<stdbool.h>
#include <string.h>

int findMax(int, int);
double square(double );
void Birthday(char[],int);
void hello(char[], int);//function protorype


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

    // if statments

    // int age; 

    // printf("Enter your age: ");
    // scanf("%d", &age);

    // if(age >= 18) {
    //     printf("You are now signed up. ");
    // }
    // else if(age < 0){
    //     printf("You are not born yet. ");
    // }
    // else{
    //     printf("You are too young. ");
    // }

    // switch = A more efficient alternative to using many 'else if' statements 
    // allows a value to be tested for equality against many cases

    // char grade;

    // printf("Enter your grade: ");
    // scanf("%c", grade);

    // switch(grade){
    //     case 'A':
    //         printf("Excelent. ");
    //     break;
    //     case 'B':
    //         printf("You did good. ");
    //     break;
    //     case 'C':
    //         printf("You did OK. ");
    //     break;
    //     case 'D':
    //         printf("Atleast its not a fail. ");
    //     break;
    //     case 'F':
    //         printf("You failed. ");
    //     break;
    //     default:
    //         printf("Enter valid grade");
    //     break;    
    // }

    // logical operators = &&(AND) checks if two conditions are true

    // float temp = 25;
    // bool sunny = true;

    // if(temp >= 0 && temp <= 26 && sunny){
    //     printf("The weather is perfect. ");
    // }
    // else{
    //     printf("The weather is bad. ");
    // }

    // logical operators = ||(OR) check if atleast one condition is true

    // float temp = 25;

    // if(temp<= 0 || temp >= 30){
    //     printf("The weather is bad. ");
    // }
    // else {
    //     printf("The weather is good. ");
    // }

    // logical operators = !(NOT) reverses the state of a condition

    // bool sunny = true;
    // if(!sunny){
    //     printf("Its cloudy. ");
    // }
    // else{
    //     printf("Its sunny. ");
    // }

    // functions
    // Birthday();
    // Birthday();
    // Birthday();

    // arguments 
    // char name[] = "Mango";
    // int age = 21;
    // Birthday(name, age);

    // return = returns a value back to a calling function

    // double x = square(3.14);
    // printf(x);

    // ternary operator = shortcut to if/else when assigning/returning a value
    // (condition) ? value if true : value if false

    // int max = findMax(3,4);
    // printf("%d", max);

    // function prototype
    // Function declaration , without body, before main()
    // Ensure that calls to a function are made with the correct arguments

    // char name[] = "Ahmed";
    // int age = 21;
    // hello(name, age);

    // string functions

    char string1[] = "Bro";
    char string2[] = "Code";

    // strlwr(string1);   // converts a string to lowercase = (bro)
    // strupr(string2);   // converts a string to uppercase = (BRO)
    // strcat(string1, string2);  // appends string2 to end of string1 = (BroCode)
    // strncat(string1, string2, 1);  // appends n characters from string2 to string1 = (BroC)
    // strcpy(string1, string2);  // copy string2 to string1 = (Code)
    // strncpy(string1, string2,1);   // copy n characters of string2 to string1 = (Cro)

    // strset(string1, '?);   // sets all characters of string to a given character  = (???)
    // strnset(string1, 'x', 1); // sets n characters of string to a given character  = (xro)
    // strrev(string1); // reverse a string = (orB) 

    // int result = strlen(string1);    // returns string length as int = (3)
    // int result = strcmp(string1, string2);  // string compare all characters = (1) 0 if they are the same or 1 if they are not the same
    // int result = strncmp(string1, string2, 1);  // string compare n characters 
    // int result = strcmpi(string1, string2);  // string compare all(ignore case)
    // int result = strnicmp(string1, string2, 1);  // string compare n characters (ignore case)

    //for loop = repeats a section of code a limited ammount of times

    // for(int i = 1; i <= 10; i+=2){
    //     printf("%d\n", i);
    // }

    // while loops = repeat a section of code possibly ulimited times
    // WHILE some condition remains true
    // a while loop might not execute at all

    // char name[25];

    // printf("Enter your name: ");
    // fgets(name,25,stdin);
    // name[strlen(name) -1] = '\0';
    // while (strlen(name) == 0){
    //     printf("Enter your name. ");
    //     fgets(name,25,stdin);
    //     name[strlen(name) -1] = '\0';
    // }
    // printf("Hello %s" , name);

    // do while = always executes a block of code once, THEN checks condition

    // int number = 0;
    // int sum = 0;

    // do{
    //     printf("Enter a number above 0: ");
    //     scanf("%d", &number);
    //     if(number>0){
    //         sum += number;
    //     }
    // }while(number > 0);
    // printf("SUM: %d ", sum);

    // nested loop = a loop inside of another loop
    

    return 0;
}

int findMax(int x, int y)
{
    return (x>y) ? x : y;
}

double square(double x){
    double result = x*x;
    return result;
}

void Birthday(char name[],int age)
{
    printf("Happy Birthday dear %s!. ", name);
    printf("You are %d years old! ", age);
}

void hello(char name[], int age){
    printf("\nHello %s", name);
    printf("\nYour age is %d", age);
}