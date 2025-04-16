#ifndef LISTAENCADEADA_H
 #define LISTAENCADEADA_H
 
 typedef struct _era {
     char nome[50];
     int limitePassageiros;
 } Era;
 
 typedef struct _no_embarcado {
     char nome[50];
     struct _no_embarcado *proximo;
     struct _no_embarcado *anterior;
 } noEmbarcado;
 
 typedef struct _no_espera {
     char nome[50];
     struct _no_espera *proximo;
 } noEspera;
 
 typedef struct _no_era {
     Era valor;
     struct _no_era *proximo;
 } noEra;
 
 typedef struct _lista_simplesmente_encadeada {
     noEspera *inicio;
 } listaEspera;
 
 typedef struct _lista_duplamente_encadeada {
     noEmbarcado *inicio;
     noEmbarcado *fim;
     int tamanho;
 } listaEmbarcado;
 
 typedef struct _lista_eras {
     noEra *inicio;
 } listaEras;
 
 // Funções
 listaEmbarcado *criarListaEmbarcado() ;
 listaEspera *criarListaEspera();
 listaEras *criarListaEras();
 
 void addEmbarcado(listaEmbarcado *lista, char nome[]);
 void addFinalEspera(listaEspera *lista, char nome[]);
 
 void embarcarPrimeiroEspera(listaEmbarcado*listaEmbarcado, listaEspera*listaEspera);
 void embarcarUltimoEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera);
 
 
 void adicionarPrimeiroEmbarcadoNaEra(listaEras *listaEras, listaEmbarcado *listaEmbarcado);
 void embarcarUltimoEspera(listaEmbarcado *listaEmbarcado, listaEspera *listaEspera);
 void adicionarUltimoEmbarcadoNaEra(listaEras *eras, listaEmbarcado *embarcados);
 
 void ImprimirEmbarcados(const listaEmbarcado *lista);
 void ImprimirEspera(const listaEspera *lista);
 void ImprimirEras(const listaEras *lista);

 void adicionarEra(listaEras *lista, char nome[]) ;

 void selecionarEra(listaEras *eras, int escolhaEra);
 void imprimirErasComLimite(const listaEras *lista);

 int temEspacoNasEras(listaEras *eras);
 
 #endif