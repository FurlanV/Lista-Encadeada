/* 
 * File:   TADListaLinear.h
 * Author: vinicius Furlan
 *
 * Created on September 3, 2015, 4:17 AM
 */


typedef struct{
    int id;
}Titem;

typedef struct{
    Titem item;
    struct TCelula *prox;
}TCelula;

typedef struct{
    TCelula *primeiro;
    TCelula *ultimo;
    int tamanhoLista;
}TLista;

TCelula *alocaCelula();
int listaVazia(TLista *lista);
void inicializa(TLista *lista);
void inserirFim(TLista *lista,Titem *item);
void inserirInicio(TLista *lista,Titem *item);
void inserir(TLista *lista,Titem *item);
void remover(TLista *lista,Titem *item);
void removerInicio(TLista *lista,Titem *item);
void removerFim(TLista *lista, Titem *item);
void imprimir(TLista *lista);
void moveMenor(TLista *lista);
void removeItem(TLista *lista,Titem *item, int posicao);
void inverte(TLista *lista);
void copia(TLista *lista1,TLista *lista2);
void concatena(TLista *lista,TLista *lista2);

