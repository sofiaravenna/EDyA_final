#include "listaD.h"
#include "listaS.h"
int main() {
    /*Lista * lista1 =newLista();
    enlistar(lista1, newNodo(1));
    enlistar(lista1, newNodo(2));
    enlistar(lista1, newNodo(3));
    enlistar(lista1, newNodo(4));
    print(lista1);*/

    Lista * listaO = newLista();
    Lista * lista2 = newLista();
    enlistarOrdenado(listaO, newNodo(2));
    enlistarOrdenado(listaO, newNodo(2));
    enlistarOrdenado(listaO, newNodo(2));
    enlistarOrdenado(lista2, newNodo(1));
    enlistarOrdenado(lista2, newNodo(1));
    concatenar(listaO,lista2);
    print(listaO);

    return 0;
}