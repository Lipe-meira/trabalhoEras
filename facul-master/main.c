#include <stdio.h>
#include <string.h>  // Para usar strcpy
#include "ListaEncadeada.h"
#include <string.h>
int main()
{
   listaEras* lista_eras=(listaEras*)
           calloc(1, (sizeof(lista_eras)));
   lista_eras-> inicio = NULL;
   Era *era;
   strcpy(era->nome, "Periodo cretaceo");
   era->limitePassageiros=5;
   addInicio(lista_eras,*era);
   Imprimir(lista_eras);

    return 0;
}
