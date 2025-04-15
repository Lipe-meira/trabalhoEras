#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"

int main() {
    int escolha;

    // Exemplo de uso:
    listaEmbarcado *listaEmbarcado = criarListaEmbarcado();
    listaEspera *listaEspera = criarListaEspera();

    addFinalEspera(listaEspera,"Joao");
    addFinalEspera(listaEspera,"Maria");
    addFinalEspera(listaEspera,"Carlos");

 
    embarcarPrimeiroEspera(listaEmbarcado,listaEspera);
    embarcarPrimeiroEspera(listaEmbarcado,listaEspera);

    printf("Lista embarcados:\n");

    ImprimirEmbarcados(listaEmbarcado);// joao e maria
    printf("\n");

    printf("Lista espera:\n");
    ImprimirEspera(listaEspera);// carlos
    printf("\n");


    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

   /* switch (escolha) {
        case 0:
            printf("Você escolheu sair do menu\n");
            break;

        case 1:
            printf("Você escolheu Adicionar passageiro à espera\n");
            break;

        case 2:
            printf("Você escolheu Listar passageiros em espera\n");
            break;

        case 3:
            printf("Você escolheu Embarcar primeiro passageiro da espera\n");
            break;

        case 4:
            printf("Você escolheu Embarcar último passageiro da espera\n");
            break;

        case 5:
            printf("Você escolheu Embarcar passageiro específico\n");
            break;

        case 6:
            printf("Você escolheu Listar passageiros embarcados\n");
            Imprimir(list);
            break;

        case 7:
            printf("Você escolheu Desembarcar passageiro específico\n");
            break;

        case 8:
            printf("Você escolheu Desembarcar primeiro passageiro\n");
            break;

        case 9:
            printf("Você escolheu Desembarcar último passageiro\n");
            break;

        default:
            printf("Opção inválida. Por favor, escolha uma opção válida.\n");
            break;
    }*/

    return 0;
}
