#include "ListaEncadeada.h"
#include<stdio.h>
#include <stdlib.h>


noEra *_criarNoEra(Era *era){
noEra *no = (noEra*) calloc(1,(sizeof(noEra)));
noEra->(valor) = valor;
noEra-> (proximo) = NULL;
return no;
}


/*listaPassageiros *criarListaDuplamenteEncadeada(){
listaPassageiros *lista = (listaPassageiros*)
    calloc(1, (sizeof(listaPassageiros)));
lista-> inicio = NULL;
return lista;
}*/

void addInicio(listaEras *lista, Era *valor) {
    noEra *no = _criarNoEra(valor);
    if (lista->inicio == NULL) {
        lista->inicio = no;
    } else
        no->proximo = lista->inicio;
        lista->inicio = no;
    }
}
/*
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
*/

void Imprimir( const listaPassageiros *lista){
    noDuplo *no = lista->inicio;

    while(no!=NULL){
   printf("%d ->", no->valor );

   no=no->proximo;
    }
    printf("NULL");
}

