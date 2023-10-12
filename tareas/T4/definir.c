#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

//... define variables globales o funciones adicionales ...

int l_size = 81;

int main(int argc, char *argv[]) {
    char td[] = ":";

    if (argc != 4) {
        fprintf(stderr,"Uso: ./definir <diccionario> <llave> <definicion>\n");
        exit(1);
    }

    int key_size = strlen(argv[2]);

    int def_size = strlen(argv[3]);

    FILE *f = fopen(argv[1], "r+");

    if (f == NULL) {
        perror(argv[1]);
        exit(2);
    }

    fseek(f,0,SEEK_END);//Cursor at the EOF
    long number_lines = ftell(f)/l_size; //number of lines
    fseek(f,0,SEEK_SET); //Cursor at the beginning of the stream
    
    int hash_line = hash_string(argv[2])%number_lines;
    

    fseek(f,0,SEEK_SET);

    int i = 0;
    while (i<number_lines) {
        fseek(f, hash_line*l_size, SEEK_SET);
        char cursor_val = fgetc(f);
        if (cursor_val != ' ') {
            fseek(f,-1,SEEK_CUR);
            int  l = 0;
            while (fgetc(f) != ':') {
                l += 1;
            }
            char buffer[l+1];
            buffer[l]='\0';
            fseek(f,-l-1,SEEK_CUR);
            fread(buffer, l, 1, f);
            if (strcmp(buffer,argv[2]) == 0) {
                fprintf(stderr,"La llave %s ya se encuentra en el diccionario\n",argv[2]);
                exit(1);
            }
            hash_line++;
            if (hash_line>number_lines) {
                hash_line = 0;
            }
            i++;
        }
        else {
            fseek(f,-1,SEEK_CUR);
            fwrite(argv[2], key_size, 1, f);
            fwrite(td, 1, 1, f);
            fwrite(argv[3], def_size, 1, f);
            return 0;
        }
        i++;
    }

    fprintf(stderr,"%s: el diccionario esta lleno\n",argv[1]);
    exit(4);
}
