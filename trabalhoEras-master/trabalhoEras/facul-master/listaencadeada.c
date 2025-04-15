#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"

listaEmbarcado *criarListaDuplamenteEncadeada() {
    listaEmbarcado *lista = (listaEmbarcado *) calloc(1, sizeof(listaEmbarcado));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
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

void AddFinal(listaEmbarcado *lista, char nome[]) {
    noEmbarcado *no = (noEmbarcado *) calloc(1, sizeof(noEmbarcado));
    if (no != NULL) {
        strcpy(no->nome, nome);
        no->proximo = NULL;
        no->anterior = lista->fim;

        if (lista->fim != NULL) {
            lista->fim->proximo = no;
        } else {
            lista->inicio = no;
        }

        lista->fim = no;
        lista->tamanho++;
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
