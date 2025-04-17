#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"

int main()
{
    int escolha, escolhaEra;
    char nome[50]; // 50 caracteres pra nome
    // Exemplo de uso:
    listaEmbarcado *listaEmbarcado = criarListaEmbarcado();
    listaEspera *listaEspera = criarListaEspera();
    listaEras *listaEras = criarListaEras();

    // Criando eras automaticamente
<<<<<<< HEAD
    adicionarEra(listaEras, "Idade Media");
    adicionarEra(listaEras, "Era dos Dinossauros");
    adicionarEra(listaEras, "Ano 3000");

    do
    {
        system("cls");
=======
    adicionarEra(listaEras, "Idade Média");
    adicionarEra(listaEras, "Era dos Dinossauros");
    adicionarEra(listaEras, "Ano 3000");

    

    do
    {
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
        printf("1. Adicionar passageiro a espera\n");
        printf("2. Listar passageiros em espera\n");
        printf("3. Embarcar primeiro passageiro da espera\n");
        printf("4. Embarcar ultimo passageiro da espera\n");
        printf("5. Embarcar passageiro especifico\n");
        printf("6. Listar passageiros embarcados\n");
        printf("7. Desembarcar passageiro especifico\n");
        printf("8. Desembarcar primeiro passageiro\n");
        printf("9. Desembarcar ultimo passageiro\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opcao (0 a 9): ");
        scanf("%d", &escolha);
        getchar(); // Limpar o buffer de entrada, caso haja um \n residual

        switch (escolha)
        {
        case 0:
            printf("Voce escolheu sair do menu\n");
            break;

        case 1:
            printf("Voce escolheu Adicionar passageiro a espera, entao escreva o nome dele!\n");
            scanf(" %[^\n]", nome);
<<<<<<< HEAD
            getchar(); // limpa o buffer do Enter
=======
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            addFinalEspera(listaEspera, nome);
            printf("Agora, escolha qual sera o destino dele!\n");
            imprimirErasComLimite(listaEras);
            printf("Escolha a era (1 a 3): ");
            scanf("%d", &escolhaEra);
<<<<<<< HEAD
            selecionarEra(listaEras, escolhaEra, listaEspera);
            getchar(); // Limpar o buffer de entrada, caso haja um \n residual
            system("pause");
=======
            selecionarEra(listaEras, escolhaEra);
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            break;

        case 2:
            printf("Voce escolheu Listar passageiros em espera\n");
            printf("Lista espera:\n");
            ImprimirEspera(listaEspera);
            printf("\n");
<<<<<<< HEAD
            system("pause");
=======
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            break;

        case 3:
            printf("Voce escolheu Embarcar primeiro passageiro da espera\n");
            embarcarPrimeiroEspera(listaEmbarcado, listaEspera);
<<<<<<< HEAD
            system("pause");
=======
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            break;

        case 4:
            printf("Voce escolheu Embarcar ultimo passageiro da espera\n");
            embarcarUltimoEspera(listaEmbarcado, listaEspera);
<<<<<<< HEAD
            system("pause");
=======
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            break;

        case 5:
            printf("Voce escolheu Embarcar passageiro especifico em espera, insira o índice desejado (começa em 1)\n");
            int indice;
            scanf("%d", &indice);
<<<<<<< HEAD
            embarcarEspecificoEspera(listaEmbarcado, listaEspera, indice);
            getchar(); // Limpar o buffer de entrada, caso haja um \n residual
            system("pause");
=======
            embarcarEspecificoEspera(listaEmbarcado, listaEspera,indice);
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            break;

        case 6:
            printf("Voce escolheu Listar passageiros embarcados\n");
            printf("Lista embarcados:\n");
            ImprimirEmbarcados(listaEmbarcado);
            printf("\n");
<<<<<<< HEAD
            system("pause");
=======
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            break;

        case 7:
            printf("Voce escolheu Desembarcar passageiro especifico. Insira o índice desejado (começa em 1)\n");
            scanf("%d", &indice);
<<<<<<< HEAD
            removerEspEmbarcadoEra(listaEmbarcado, indice);
            getchar(); // Limpar o buffer de entrada, caso haja um \n residual
            system("pause");
=======
            embarcarEspecificoNaEra(listaEras, listaEmbarcado, indice);
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            break;

        case 8:
            printf("Voce escolheu Desembarcar primeiro passageiro\n");
<<<<<<< HEAD
            removerPrimeiroEmbarcadoEra(listaEmbarcado, listaEras);
            system("pause");
=======
            adicionarPrimeiroEmbarcadoNaEra(listaEras, listaEmbarcado);
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            break;

        case 9:
            printf("Voce escolheu Desembarcar ultimo passageiro\n");
<<<<<<< HEAD
            removerUltimoEmbarcadoEra(listaEmbarcado);
            system("pause");
=======
            adicionarUltimoEmbarcadoNaEra(listaEras, listaEmbarcado);
>>>>>>> d4424d77cc7676e4f872b114e727256d3ef96932
            break;

        default:
            printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
            break;
        }
    } while (escolha != 0 && temEspacoNasEras(listaEras));

    return 0;
}