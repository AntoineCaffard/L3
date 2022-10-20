#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Word = 25 caracters (english alphabet)


unsigned char isLowercase( char c) {
    if ( c <= 'z' && c >= 'a' ) return 1;
    return 0;
}

unsigned char isUppercase(char c){
    if ( c <= 'Z' && c >= 'A' ) return 1;
    return 0;
}

unsigned char isLetter( char c ){
    if (( c <= 'z' && c >= 'a') || ( c <= 'Z' && c >= 'A' )) return 1;
    return 0;
}

unsigned char convertLowerUpper( char c ){
    assert(isLetter(c));
    if (isUppercase(c)) return c;
    return c + 'A' - 'a';
}

FILE* open(char* name){
    FILE * file = fopen(name,"r");
    if(!file){
        printf("No memory allocated\n");
        return NULL;
    } else {
        printf("File opened\n");
        return file;
    }
}

void readWord(FILE * file){
    char c;
    while ((c = fgetc(file)) != EOF)
        {
            printf("%c", c);
        }
}


int main ( void ){
    FILE* file = open("texte1.txt");
    char input;
    printf("%s",&input);
    readWord(file);
    fclose(file);
    return 0;
}