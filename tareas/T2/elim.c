#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    char *s = str;
    char *p = pat;
    //char *old = str;
    while (*s != 0) {
        if (*s != *p) {
            //*str = *s;
            s++;
            //str++;
        }
        while (p != 0 && *s == *p) {
            s++;
            p++;
        }
        *str = *s;
    }
}

char *eliminados(char *str, char *pat) {
  return NULL;
}
