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

void adicionarEra(listaEras *lista, char nome[])
{
    noEra *nova = calloc(1, sizeof(noEra));
    strcpy(nova->valor.nome, nome);
    nova->valor.limitePassageiros = 4; // valor default

    nova->proximo = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = nova;
    }
    else
    {
        noEra *atual = lista->inicio;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = nova;
    }
    // printf("Era '%s' adicionada com limite de passageiros: %d.\n", nome, nova->valor.limitePassageiros);
}

void imprimirErasComLimite(const listaEras *lista)
{
    noEra *no = lista->inicio;
    int i = 1;
    while (no != NULL)
    {
        printf("%d. %s - Limite de passageiros: %d\n", i, no->valor.nome, no->valor.limitePassageiros);
        no = no->proximo;
        i++;
    }
}

int temEspacoNasEras(listaEras *eras)
{
    noEra *atual = eras->inicio;
    while (atual != NULL)
    {
        if (atual->valor.limitePassageiros > 0)
        {
            return 1; // ainda tem espaço
        }
        atual = atual->proximo;
    }
    return 0; // todas lotadas
}

void removeFinalEspera(listaEspera *lista)
{
    if (lista->inicio == NULL)
    {
        printf("A lista de espera esta vazia.\n");
        return;
    }

    noEspera *atual = lista->inicio;
    noEspera *anterior = NULL;

    // Se só tem um nó
    if (atual->proximo == NULL)
    {
        printf("Passageiro '%s' removido da lista de espera.\n", atual->nome);
        free(atual);
        lista->inicio = NULL;
    }
    else
    {
        // Vai até o penúltimo nó
        while (atual->proximo != NULL)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        printf("Passageiro '%s' removido da lista de espera.\n", atual->nome);
        free(atual);
        anterior->proximo = NULL;
    }

    lista->tamanho--;
}

void selecionarEra(listaEras *eras, int escolhaEra, listaEspera *lista)
{
    noEra *atual = eras->inicio;
    int pos = 1;

    while (atual && pos < escolhaEra)
    {
        atual = atual->proximo;
        pos++;
    }

    if (!atual)
    {
        printf("Era invalida! Usando a primeira era disponivel por padrao.\n");
        atual = eras->inicio;
    }

    if (atual->valor.limitePassageiros > 0)
    {
        atual->valor.limitePassageiros--;
        printf("Passageiro adicionado a era %s. Vagas restantes: %d\n", atual->valor.nome, atual->valor.limitePassageiros);
    }
    else
    {
        removeFinalEspera(lista);
        printf("A era %s esta lotada! Por favor, escolha outra era.\n", atual->valor.nome);
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
    lista->tamanho++;
    printf("Passageiro '%s' adicionado a lista de espera.\n", nome);
}

void embarcarPrimeiroEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera)
{
    if (!listaEspera->inicio)  // Verifica se a lista de espera está vazia
    {
        printf("A lista de espera está vazia! Ninguém para embarcar.\n");
        return;
    }

    noEspera *primeiroEspera = listaEspera->inicio;
    noEmbarcado *noEmb = (noEmbarcado *)calloc(1, sizeof(noEmbarcado));

    if (!noEmb)  // Verifica se a alocação foi bem-sucedida
    {
        printf("Erro ao alocar memória para o novo embarcado.\n");
        return;
    }

    // Copia o nome do passageiro para o novo nó de embarcado
    strcpy(noEmb->nome, primeiroEspera->nome);

    // Se a lista de embarcados não está vazia
    if (listaEmbarcado->inicio != NULL)
    {
        // Vai até o último nó de embarcados
        noEmbarcado *noTemp = listaEmbarcado->inicio;
        while (noTemp->proximo != NULL)
        {
            noTemp = noTemp->proximo;
        }

        // Conecta o novo nó ao final da lista de embarcados
        noTemp->proximo = noEmb;
        noEmb->anterior = noTemp;
        noEmb->proximo = NULL;
    }
    else  // Se a lista de embarcados está vazia, o novo nó é o primeiro
    {
        listaEmbarcado->inicio = noEmb;
        listaEmbarcado->fim = noEmb;  // Também atualiza o ponteiro 'fim' se for o primeiro nó
    }

    // Remove o primeiro nó da lista de espera
    listaEspera->inicio = primeiroEspera->proximo;

    // Atualiza o tamanho das listas
    listaEspera->tamanho--;
    listaEmbarcado->tamanho++;

    // Libera o nó removido da lista de espera
    free(primeiroEspera);

    // Mensagem de sucesso
    printf("Passageiro '%s' embarcado do início da lista de espera.\n", noEmb->nome);
}

void embarcarUltimoEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera)
{
    if (!listaEspera->inicio)
        return;

    noEspera *atual = listaEspera->inicio, *anterior = NULL;
    while (atual->proximo)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    noEmbarcado *noEmb = calloc(1, sizeof(noEmbarcado));
    strcpy(noEmb->nome, atual->nome);
    noEmb->anterior = listaEmbarcado->fim;

    if (!listaEmbarcado->inicio)
        listaEmbarcado->inicio = listaEmbarcado->fim = noEmb;
    else
    {
        listaEmbarcado->fim->proximo = noEmb;
        listaEmbarcado->fim = noEmb;
    }

    if (!anterior)
        listaEspera->inicio = NULL;
    else
        anterior->proximo = NULL;

    free(atual);
    listaEspera->tamanho--;
    listaEmbarcado->tamanho++;

    printf("Passageiro '%s' embarcado do final da lista de espera.\n", noEmb->nome);
}



void embarcarEspecificoEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera, int indice)
{
    if (listaEspera->inicio == NULL)
    {
        printf("A lista de espera esta vazia\n");
        return;
    }

    if (indice < 1 || indice > listaEspera->tamanho)
    {
        printf("indice invalido. Nenhum passageiro embarcado.\n");
        return;
    }

    noEspera *atual = listaEspera->inicio;
    noEspera *anterior = NULL;

    int i = 1;
    while (atual != NULL)
    {
        if (i == indice)
        {
            noEmbarcado *noEmb = calloc(1, sizeof(noEmbarcado));
            strcpy(noEmb->nome, atual->nome);
            noEmb->proximo = NULL;

            if (listaEmbarcado->inicio == NULL)
            {
                listaEmbarcado->inicio = noEmb;
                noEmb->anterior = NULL;
            }
            else
            {
                noEmbarcado *ultimo = listaEmbarcado->inicio;
                while (ultimo->proximo != NULL)
                {
                    ultimo = ultimo->proximo;
                }
                ultimo->proximo = noEmb;
                noEmb->anterior = ultimo;
            }

            if (anterior == NULL)
            {
                listaEspera->inicio = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            listaEspera->tamanho--;

            printf("Passageiro '%s' embarcado na posicao %d da lista de espera.\n", noEmb->nome, indice);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
        i++;
    }
}

void removerPrimeiroEmbarcadoEra(listaEmbarcado *embarcados, const listaEras *lista)
{
    noEra *no = lista->inicio;
    if (!embarcados || !embarcados->inicio)
    {
        printf("A lista de embarcados esta vazia!\n");
        return;
    }

    noEmbarcado *remover = embarcados->inicio;

    embarcados->inicio = remover->proximo;
    if (embarcados->inicio)
    {
        embarcados->inicio->anterior = NULL;
    }
    else
    {
        // Lista ficou vazia
        embarcados->fim = NULL;
    }

    printf("Passageiro '%s' chegou do inicio da lista de embarcados para a  %s .\n", remover->nome, no->valor.nome);
    free(remover);
    embarcados->tamanho--;
}

void removerUltimoEmbarcadoEra(listaEmbarcado *listaEmbarcado)
{
    if (listaEmbarcado->inicio == NULL)
    {
        printf("A lista de embarcados está vazia! Ninguém para desembarcar.\n");
        return;
    }

    noEmbarcado *atual = listaEmbarcado->inicio;
    noEmbarcado *anterior = NULL;

    // Se só tem um nó
    if (atual->proximo == NULL)
    {
        printf("Passageiro '%s' desembarcado do final da lista de embarcados.\n", atual->nome);
        free(atual);
        listaEmbarcado->inicio = NULL;
        listaEmbarcado->fim = NULL; // Garantir que o fim também seja NULL quando a lista ficar vazia
    }
    else
    {
        // Vai até o penúltimo nó
        while (atual->proximo != NULL)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        printf("Passageiro '%s' desembarcado do final da lista de embarcados.\n", atual->nome);
        free(atual);
        anterior->proximo = NULL;
        listaEmbarcado->fim = anterior; // Ajusta o fim da lista
    }

    listaEmbarcado->tamanho--;
}

void removerEspEmbarcadoEra(listaEmbarcado *embarcados, int indice)
{
    if (embarcados->inicio == NULL)
    {
        printf("A lista de embarcados esta vazia.\n");
        return;
    }

    if (indice < 1 || indice > embarcados->tamanho)
    {
        printf("indice invalido. Nenhum passageiro embarcado.\n");
        return;
    }

    noEmbarcado *atual = embarcados->inicio;
    noEmbarcado *anterior = NULL;

    int i = 1;
    while (atual != NULL)
    {
        if (i == indice)
        {
            // Remove o passageiro da lista de embarcados
            if (anterior == NULL)
            {
                embarcados->inicio = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }

            if (atual->proximo == NULL)
            {
                embarcados->fim = anterior;
            }
            else
            {
                atual->proximo->anterior = anterior;
            }

            embarcados->tamanho--;
            free(atual);

            printf("Passageiro removido da lista de embarcados com sucesso!\n");
            return;
        }

        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    printf("Passageiro nao encontrado na lista de embarcados.\n");
}

void ImprimirEmbarcados(const listaEmbarcado *lista)
{
    int contador = 1;

    noEmbarcado *no = lista->inicio;

    while (no != NULL)
    {
        printf("%d - %s\n", contador, no->nome);
        no = no->proximo;
        contador++;
    }
}

void ImprimirEspera(const listaEspera *lista)
{
    int contador = 1;
    noEspera *no = lista->inicio;

    while (no != NULL)
    {
        printf("%d - %s\n", contador, no->nome);
        no = no->proximo;
        contador++;
    }
}
