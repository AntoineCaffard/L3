#include <stdbool.h>
#include <sys/types.h>
#define BUFFER_CAPACITY (8*1024)

typedef struct _dataBufferWriter {
    FILE* file;
    
} dataBufferWriter;

// crée une structure de type dataBufferWriter et l'initialise.
dataBufferWriter*createBufferWriter(char*fileName);

// ferme le fichier et libére la mémoire allouée.
void destroyBufferWriter(dataBufferWriter*data);

// vide le buffer pour l'écrire dans le fichier.
void flush(dataBufferWriter*data);

// ajoute un bit dans le buffer (s'il est plein il faut le vider!).
void putBit(dataBufferWriter*data, bool val);

// ajoute un unsigned char dans le buffer (s'il est plein il faut le vider!).
void putUnsignedChar(dataBufferWriter*data, u_int8_t val);

// ajoute un unsigned int dans le buffer (s'il est plein il faut le vider!).
void putUnsignedInt(dataBufferWriter*data, unsigned val);
