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
int sizeOf(Lista * lista);
void eliminarPos(Lista * lista, int pos); //Eliminar el elemento de la lista en una posición dada.
int elementoPos(Lista * lista, int pos); //Obtener el elemento de la lista en una posición dada.
#endif //EDYA_FINAL_LISTAS_H
