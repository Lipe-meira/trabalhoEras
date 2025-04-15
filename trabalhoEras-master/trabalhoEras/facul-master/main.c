#include <stdio.h>
#include <string.h>  // Para usar strcpy
#include "listaencadeada.h"
#include <string.h>


int main() {

        //    listaEras* lista_eras=(listaEras*)
//            calloc(1, (sizeof(lista_eras)));
//    lista_eras-> inicio = NULL;
//    Era *era;
//    strcpy(era->nome, "Periodo cretaceo");
//    era->limitePassageiros=5;
//    addInicio(lista_eras,*era);
//    Imprimir(lista_eras);
        int escolha;
    
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
    
        switch (escolha) {
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
                printf("Digite novamente: ");
                scanf("%d", &escolha);
                // Você pode querer repetir o switch ou usar um loop para continuar pedindo a escolha até que seja válida
                break;
        }
    
        return 0;
    }
