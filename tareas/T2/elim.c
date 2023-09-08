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
        while (*s != *p && *s != 0){
            s++;
        }
        if (s != 0){
            break;
        }
        char *rp = p;
        while (*s == *rp) {
            s++;
            rp++;
            if (*rp == 0) {
                l++;
            }
        }
    }
    s = str;
    p = pat;
    int str_len = strlen(str)+1;
    int pat_len = strlen(pat);
    char *r = (char*)malloc(sizeof(char)*(str_len-(pat_len*l)+1));
    char *w = r;
    while (*s != 0) {
        if (*s == *p) {
            old = s;
            while (*p != 0 && *s == *p) {
                s++;
                p++;
            }
            if (*p != 0) {
                while (old < s) {
                    *w = *old;
                    old++;
                    w++;
                }
            //s = old;

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
