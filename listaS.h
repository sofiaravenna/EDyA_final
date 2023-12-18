//
// Created by Ciro on 18/12/2023.
//

#ifndef EDYA_FINAL_LISTAS_H
#define EDYA_FINAL_LISTAS_H
typedef struct nodo{
    int valor;
    struct nodo * sig;
}Nodo;

typedef struct lista{
    Nodo * cabeza;
}Lista;

Nodo * newNodo(int num);
Lista * newLista();
void print(Lista * lista);
void enlistar(Lista * lista, Nodo * nodo);
#endif //EDYA_FINAL_LISTAS_H
