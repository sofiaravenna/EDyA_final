//
// Created by Ciro on 18/12/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "listaS.h"

Nodo * newNodo(int num){
    Nodo * aux = NULL;
    aux=malloc(sizeof(Nodo));
    if(aux== NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    } else{
        aux->valor=num;
        aux->sig=NULL;
    }
    return aux;
}

Lista * newLista(){
    Lista * aux=NULL;
    aux= malloc(sizeof (Lista));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->cabeza=NULL;
    }
    return aux;
}

void print(Lista * lista){
    if(lista->cabeza==NULL){
        printf("La lista esta vacia.\n");
        exit(-1);
    }
    Nodo * aux = lista->cabeza;
    while (aux != NULL){
        printf("%d  ",aux->valor);
        aux=aux->sig;
    }
}

void enlistar(Lista * lista,Nodo * nodo){
    if(lista->cabeza== NULL){
        lista->cabeza=nodo;
    }else{
        Nodo * aux = lista->cabeza;
        while (aux->sig != NULL){
            aux =aux->sig;
        }
        aux->sig= nodo;
    }
}
