#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "listaencadeada.h"
 
 listaEmbarcado *criarListaEmbarcado()
 {
     listaEmbarcado *lista = (listaEmbarcado *)calloc(1, sizeof(listaEmbarcado));
     lista->inicio = NULL;
     lista->fim = NULL;
     lista->tamanho = 0;
     return lista;
 }
 
 listaEras *criarListaEras()
 {
     listaEras *lista = (listaEras *)calloc(1, sizeof(listaEras));
     lista->inicio = NULL;
     return lista;
 }
 
 listaEspera *criarListaEspera()
 {
     listaEspera *lista = (listaEspera *)calloc(1, sizeof(listaEspera));
     lista->inicio = NULL;
     return lista;
 }
 
 void adicionarEra(listaEras *lista, char nome[]) {
    noEra *nova = calloc(1, sizeof(noEra));
    strcpy(nova->valor.nome, nome);
    nova->valor.limitePassageiros = 4; // valor default

    nova->proximo = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = nova;
    } else {
        noEra *atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = nova;
    }
}

void imprimirErasComLimite(const listaEras *lista) {
    noEra *no = lista->inicio;
    int i = 1;
    while (no != NULL) {
        printf("%d. %s - Limite de passageiros: %d\n", i, no->valor.nome, no->valor.limitePassageiros);
        no = no->proximo;
        i++;
    }
}

int temEspacoNasEras(listaEras *eras) {
    noEra *atual = eras->inicio;
    while (atual != NULL) {
        if (atual->valor.limitePassageiros > 0) {
            return 1; // ainda tem espaço
        }
        atual = atual->proximo;
    }
    return 0; // todas lotadas
}


void selecionarEra(listaEras *eras, int escolhaEra) {
    noEra *atual = eras->inicio;
    int pos = 1;

    // Navega até a era escolhida
    while (atual && pos < escolhaEra) {
        atual = atual->proximo;
        pos++;
    }

    if (!atual) {
        printf("Era invalida! Usando a primeira era disponivel por padrao.\n");
        atual = eras->inicio;
    }

    if (atual->valor.limitePassageiros > 0) {
        atual->valor.limitePassageiros--;
        printf("Passageiro adicionado à era %s. Vagas restantes: %d\n", atual->valor.nome, atual->valor.limitePassageiros);
        // Aqui você poderia adicionar o passageiro, por exemplo
    } else {
        printf("A era %s está lotada! Por favor, escolha outra era.\n", atual->valor.nome);
    }
}

 void addEmbarcado(listaEmbarcado *lista, char nome[])
 {
     noEmbarcado *no = (noEmbarcado *)calloc(1, sizeof(noEmbarcado));
     if (no != NULL)
     {
         strcpy(no->nome, nome);
         no->anterior = NULL;
         no->proximo = lista->inicio;
 
         if (lista->inicio != NULL)
         {
             lista->inicio->anterior = no;
         }
         else
         {
             lista->fim = no;
         }
 
         lista->inicio = no;
         lista->tamanho++;
     }
 }
 
 void addFinalEspera(listaEspera *lista, char nome[])
 {
     noEspera *no = (noEspera *)calloc(1, sizeof(noEspera));
 
     strcpy(no->nome, nome);
     no->proximo = NULL;
 
     if (lista->inicio == NULL)
     {
         lista->inicio = no;
     }
     else
     {
         noEspera *ultimoNo = lista->inicio;
         while (ultimoNo->proximo != NULL)
         {
             ultimoNo = ultimoNo->proximo;
         }
         ultimoNo->proximo = no;
     }
 }
 
 void embarcarPrimeiroEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera)
 {
     noEspera *primeiroEspera = listaEspera->inicio;
     noEmbarcado *noEmb = (noEmbarcado *)calloc(1, sizeof(noEmbarcado));
     strcpy(noEmb->nome, primeiroEspera->nome);
     if (listaEmbarcado->inicio != NULL)
     {
         noEmbarcado *noTemp = listaEmbarcado->inicio;
         while (noTemp->proximo != NULL)
         {
             noTemp = noTemp->proximo;
         }
         noTemp->proximo = noEmb;
         noEmb->anterior = noTemp;
         noEmb->proximo = NULL;
     }
     else
     {
         listaEmbarcado->inicio = noEmb;
     }
 
     listaEspera->inicio = primeiroEspera->proximo;
     free(primeiroEspera);
 }
 
 void embarcarUltimoEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera)
 {
     if (!listaEspera->inicio) return;
 
     noEspera *atual = listaEspera->inicio, *anterior = NULL;
     while (atual->proximo) {
         anterior = atual;
         atual = atual->proximo;
     }
 
     noEmbarcado *noEmb = calloc(1, sizeof(noEmbarcado));
     strcpy(noEmb->nome, atual->nome);
     noEmb->anterior = listaEmbarcado->fim;
 
     if (!listaEmbarcado->inicio)
         listaEmbarcado->inicio = listaEmbarcado->fim = noEmb;
     else {
         listaEmbarcado->fim->proximo = noEmb;
         listaEmbarcado->fim = noEmb;
     }
 
     if (!anterior) listaEspera->inicio = NULL;
     else anterior->proximo = NULL;
 
     free(atual);
     listaEmbarcado->tamanho++;
 }
 
 void adicionarPrimeiroEmbarcadoNaEra(listaEras *eras, listaEmbarcado *embarcados)
 {
     if (!embarcados->inicio) return;
 
     noEmbarcado *primeiro = embarcados->inicio;
     noEra *nova = calloc(1, sizeof(noEra));
     strcpy(nova->valor.nome, primeiro->nome);
 
     // Insere no final da lista de eras
     if (!eras->inicio) eras->inicio = nova;
     else {
         noEra *atual = eras->inicio;
         while (atual->proximo) atual = atual->proximo;
         atual->proximo = nova;
     }
 
     // Remove o primeiro da lista de embarcados
     embarcados->inicio = primeiro->proximo;
     if (embarcados->inicio) embarcados->inicio->anterior = NULL;
     else embarcados->fim = NULL;
 
     embarcados->tamanho--;
     free(primeiro);
 }
 
 void adicionarUltimoEmbarcadoNaEra(listaEras *eras, listaEmbarcado *embarcados)
 {
     if (!embarcados->fim) return;
 
     noEmbarcado *ultimo = embarcados->fim;
     noEra *nova = calloc(1, sizeof(noEra));
     strcpy(nova->valor.nome, ultimo->nome);
 
     if (!eras->inicio) eras->inicio = nova;
     else {
         noEra *atual = eras->inicio;
         while (atual->proximo) atual = atual->proximo;
         atual->proximo = nova;
     }
 
     embarcados->fim = ultimo->anterior;
     if (embarcados->fim) embarcados->fim->proximo = NULL;
     else embarcados->inicio = NULL;
 
     embarcados->tamanho--;
     free(ultimo);
 }
 
 
 void ImprimirEmbarcados(const listaEmbarcado *lista)
 {
     noEmbarcado *no = lista->inicio;
 
     while (no != NULL)
     {
         if (no != NULL)
         {
             printf("->%s", no->nome);
         }
         no = no->proximo;
     }
 }
 
 void ImprimirEspera(const listaEspera *lista)
 {
     noEspera *no = lista->inicio;
 
     while (no != NULL)
     {
         if (no != NULL)
         {
             printf("->%s ", no->nome);
         }
         no = no->proximo;
     }
 }
 
 void ImprimirEras(const listaEras *lista)
 {
     noEra *no = lista->inicio;
 
     while (no != NULL)
     {
         printf("->%s ", no->valor.nome);
         no = no->proximo;
     }
 }