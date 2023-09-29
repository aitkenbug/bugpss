#include <stddef.h>

#include "prev.h"

void asignarPrev(Nodo *t, Nodo **pprev) {
  if (t->izq == NULL) {
  return;
  }
  if (t->der == NULL) {
    return;
  } 
  else {
    t->prev = *pprev;
    t->prox = NULL;
    if (*pprev != NULL) {
        (*pprev)->prox = t;
    }
    *pprev = t;
    asignarPrev(t,pprev);
  }
}
