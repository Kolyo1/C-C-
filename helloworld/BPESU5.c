#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Zad 1
void Sum(int people){
    char command[20];
    double one_table = 42.00;
    double chair = 13.99;
    double six_glasses = 5.98;
    double utilities = 21.02;
    double sum = 0;
    double total_tables = 0, total_chairs = 0, total_glasses = 0, total_utilities = 0;
    int table_count = 0, chair_count = 0, glass_count = 0, utility_count = 0;
    int needed_tables = (people + 7) / 8;  
    int needed_chairs = people;
    int needed_glasses = (people + 5) / 6;
    int needed_utilities = people;

    while (1)
    {
        scanf("%s", command);
        if(strcmp(command, "PARTY!") == 0)
        {
            break;
        }
        else if (strcmp(command, "Table") == 0)
        {
            total_tables += one_table;
            table_count++;
        }
        else if (strcmp(command, "Chair") == 0)
        {
            total_chairs += chair;
            chair_count++;
        }
        else if (strcmp(command, "Cups") == 0)
        {
            total_glasses += six_glasses;
            glass_count++;
        }
        else if (strcmp(command, "Place-setting") == 0)
        {
            total_utilities += utilities;
            utility_count++;
        }
        else {
            printf("Invalid item. Try again.\n");
        }
    }

    sum = total_chairs + total_tables + total_glasses + total_utilities;
    printf("Value: %.2lf\n", sum);
    printf("Tables: %d\n", table_count);
    printf("Chairs: %d\n", chair_count);
    printf("Glasses: %d\n", glass_count);
    printf("Utilities: %d\n", utility_count);
    printf("Needed Tables: %d\n", needed_tables - table_count);
    printf("Needed Chairs: %d\n", needed_chairs - chair_count);
    printf("Needed Glasses: %d\n", needed_glasses - glass_count);
    printf("Needed Utilities: %d\n", needed_utilities - utility_count);
}

// Zad 2
typedef struct {
    char name[20];
    double price;
    int id;
}product;

typedef struct{
    char client[20];
    int product_id;
}sales;

void Fill(){
    product p[100];
    int count = 0;
    char temp[20];
    while (1) {
        scanf("%s", temp);
        if (strcmp(temp, "Product") == 0) {
            product ps;
            scanf("%s", ps.name);
            scanf("%lf", &ps.price);
            scanf("%d", &ps.id);
            p[count++] = ps;
        } else if (strcmp(temp, "Exit") == 0) {
            break;
        }
    }

    printf("Products saved! Enter orders:\n");

    while (1) {
        scanf("%s", temp);
        if (strcmp(temp, "Order") == 0) {
            sales s;
            getchar();
            fgets(s.client, 100, stdin);
            size_t len = strlen(s.client);
            if (len > 0 && s.client[len - 1] == '\n') {
                s.client[len - 1] = '\0';
            }
            scanf("%d", &s.product_id);

            int found = 0;
            for (int i = 0; i < count; i++) {
                if (p[i].id == s.product_id) {
                    printf("Order for %s fulfilled!\n", s.client);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Order for %s not fulfilled! Product does not exist.\n", s.client);
            }
        } else if (strcmp(temp, "END") == 0) {
            break;
        }
    }

}

// Zad 3
int starts_with_last_char(const char* prev, const char* next) {
    int len = strlen(prev);
    if (len == 0) return 0;
    char last = tolower(prev[len - 1]);
    char first = tolower(next[0]);
    return last == first;
}

void process_words() {
    FILE* inFile = fopen("input.txt", "r");
    if (!inFile) {
        printf("Неуспешно отваряне на input.txt\n");
        return;
    }

    char buffer[5000];
    fread(buffer, sizeof(char), sizeof(buffer), inFile);
    fclose(inFile);
    char* token = strtok(buffer, " ");
    char** result = NULL;
    int count = 0;

    char prev[51] = "";

    while (token) {
        if (count == 0) {
            result = realloc(result, sizeof(char*) * (count + 1));
            result[count] = strdup(token);
            strcpy(prev, token);
            count++;
        } else {
            if (starts_with_last_char(prev, token)) {
                result = realloc(result, sizeof(char*) * (count + 1));
                result[count] = strdup(token);
                strcpy(prev, token);
                count++;
            }
        }
        token = strtok(NULL, " !");
    }
    FILE* outFile = fopen("output.txt", "w");
    if (!outFile) {
        printf("Неуспешно отваряне на output.txt\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(outFile, "%s\n", result[i]);
    }
    fclose(outFile);
    printf("Съдържание на output.txt:\n");
    outFile = fopen("output.txt", "r");
    char line[51];
    while (fgets(line, sizeof(line), outFile)) {
        printf("%s", line);
    }
    fclose(outFile);
    for (int i = 0; i < count; i++) {
        free(result[i]);
    }
    free(result);
}

int main(){
    // Zad 1
    int people;
    printf("How many people: ");
    scanf("%d", &people);
    Sum(people);

    // Zad 2
    Fill();

    // Zad 3
    process_words();
}