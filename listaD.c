//
// Created by Ciro on 16/12/2023.
//
#include <stdio.h>
#include "listaD.h"
#include <stdlib.h>
Nodo *newNodo(int num) {
    Nodo * aux=NULL;
    aux=malloc(sizeof(Nodo));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->valor=num;
        aux->sig=NULL;
        aux->ant=NULL;
    }
    return aux;
}

Lista *newLista() {
    Lista * aux = NULL;
    aux=malloc(sizeof (Lista));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    } else{
        aux->cabeza=NULL;
    }
    return aux;
}

void enlistar(Lista *lista, Nodo *nodo) {
    if(lista->cabeza==NULL) {//la lista esta vacia-> insertar al principio
        lista->cabeza =nodo;
        nodo->ant=NULL;
        nodo->sig=NULL;
    }else{ //insertar al final
        Nodo * aux = lista->cabeza;
        while (aux->sig != NULL){
            aux= aux->sig;
        }
        nodo->sig= NULL;
        nodo->ant=aux;
        aux->sig= nodo;
    }
}

void enlistarOrdenado(Lista *lista, Nodo *nodo) {
    if (lista->cabeza == NULL) { //caso 1: lista vacia
        lista->cabeza = nodo;
        return;
    } else {
        Nodo *act = lista->cabeza;
        Nodo *ant = NULL;
        while (act != NULL && act->valor < nodo->valor) {
            ant = act;
            act = act->sig;
        }

        if(act== NULL){ //caso 2:insertar al final
            ant->sig=nodo;
            nodo->ant=ant;
        }else{
            if(ant==NULL){ //caso 3: insertar al principio
                nodo->sig=act;
                act->ant=nodo;
                lista->cabeza=nodo;
                return;
            }
            nodo->ant=ant;
            nodo->sig= act;
            ant->sig=nodo;
            act->ant=nodo;

        }

    }

}

void eliminar(Lista *lista, Nodo *nodo) {
    // caso 1: lista vacia
    if(lista->cabeza == NULL){
        printf("La lista esta vacia.\n");
    }
    Nodo * act= lista->cabeza;
    Nodo * ant = NULL;
    while(act!= NULL && act->valor!= nodo->valor){
        ant=act;
        act=act->sig;
    }
    if(act == NULL){ //el elemento no esta en la lista
        printf("El elemento %d no esta en la lista.",nodo->valor);
        return;
    }else{
        if(act == lista->cabeza) { //eliminar el primero
            lista->cabeza = act->sig;
            free(act);
        }else{
            //eliminar en el medio
            ant->sig=act->sig;
            act->sig->ant=ant;
            free(act);
        }
    }
}

void print(Lista *lista) {
    if(lista->cabeza== NULL){
        printf("La lista esta vacia.\n");
    }
    Nodo * aux = lista->cabeza;
    while (aux!=NULL){
        printf("%d  ",aux->valor);
        aux=aux->sig;
    }
}

void concatenar(Lista *lista1, Lista *lista2) {
    Nodo * ult = lista1->cabeza;
    while (ult->sig != NULL){
        ult= ult->sig;
    }
    ult->sig= lista2->cabeza;

}

Lista *unirLordenadas(Lista *lista1, Lista *lista2) {
    Lista * listaU=newLista();
     Nodo * aux1= lista1->cabeza;
     Nodo * aux2= lista2->cabeza;
     if(lista1->cabeza == NULL && lista2->cabeza==NULL){
         printf("Ambas listas estan vacias.\n");
         exit(-1);
     }
     while(aux1 != NULL){
         if(aux1==aux2){
             enlistar(listaU, newNodo(aux1->valor));
             aux1=aux1->sig;
             aux2=aux2->sig;
         } else if(aux1->valor<aux2->valor){
             enlistar(listaU, newNodo(aux1->valor));
             aux1=aux1->sig;
         } else if(aux2->valor< aux1->valor){
             enlistar(listaU, newNodo(aux2->valor));
             aux2=aux2->sig;
         }
     }
     if(aux2 !=NULL){
         while (aux2!= NULL){
             enlistar(listaU, newNodo(aux2->valor));
             aux2= aux2->sig;
         }
     }

    return listaU;
}

Lista *resta(Lista *lista1, Lista *lista2) {
    if(lista1->cabeza==NULL && lista2->cabeza==NULL){
        printf("Las dos listas estan vacias.\n");
        exit(-1);
    }
    Lista * listaR = newLista();
    Nodo * aux1= lista1->cabeza;
    Nodo * aux2= lista2->cabeza;
    while (aux1 != NULL){
        if(aux1->valor<aux2->valor){
            enlistar(listaR, newNodo(aux1->valor));
            aux1=aux1->sig;
        }else if (aux1->valor == aux2->valor){
            aux1=aux1->sig;
            aux2=aux2->sig;
        }else if (aux1!= NULL && aux2 == NULL){
            enlistar(listaR, newNodo(aux1->valor));
            aux1=aux1->sig;
        }
    }
    return listaR;
}
