#include <stdio.h>
#include "suma.h"

Bcd mask = 0xf;

Bcd sumaBcd(Bcd x, Bcd y) {
    Bcd sum = 0;
    Bcd x_mask;
    Bcd y_mask;
    Bcd tmp;
    Bcd exs = 0;
    int shift = 0;
    while (shift < 64) {
        x_mask = (x >> shift) & mask;
        y_mask = (y >> shift) & mask;
        tmp = x_mask + y_mask + exs;
        if (tmp > 0x9) {
            sum = sum + ((tmp - 0xa) << shift);
            exs = 0x1;
        }
        else {
            sum = sum + (tmp << shift);
            exs = 0x0;
        }
        shift += 4;
    }
    if (exs > 0) {
        return 0xffffffffffffffff;
    }
    else {
        return sum;
    }
}

