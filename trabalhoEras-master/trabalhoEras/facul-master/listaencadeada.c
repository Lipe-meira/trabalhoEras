#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"

listaEmbarcado *criarListaEmbarcado() {
    listaEmbarcado *lista = (listaEmbarcado *) calloc(1, sizeof(listaEmbarcado));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

listaEspera *criarListaEspera() {
    listaEspera *lista = (listaEspera*) calloc(1, sizeof(listaEspera));
    lista->inicio = NULL;
    return lista;
}

void addEmbarcado(listaEmbarcado *lista, char nome[]) {
    noEmbarcado *no = (noEmbarcado *) calloc(1, sizeof(noEmbarcado));
    if (no != NULL) {
        strcpy(no->nome, nome);
        no->anterior = NULL;
        no->proximo = lista->inicio;

        if (lista->inicio != NULL) {
            lista->inicio->anterior = no;
        } else {
            lista->fim = no;
        }

        lista->inicio = no;
        lista->tamanho++;
    }
}

void addFinalEspera(listaEspera *lista, char nome[]) {
    noEspera *no = (noEspera *) calloc(1, sizeof(noEspera));
    

    strcpy(no->nome, nome);
    no->proximo = NULL;

    if(lista->inicio==NULL){
        lista->inicio=no;
    }
    else{
        noEspera *ultimoNo=lista->inicio;
        while(ultimoNo->proximo!=NULL){
            ultimoNo=ultimoNo->proximo;
        }
        ultimoNo->proximo=no;


    }
   
}

void embarcarPrimeiroEspera(listaEmbarcado*listaEmbarcado, listaEspera*listaEspera){
    noEspera* primeiroEspera=listaEspera->inicio;
    noEmbarcado *noEmb = (noEmbarcado *) calloc(1, sizeof(noEmbarcado));
    strcpy(noEmb->nome, primeiroEspera->nome);
    if(listaEmbarcado->inicio!=NULL){
        noEmbarcado * noTemp=listaEmbarcado->inicio;
        while(noTemp->proximo!=NULL){
            noTemp=noTemp->proximo;
        }
        noTemp->proximo=noEmb;
        noEmb->anterior=noTemp;
        noEmb->proximo=NULL;
        
    }
    else{
        listaEmbarcado->inicio=noEmb;
    }

    listaEspera->inicio=primeiroEspera->proximo;
    free(primeiroEspera);

    
}



void ImprimirEmbarcados(const listaEmbarcado *lista) {
    noEmbarcado *no = lista->inicio;

    while (no != NULL) {
        if(no!=NULL){
        printf("->%s", no->nome);
    }
        no = no->proximo;
    }
    
       
    
}

void ImprimirEspera(const listaEspera *lista) {
    noEspera *no = lista->inicio;

    while (no != NULL) {
        if(no!=NULL){
        printf("->%s ", no->nome);
    }
        no = no->proximo;
    }
    
       
    
}
