//
// Created by Ciro on 18/12/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "listaS.h"

Nodo * newNodo(int num){
    Nodo * aux=malloc(sizeof(Nodo));
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
    }else{
        Nodo * aux = lista->cabeza;
        while (aux != NULL){
            printf("%d  ",aux->valor);
            aux=aux->sig;
        }
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

int sizeOf(Lista *lista) {
    int size =0;
    if(lista->cabeza== NULL){
        printf("La lista esta vacia.\n");
    } else{
        Nodo * aux = lista->cabeza;
        while(aux!= NULL){
            size++;
            aux=aux->sig;
        }
    }
    return size;
}
void eliminarPos(Lista * lista, int pos){
    int i=0;

    if(lista->cabeza== NULL){
        printf("La lista esta vacia.\n");
        return;
    }

    Nodo * aux= lista->cabeza;
    Nodo * ant = NULL;

    while (aux!= NULL && i<pos){
            ant=aux;
            aux=aux->sig;
            i++;
    }
    if (aux == NULL) {
        printf("La lista no llega a la posición %d\n", pos);
        return;  // Salir de la función si la posición no es válida
    }
    if (ant == NULL) {  // Si es el primer nodo
        lista->cabeza = aux->sig;
    } else {
        ant->sig = aux->sig;
    }
    free(aux);
}

int elementoPos(Lista * lista, int pos){
    int elemento;
    int i=0;
    if(lista->cabeza== NULL){
        printf("La lista esta vacia.\n");
    }else{
        Nodo * aux= lista->cabeza;
        while (i<pos){
            aux=aux->sig;
            i++;
            if(i> sizeOf(lista)){
                printf("La lista no llega a la posicion %d",pos);
            }
        }
        elemento=aux->valor;
    }
    return elemento;
}