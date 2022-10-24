#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct  _dataBufferReader{
    FILE* file;
    int car;
    int currentChar;
    int bit;
    int currentBit;

} dataBufferReader;

dataBufferReader* createBufferReader(char *fileName){
    dataBufferReader* data = (dataBufferReader*) malloc(sizeof(dataBufferReader));
    data->file = fopen(fileName,"r");
    return data;
}

void destroyBufferReader(dataBufferReader* data){
    fclose(data->file);
    free(data);
}

int getCurrentChar(dataBufferReader* data){
    return data->car;
}

int consumeChar(dataBufferReader* data){
    data->currentChar++;
    return data->car = fgetc(data->file);
}

int eof(dataBufferReader* data){
    if (data->car == -1) return 0;
    return 1;
}

int moveBeginning(dataBufferReader*data){
    return eof(data);
}

// Test
int getCurrentBit(dataBufferReader* data){
    return f(data->car,data->currentBit);
}

int consumeBit(dataBufferReader* data){
    data->currentChar++;
    if(data->currentBit == 8){
        consumeChar(data);
    }
}

int main( void ){
    return 0;
}

