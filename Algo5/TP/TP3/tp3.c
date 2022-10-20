#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    assert(isLowercase(c));
    return c + 'A' - 'a';
}

void open( FILE* file, char* name){
    if(!file) printf("No memory allocated\n");
    else{
        file = fopen(name,"r");
        printf("File opened\n");
    }
}


int main ( void ){
    FILE* file = (FILE*) malloc(sizeof(FILE));
    char input;
    printf("%s",&input);
    open(file,"test.txt");
    return 0;
}