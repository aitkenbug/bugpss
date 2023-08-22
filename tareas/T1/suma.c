#include <stdio.h>
#include "suma.h"

Bcd mask = 0xf;

Bcd sumaBcd(Bcd x, Bcd y) {
    Bcd x_mask;
    Bcd y_mask;
    Bcd sum;
    for (int i = 0, i<sizeof(Bcd), i++) {
        x_mask = x & mask;
        y_mask = y & mask;
        x_mask + y_mask 
    }
}
