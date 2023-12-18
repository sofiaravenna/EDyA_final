//
// Created by Ciro on 16/12/2023.
//

#ifndef EDYA_FINAL_LISTAD_H
#define EDYA_FINAL_LISTAD_H

typedef struct nodo{
    int valor;
    struct nodo * ant;
    struct nodo * sig;
}Nodo;

typedef struct lista{
    Nodo * cabeza;
}Lista;

Nodo * newNodo(int num);
Lista * newLista();
void print(Lista * lista);
void enlistar(Lista * lista, Nodo * nodo);
void enlistarOrdenado(Lista * lista, Nodo * nodo);
void eliminar(Lista * lista, Nodo * nodo);
void concatenar(Lista * lista1, Lista * lista2);
Lista * unirLordenadas(Lista * lista1, Lista * lista2); //ej 1 parcial 2023
Lista * resta(Lista * lista1, Lista * lista2); //ej 1 recu 2023
#endif //EDYA_FINAL_LISTAD_H

