#include <stdio.h>
#include "suma.h"

Bcd mask = 0xf;

Bcd sumaBcd(Bcd x, Bcd y) {
    Bcd x_mask;
    Bcd y_mask;
    Bcd sum = 0;
    Bcd tmp;
    Bcd exs;
    int shift = 0;
    for (int i = 0; i<sizeof(Bcd); i++) {
        x = x >> shift;
        y = y >> shift;
        sum = sum << shift;
        x_mask = x & mask;
        y_mask = y & mask;
        tmp = x_mask + y_mask;
        exs = tmp - 0xa;
        if (tmp > 0x9) {
            sum += exs;
            sum += 0x10;
        }
        else {
            sum += tmp;
        }
        
        shift += 4;
        i++;
    }
    return sum;
}

