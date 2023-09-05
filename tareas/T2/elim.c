#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    char *s = str;
    char *p = pat;
    char *w = str;
    while (*s != 0) {
        while (*p != 0 && *s == *p) {
            s++;
            p++;
        }
        *w = *s;
        w++;
        s++;
        p = pat;
    }
    *w = 0;
}

char *eliminados(char *str, char *pat) {
    char *s = str;
    char *p = pat;
    char *w = str;
    int l = 0;
    while (*s != 0) {
        while (*p != 0 && *s == *p) {
            s++;
            p++;
        }
        if (*p == 0) {
            l++;
        }
        p = pat;
        s++
    }
    s = str;

    return str;
}
