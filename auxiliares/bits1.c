#include <stdio.h>

int bits1(unsigned int n) {
    int cnt = 0;
    for (int i = 0; i < sizeof(int)*8; i++) {
        if ((n>>i) & 1 == 1){
            cnt += (n>>i) & 1;
        }
    }
    return cnt;
}

int main() {
    printf("para 0b0110 el numero de bits es 2 y obtenemos %d", bits1(0b0110));
    printf("\npara 0b0 el numero de bits es 0 y obtenemos %d\n", bits1(0b0));
}
