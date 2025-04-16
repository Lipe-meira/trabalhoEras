#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"

listaEmbarcado *criarListaEmbarcado() {
    listaEmbarcado *lista = (listaEmbarcado *)calloc(1, sizeof(listaEmbarcado));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

listaEras *criarListaEras() {
    listaEras *lista = (listaEras *)calloc(1, sizeof(listaEras));
    lista->inicio = NULL;
    return lista;
}

listaEspera *criarListaEspera() {
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
    printf("Era '%s' adicionada com limite de passageiros: %d.\n", nome, nova->valor.limitePassageiros);
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
    } else {
        printf("A era %s está lotada! Por favor, escolha outra era.\n", atual->valor.nome);
    }
}

void addEmbarcado(listaEmbarcado *lista, char nome[]) {
    noEmbarcado *no = (noEmbarcado *)calloc(1, sizeof(noEmbarcado));
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
        printf("Passageiro '%s' adicionado à lista de embarcados.\n", nome);
    }
}

void addFinalEspera(listaEspera *lista, char nome[]) {
    noEspera *no = (noEspera *)calloc(1, sizeof(noEspera));

    strcpy(no->nome, nome);
    no->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = no;
    } else {
        noEspera *ultimoNo = lista->inicio;
        while (ultimoNo->proximo != NULL) {
            ultimoNo = ultimoNo->proximo;
        }
        ultimoNo->proximo = no;
    }
    lista->tamanho++;
    printf("Passageiro '%s' adicionado à lista de espera.\n", nome);
}

void embarcarPrimeiroEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera) {
    noEspera *primeiroEspera = listaEspera->inicio;
    noEmbarcado *noEmb = (noEmbarcado *)calloc(1, sizeof(noEmbarcado));
    strcpy(noEmb->nome, primeiroEspera->nome);
    if (listaEmbarcado->inicio != NULL) {
        noEmbarcado *noTemp = listaEmbarcado->inicio;
        while (noTemp->proximo != NULL) {
            noTemp = noTemp->proximo;
        }
        noTemp->proximo = noEmb;
        noEmb->anterior = noTemp;
        noEmb->proximo = NULL;
    } else {
        listaEmbarcado->inicio = noEmb;
    }

    listaEspera->inicio = primeiroEspera->proximo;
    listaEmbarcado->tamanho++;
    listaEspera->tamanho--;
    free(primeiroEspera);

    printf("Passageiro '%s' embarcado do início da lista de espera.\n", noEmb->nome);
}

void embarcarUltimoEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera) {
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
    listaEspera->tamanho--;
    listaEmbarcado->tamanho++;

    printf("Passageiro '%s' embarcado do final da lista de espera.\n", noEmb->nome);
}

void embarcarEspecificoEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera, int indice) {
    if (listaEspera->inicio == NULL) {
        printf("A lista de espera está vazia\n");
        return;
    }

    if (indice < 1 || indice > listaEspera->tamanho) {
        printf("Índice inválido. Nenhum passageiro embarcado.\n");
        return;
    }

    noEspera *atual = listaEspera->inicio;
    noEspera *anterior = NULL;

    int i = 1;
    while (atual != NULL) {
        if (i == indice) {
            noEmbarcado *noEmb = calloc(1, sizeof(noEmbarcado));
            strcpy(noEmb->nome, atual->nome);
            noEmb->proximo = NULL;

            if (listaEmbarcado->inicio == NULL) {
                listaEmbarcado->inicio = noEmb;
                noEmb->anterior = NULL;
            } else {
                noEmbarcado *ultimo = listaEmbarcado->inicio;
                while (ultimo->proximo != NULL) {
                    ultimo = ultimo->proximo;
                }
                ultimo->proximo = noEmb;
                noEmb->anterior = ultimo;
            }

            if (anterior == NULL) {
                listaEspera->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            listaEspera->tamanho--;

            printf("Passageiro '%s' embarcado na posição %d da lista de espera.\n", noEmb->nome, indice);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
        i++;
    }
}

void adicionarPrimeiroEmbarcadoNaEra(listaEras *eras, listaEmbarcado *embarcados) {
    if (!embarcados->inicio) return;

    noEmbarcado *primeiro = embarcados->inicio;
    noEra *nova = calloc(1, sizeof(noEra));
    strcpy(nova->valor.nome, primeiro->nome);

    if (!eras->inicio) eras->inicio = nova;
    else {
        noEra *atual = eras->inicio;
        while (atual->proximo) atual = atual->proximo;
        atual->proximo = nova;
    }

    embarcados->inicio = primeiro->proximo;
    if (embarcados->inicio) embarcados->inicio->anterior = NULL;
    else embarcados->fim = NULL;

    embarcados->tamanho--;
    free(primeiro);

    printf("Passageiro '%s' adicionado à era.\n", nova->valor.nome);
}

void adicionarUltimoEmbarcadoNaEra(listaEras *eras, listaEmbarcado *embarcados) {
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

    printf("Passageiro '%s' adicionado à era.\n", nova->valor.nome);
}

void embarcarEspecificoNaEra(listaEras *eras, listaEmbarcado *embarcados, int indice) {
    if (embarcados->inicio == NULL) {
        printf("A lista de embarcados está vazia.\n");
        return;
    }

    if (indice < 1 || indice > embarcados->tamanho) {
        printf("Índice inválido. Nenhum passageiro embarcado.\n");
        return;
    }

    noEmbarcado *atual = embarcados->inicio;
    noEmbarcado *anterior = NULL;

    int i = 1;
    while (atual != NULL) {
        if (i == indice) {
            noEra *novaEra = calloc(1, sizeof(noEra));
            strcpy(novaEra->valor.nome, atual->nome);
            
            // Insere na lista de eras
            if (eras->inicio == NULL) {
                eras->inicio = novaEra;
            } else {
                noEra *atualEra = eras->inicio;
                while (atualEra->proximo != NULL) {
                    atualEra = atualEra->proximo;
                }
                atualEra->proximo = novaEra;
            }

            // Remove o passageiro da lista de embarcados
            if (anterior == NULL) {
                embarcados->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            if (atual->proximo == NULL) {
                embarcados->fim = anterior;
            } else {
                atual->proximo->anterior = anterior;
            }

            embarcados->tamanho--;
            free(atual);

            printf("Passageiro %s embarcado na era com sucesso!\n", novaEra->valor.nome);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
        i++;
    }
}

void ImprimirEmbarcados(const listaEmbarcado *lista) {
    int contador = 1;

    noEmbarcado *no = lista->inicio;

    while (no != NULL) {
        printf("%d - %s\n", contador, no->nome);
        no = no->proximo;
        contador++;
    }
}

void ImprimirEspera(const listaEspera *lista) {
    int contador = 1;
    noEspera *no = lista->inicio;

    while (no != NULL) {
        printf("%d - %s\n", contador, no->nome);
        no = no->proximo;
        contador++;
    }
}

void ImprimirEras(const listaEras *lista) {
    noEra *no = lista->inicio;

    while (no != NULL) {
        printf("->%s ", no->valor.nome);
        no = no->proximo;
    }
    printf("\n");
}
