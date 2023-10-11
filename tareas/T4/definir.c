#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

//... define variables globales o funciones adicionales ...

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r+");
    fseek(f,0,SEEK_END);
    long p1 = ftell(f);
    return p1;
}
