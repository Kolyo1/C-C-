#include <stdio.h>
#include <string.h>
#include <ctype.h>

void GenerateStr(char str[], int size){
    fgets(str, size, stdin);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

void LenStr(){
    char str[100];
    GenerateStr(str, sizeof(str));
    int count = 0;
    while(str[count] != '\0'){
        count++;
    }
    printf("Len of String: %d\n", count);
}

void NumWords(){
    char str[100];
    GenerateStr(str, sizeof(str));
    int count = 0, i = 0;
    while (str[i] == ' '){
        i++;
    }

    while(str[i] != '\0'){
        if(str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0' && str[i] !='\t'){
            count++;
        }
        i++;
    }
    if(i > 0){
        count++;
    }
    printf("Words in String: %d", count);
}

void CountLetters(){
    char str[100];
    GenerateStr(str, sizeof(str));
    int count[26]= {0};
    for(int i = 0; str[i] != '\0'; i++){
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z'){
            count[ch - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("%c: %d\n", i + 'a', count[i]);
        }
    }
}

void StrCompare(){
    printf("First String: ");
    char str1[100];
    GenerateStr(str1, sizeof(str1));
    printf("Second String: ");
    char str2[100];
    GenerateStr(str2, sizeof(str2));
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]){
            if(str1[i] > str2[i]){
                printf("Fist String is bigger.\n");
            }
            else{
                printf("Second String is bigger.\n");
            }
        return;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        printf("Identical. \n");
    }
}

void CountVowels(){
    char str[100];
    GenerateStr(str,sizeof(str));
    int i = 0;
    char ch;
    int count = 0;
    while (str[i] != '\0'){
        ch = tolower(str[i]);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            count++;
        }
        i++;
    }
    printf("Count of Vowels: %d", count);
}

void LowerToUpper(){
    int i = 0;
    char str[100];
    GenerateStr(str, sizeof(str));
    while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
    }
    printf("In upper case: %s", str);
}

int main(){
    //LenStr();
    NumWords();
    //CountLetters();
    //StrCompare();
    //CountVowels();
    //LowerToUpper();
    return 0;
}