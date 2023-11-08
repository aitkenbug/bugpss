#include <string.h>

int strCmp(char *s1, char *s2) {
    char c1;
    char c2;

    for (;;) {
      c1= *s1;
      c2= *s2;

      if (c1==0)
        break;

      if (c1!=c2)
        break;

      s1++;
      s2++;
    }

    return c1 - c2;
}


int contarPal(char* pal) {
    int l = 0;
    
    if (pal[0] == 0) {
        return 0;
    }

    if (pal[0] != ' ') {
        l++;
    }

    for (int i = 0; i < strlen(pal); i++) {
        if (pal[i] != ' ' && pal[i-1] == ' ') {
            l++;
        }
    }
    return l;
}

void sort(char **a, int n) {
  char **ult= &a[n-1];
  char **p= a;
  while (p<ult) {

    int t1= contarPal(p[0]) - contarPal(p[1]);

    if (t1 <= 0)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= a;
    }
  }
}
