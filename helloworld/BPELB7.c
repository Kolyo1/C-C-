#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct Point{
    double x;
    double y;
}Point;

void Collinear(Point p1, Point p2, Point p3){
    double area = (p1.x - p2.x) * (p2.y - p3.y) - (p1.y - p2.y) * (p2.x - p3.x);
    if (area == 0)
    {
        printf("Points are collinear\n");
    }
    else
    {
        double a = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
        double b = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
        double c = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));

        printf("Distances: \n");
        printf("a: (between p1 and p2) %.2f\n", a);
        printf("b: between p2 and p3) %.2f\n", b);
        printf("c: between p3 and p1) %.2f\n", c);
    }
}

typedef struct {
    char name[50];
    char type[20];
    int year;
    double price;
}Vehicle;

typedef struct {
    Vehicle base;

    union 
    {
        struct {int num_doors;}cars;
        struct {double cc;}motorcycles;
        struct {double length;}boats;
        struct {int engines;}planes;
    }specs;
}SpecifiedVehicle;

void PrintVehicle(SpecifiedVehicle v){
    printf("Name: %s\n", v.base.name);
    printf("Type: %s\n", v.base.type);
    printf("Year: %d\n", v.base.year);
    printf("Price: %.2f\n", v.base.price);

    if (strcmp(v.base.type, "car") == 0)
    {
        printf("Number of doors: %d\n", v.specs.cars.num_doors);
    }
    else if (strcmp(v.base.type, "motorcycle") == 0)
    {
        printf("CC: %.2f\n", v.specs.motorcycles.cc);
    }
    else if (strcmp(v.base.type, "boat") == 0)
    {
        printf("Length: %.2f\n", v.specs.boats.length);
    }
    else if (strcmp(v.base.type, "plane") == 0)
    {
        printf("Engines: %d\n", v.specs.planes.engines);
    }
}

typedef struct{
    char name[50];
    double gpa;
}students;

typedef struct{
    char className[50];
    students student[30];
    int studentCount;
}classroom;

typedef struct{
    classroom class[5];
    int classCount;
}GraduationYear;

void inputStudent(GraduationYear *g, int index) {
    printf("Enter class name: ");
    scanf("%s", g->class[index].className);
    if (g->class[index].className[0] == '\0' || strlen(g->class[index].className) > 50) {
        printf("Class name cannot be empty and can't exceed 50 characters\n");
        return;
    }

    printf("Enter number of students: ");
    scanf("%d", &g->class[index].studentCount);
    if (g->class[index].studentCount > 30 || g->class[index].studentCount < 0) {
        printf("Number of students must be between 0 and 30\n");
        return;
    }

    for (int i = 0; i < g->class[index].studentCount; i++) {
        printf("Enter student name: ");
        scanf("%s", g->class[index].student[i].name);
        if (g->class[index].student[i].name[0] == '\0' || strlen(g->class[index].student[i].name) > 50) {
            printf("Name cannot be empty and can't exceed 50 characters\n");
            i--;
            continue;
        }

        printf("Enter student GPA: ");
        scanf("%lf", &g->class[index].student[i].gpa);
        if (g->class[index].student[i].gpa < 2 || g->class[index].student[i].gpa > 6) {
            printf("GPA must be between 2 and 6\n");
            i--;
        }
    }
}


double classGPA(classroom c){
    double sum = 0;
    for (int i = 0; i < c.studentCount; i++)
    {
        sum += c.student[i].gpa;
    }
    if (c.studentCount == 0)
    {
        return 0;
    }
    return sum / c.studentCount;
}

double yearGPA(GraduationYear y){
    double sum = 0;
    for (int i = 0; i < y.classCount; i++)
    {
        sum += classGPA(y.class[i]);
    }
    if (y.classCount == 0)
    {
        return 0;
    }
    return sum / y.classCount;
}
int main(){
    // Zad 1
    // Point p1, p2, p3;
    // printf("Enter coordinates of point 1: ");
    // scanf("%lf %lf", &p1.x, &p1.y);
    // printf("Enter coordinates of point 2: ");
    // scanf("%lf %lf", &p2.x, &p2.y);
    // printf("Enter coordinates of point 3: ");
    // scanf("%lf %lf", &p3.x, &p3.y);
    // Collinear(p1, p2, p3);

    // Zad 2
    // SpecifiedVehicle v1 = {
    //     .base={"Toyota Corolla", "car", 2015, 20000},
    //     .specs.cars.num_doors = 4
    // };
    // SpecifiedVehicle v2 = {
    //     .base={"Honda CBR", "motorcycle", 2019, 15000},
    //     .specs.motorcycles.cc = 600
    // };
    // SpecifiedVehicle v3 = {
    //     .base={"Yamaha 242X", "boat", 2021, 50000},
    //     .specs.boats.length = 24.5
    // };
    // SpecifiedVehicle v4 = {
    //     .base={"Boeing 747", "plane", 2018, 30000000},
    //     .specs.planes.engines = 4
    // };

    // SpecifiedVehicle vehicle[] = {v1, v2, v3, v4};

    // for (int i = 0; i < 4;i++){
    //     PrintVehicle(vehicle[i]);
    // }
    // SpecifiedVehicle newer = vehicle[0];
    // for(int i = 0; i < 4; i++){
    //     if (vehicle[i].base.year > newer.base.year){
    //         newer = vehicle[i];
    //     }
    // }
    // printf("Newest vehicle:\n");
    // PrintVehicle(newer);

    //Zad 3
    GraduationYear year;
    GraduationYear *graduationYearPtr = &year;

    printf("Enter number of classes: ");
    scanf("%d", &year.classCount);
    if (year.classCount > 5 || year.classCount < 0) {
        printf("Number of classes cannot exceed 5 and be below 0\n");
        return 0;
    }

    graduationYearPtr->classCount = year.classCount;

    // input students for each class
    for (int i = 0; i < year.classCount; i++) {
        inputStudent(graduationYearPtr, i); // Предаваме индекса!
    }

    printf("Average GPA of each class:\n");
    for (int i = 0; i < year.classCount; i++) {
        printf("Class %s: %.2f\n", year.class[i].className, classGPA(year.class[i]));
    }

    printf("Average GPA of the year: %.2f\n", yearGPA(year));
}