#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    char *s = str;
    char *p = pat;
    char *w = str;
    char *old = str;
    while (*s != 0) {
        if (*s == *p) {
            old = s;
            while (*p != 0 && *s == *p) {
                s++;
                p++;
            }
            if (*p != 0) {
                s = old;
            }
        }
        *w = *s;
        w++;
        if (*s != 0) {
            s++;
        }
        p = pat;
    }
    *w = 0;
}

char *eliminados(char *str, char *pat) {
    char *s = str;
    char *p = pat;
    int l = 0;
    char *old = str;
    while (*s != 0) {
        while (*p != 0 && *s == *p) {
            p++;
            s++;
        }
        if (*p == 0) {
            l++;
        }
        p = pat;
        if (*s != 0){
            s++;
        }
    }
    s = str;
    p = pat;
    char *r = malloc((strlen(str)-strlen(pat)*l+2));
    char *w = r;
    while (*s != 0) {
        if (*s == *p) {
            old = s;
            while (*p != 0 && *s == *p) {
                s++;
                p++;
            }
            if (*p != 0) {
                s = old;
            }
        }
        *w = *s;
        w++;
        if (*s != 0) {
            s++;
        }
        p = pat;
    }
    *w = 0;
    return r;
}
