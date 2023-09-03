#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    char *s = *str;
    char *p = *pat;
    char *old = *str;
    while (*p != 0) {
        if (*s == *p) {
            s++;
            p++;
    }
}

char *eliminados(char *str, char *pat) {
  ...
}
