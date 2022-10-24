#include <ctype.h>

#define islower(a) ((a) >= 'a'&& (a) <= 'z') // definit si un caractere est une lettre minuscule
#define isupper(a) ((a) >= 'A'&& (a) <= 'Z') // definit si un caractere est une lettre majuscule
#define isdigit(a) ((a) >= '0'&& (a) <= '9') // definit si un caractere est un chiffre
#define isalpha(a) (islower(a) || isupper(a)) // definit si un caractere est une lettre
#define isalnum(a) isalpha(a) || isdigit(a) // definit si un caractere est une lettre ou un chiffre
#define iscntrl(a) (((a) <= 0 && (a) <= 31) || (a) == 127) // definit si un caractere est un caractere de controle
#define isspace(a) ((a) == ' ' || (a) == '\t' || (a) == '\r' || (a) == '\n' || (a) == '\v' || (a) == '\f') // definit si un caractere est un caractere d'espacement
#define isgraph(a) (!iscntrl(a) && !isspace(a)) // definit si un caractere est un caractere graphique
#define isprint(a) (!iscntrl(a)) // definit si un caractere est un caractere imprimable
#define ispunct(a) (isgraph(a) && !isalnum(a)) // definit si un caractere est un caractere de ponctuation
#define isxdigit(a) (isdigit(a) || ((a) >= 'A' && (a) <= 'F')) // definit si un caractere est un nombre hexadecimal
#define tolower(a) (islower(a) ? (a) : (a) + 'a' - 'A') // transforme a en minuscule
#define toupper(a) (isupper(a) ? (a) : (a) + 'A' - 'a') // transforme a en majuscule
