#include "listaS.h"
int main() {
    Lista * lista1 = newLista();
    enlistar(lista1, newNodo(1));
    enlistar(lista1, newNodo(2));

    print(lista1);
    return 0;
}