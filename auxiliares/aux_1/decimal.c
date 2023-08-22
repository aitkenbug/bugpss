#include <decimal.h>
#include <stdio.h>
#include <stdlib.h>

int decimal(int binario){
    int acc = 0;
    int pot = 1;
    while (binario !=0){
        if (binario % 10 == 1){
            acc += pot;
        }
    }
}
