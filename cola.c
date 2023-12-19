//
// Created by Ciro on 18/12/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
Nodo * newNodo(int num){
    Nodo * aux =NULL;
    aux= malloc(sizeof (Nodo));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }
    aux->valor=num;
    aux->sig=NULL;
    return aux;
}
Cola * newCola(){
    Cola * aux=NULL;
    aux= malloc(sizeof (Cola));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }
    aux->first=NULL;
    aux->last=NULL;
    return aux;
}

void print(Cola * cola){
    if(cola->first==NULL){
        printf("La cola esta vacia xs.\n");
        exit(-1);
    }
    Nodo * aux= cola->first;
    while(aux != NULL){
        printf("%d  ",aux->valor);
        aux=aux->sig;
    }
}