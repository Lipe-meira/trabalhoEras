#include "metodos.h"
#include <stdio.h>
#include <stdlib.h>

noEra *_criarNoEra(Era *era) {
    noEra *no = (noEra *) calloc(1, sizeof(noEra));
    if (no != NULL) {
        no->valor = *era;  // Copia o conteúdo da struct Era para o nó
        no->proximo = NULL;
    }
    return no;
}

//tralala
listaPassageiros *criarListaDuplamenteEncadeada(){
listaPassageiros *lista = (listaPassageiros*)
    calloc(1, (sizeof(listaPassageiros)));
lista-> inicio = NULL;
return lista;
}

void addInicio(listaEmbarcado *lista, char nome[]) {
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

//tralala
void AddFinal(listaPassageiros *lista, int valor){
    noDuplo *noAxu = lista->inicio;
    noDuplo *novoNo= _criarNo(valor);
    if(noAxu==NULL){
        lista->inicio = novoNo;
    }
    else{
         while(noAxu->proximo != NULL){
             noAxu=noAxu->proximo;
         }
         noAxu->proximo = novoNo;
    }
}


void Imprimir(const listaEmbarcado *lista) {
    noEmbarcado *no = lista->inicio;

    while (no != NULL) {
        printf("%s -> ", no->nome);
        no = no->proximo;
    }
    printf("NULL\n");
}


