#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    char *s = str;
    char *p = pat;
    char *old = str;
    while (*s != 0) {
        if (*s != *p) {
            s++;
            old++;
        }
        while (p != 0 && *s == *p) {
            s++;
            p++;
        }
        old = s;
        old++;
        p = pat;
    }
}

char *eliminados(char *str, char *pat) {
  return NULL;
}
