//
// Created by Ciro on 18/12/2023.
//

#ifndef EDYA_FINAL_COLA_H
#define EDYA_FINAL_COLA_H
typedef struct nodo{
    int valor;
    struct nodo * sig;
}Nodo;

typedef struct cola{
    Nodo * first;
    Nodo * last;
}Cola;

Nodo * newNodo(int num);
Cola * newCola();
void encolar(Cola * cola, Nodo * nodo);
void desencolar(Cola * cola);
void print(Cola * cola);
#endif //EDYA_FINAL_COLA_H
