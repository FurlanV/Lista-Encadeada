#include <stdlib.h>
#include <stdio.h>
#include "TADListaLinear.h"

/* aloca memoria para a celula cabeça (lista->primeiro)
   apontamos para o proximo elemento (NULL) 
   tamanho da lista é setado para "0"*/
void inicializa(TLista *lista)
{
    
    lista->primeiro = alocaCelula();    
    lista->primeiro->prox = NULL;      
    lista->ultimo = lista->primeiro;    
    lista->tamanhoLista = 0;          
}

/*Se a lista esta vazia (tamanhoLista = 0) 
  retorna 1 caso contrario retorna 0*/
int listaVazia(TLista *lista)
{
    if(lista->tamanhoLista == 0)  
                                    
        return 1;
    else
        return 0;          
}

void imprimir(TLista *lista)
{       
    printf("\n");
    
    if(listaVazia(lista)){
        printf("Lista vazia\n");
    }
    
    int i;
    int tamanhoLista;
    TCelula *pCelulaAtual; 
    
    tamanhoLista = lista->tamanhoLista;
    pCelulaAtual = lista->primeiro->prox;
    
    
    /*Enquanto a Celula atual não é NULL 
      imprime o item da celula. 
     celula atual recebe o proximo elemento da lista*/    
    printf("Lista: ");
    while(pCelulaAtual != NULL){
        printf("%5d ",pCelulaAtual->item.id);
        pCelulaAtual = pCelulaAtual->prox;
    }
    
    printf("\n        ");
    
    for(i=0; i<tamanhoLista; i++)
        printf("   ^  ");
    
    \\\printf("\nOrdem: ");
    for(i=0; i<tamanhoLista; i++)
        printf("%5d ",i+1);
    
    printf("\n\n");
}

void removeItem(TLista *lista,Titem *item, int posicao)
{
    int i;
    TCelula *pTempCelula,*pCelulaAtual,*pCelulaAnterior;
    
    if(listaVazia(lista)){ /*Se o tamanho da lista é "0", uma mensagem é exibida*/
        printf("A lista ja esta vazia !\n");
    }
    else{   /*Se não percorremos até a posição passada por argumento e liberamos a celula*/
        
        pCelulaAtual = lista->primeiro->prox;
        
        /*Percorre a lista até a posição passado por argumento*/
        for(i=0;i<posicao;i++){
            pCelulaAnterior = pCelulaAtual;
            pCelulaAtual = pCelulaAtual->prox;
        }
        
        /*A Celula temporario recebe a celula atual.
          A Celula anterior agora aponta para o proximo elemento
          O tamanho da lista é decrementado e a celula temporaria é liberada*/
        pTempCelula = pCelulaAtual;
        pCelulaAnterior->prox = pTempCelula->prox;
        lista->tamanhoLista--;
        
        free(pTempCelula);
    }      
}

void remover(TLista *lista,Titem *item)
{
    int i,posicao;
    TCelula *pTempCelula,*pCelulaAtual,*pCelulaAnterior;
    
    if(listaVazia(lista)){ /*Se o tamanho da lista é "0", uma mensagem é exibida*/
        printf("A lista ja esta vazia !\n");
        exit(1);
    }
    else{
        
        printf("Qual posicao [de 1 ate %d] voce deseja remover ?\n",lista->tamanhoLista);
        scanf("%d",&posicao);
        
        pCelulaAtual = lista->primeiro;
        
        for(i=0;i<posicao;i++){
            pCelulaAnterior = pCelulaAtual;
            pCelulaAtual = pCelulaAtual->prox;
        }
        
        pTempCelula = pCelulaAtual;
        pCelulaAnterior->prox = pTempCelula->prox;
        lista->tamanhoLista--;
        
        free(pTempCelula);
    }
        
}

void removerInicio(TLista *lista, Titem *item)
{
    TCelula *pTempCelula;
    
    if(lista->primeiro->prox == NULL){
        printf("A lista ja esta vazia!\n");
    }
    else{
        
        pTempCelula = lista->primeiro->prox;
        *item = pTempCelula->item;
        lista->primeiro->prox = pTempCelula->prox;
        lista->tamanhoLista--;
        
        free(pTempCelula);
    }       
    
    
}

void removerFim(TLista *lista, Titem *item)
{    
    if(lista->ultimo == lista->primeiro)
        printf("A lista ja esta vazia !\n");
    else{
        
        TCelula *pTempCelula,*pCelulaAnterior;        
        
        pTempCelula = lista->primeiro->prox;
        
        while(pTempCelula != lista->ultimo){
            pCelulaAnterior = pTempCelula;
            pTempCelula = pTempCelula->prox;
        }
      
        *item = lista->ultimo->item;
        free(lista->ultimo);
        
        lista->ultimo = pCelulaAnterior;
        lista->ultimo->prox = NULL;
        lista->tamanhoLista--;
    }    
}

void inserirFim(TLista *lista,Titem *item)
{  
   if(listaVazia(lista))
       inserirInicio(lista,item);
   else{   
        TCelula *pNovaCelula = alocaCelula();
    
        lista->ultimo->prox = pNovaCelula;
        lista->ultimo = pNovaCelula;
    
        pNovaCelula->item = *item;
        pNovaCelula->prox = NULL;   
    
        lista->tamanhoLista++;
   }
}

void inserirInicio(TLista *lista,Titem *item)
{
    
    TCelula *novo = alocaCelula();             
    novo->prox = lista->primeiro->prox;
    novo->item = *item;
    lista->primeiro->prox = novo;
    
    if(listaVazia(lista)){
        lista->ultimo = lista->primeiro->prox;
        lista->ultimo->prox = NULL;
    }    
    lista->tamanhoLista++;
}

TCelula *alocaCelula()
{
    TCelula *novaCelula = (TCelula*)malloc(sizeof(TCelula));
 
    if(novaCelula ==  NULL){
        printf("Erro ao alocar a celula\n");
        exit(1);
    }
    else
        return novaCelula;
}

void inserir(TLista *lista,Titem *item)
{   
    int posicao,i;
    TCelula *pCelulaAtual,*pCelulaAnterior;
    
    
    //Se a lista estiver vazia, o item é inserido na primeira posicao
    if(lista->tamanhoLista == 0){
        printf("o item foi inserido na primeira posicao da lista\n");
        inserirInicio(lista,item);
    }
    else{
        //Se não perguntamos ao usuario em qual posicao o item sera inserido
        printf("Em que posicao [de 1 ate %d] voce deseja inserir ?\n",lista->tamanhoLista);
        scanf("%d",&posicao);
 
        while(posicao > lista->tamanhoLista){
            printf("Digite uma posicao [de 1 ate %d]\n",lista->tamanhoLista);
            scanf("%d",&posicao);
        }
        
        //Caso o usuario tenha digitado uma posicao valida
        //pCelulaAtual aponta para a cabeça da lista e é alocado uma nova celula 'novaCelula'
        pCelulaAtual = lista->primeiro;
        TCelula *novaCelula = alocaCelula();
        
        for(i=0;i<posicao;i++){
            pCelulaAnterior = pCelulaAtual;
            pCelulaAtual = pCelulaAtual->prox;
        }
        
        novaCelula->item = *item;
        novaCelula->prox = pCelulaAtual;
        pCelulaAnterior->prox = novaCelula;
        lista->tamanhoLista++;
    }
        
}

void pesquisar(TLista *lista)
{
    int elemento,i;
    TCelula *pCelulaAtual;
    
    pCelulaAtual = lista->primeiro;
    
    /*Usuário digita o numero do elemento que deseja procurar*/
    printf("Digite o elemento [de 1 a %d] que voce deseja pesquisar:\n",lista->tamanhoLista);
    scanf("%d",&elemento);
   
    /*Percorre a lista até o elemento N fornecido pelo usuario*/
    for(i=0; i<elemento; i++){
        pCelulaAtual = pCelulaAtual->prox;
    }
    
    /*Se a celula atual é diferente de NULL a função imprime 
      o elemento N fornecido pelo usuario
      caso contrario é exibido uma mensagem*/
    if(pCelulaAtual == NULL)
        printf("Elemento nao encontrado !\n");
    else{
        system("clear");
        printf("elemento %d\n",elemento);
        printf("id: %d\n",pCelulaAtual->item.id);
    }
    
}

void moveMenor(TLista *lista)
{
    int posicao=1,menorPosicao=1;
    
    Titem menorItem,*item;
    TCelula *pCelulaAtual,*pCelulaAnterior,*pCelulaAux;
    
    pCelulaAtual = lista->primeiro->prox;
    menorItem.id = pCelulaAtual->item.id;
    
    /*Percorre a Lista e procura a posição e o menor item
     da lista*/
    while(pCelulaAtual->prox != NULL){
        
        if(menorItem.id > pCelulaAtual->item.id){
            menorItem.id = pCelulaAtual->item.id;
            pCelulaAux = pCelulaAtual;
            menorPosicao = posicao;
        }
        
        pCelulaAtual = pCelulaAtual->prox;
        posicao++;
    }
    
    /*Quando o item e a posicao é encontrado
      a função inserirInicio() é usada para colocar o
      item na primeira posição e a função removeItem() é utilizada
      para remover o menor elemento na posicao guardada*/
    if(pCelulaAtual != NULL){
        inserirInicio(lista,&menorItem);
        removeItem(lista,item,menorPosicao);
    }
}

void copia(TLista *lista1,TLista *lista2)
{    
    
    int i;
    TCelula *pCelulaLista1,*pCelulaLista2;
    
    pCelulaLista1 = lista1->primeiro->prox; 
    pCelulaLista2 = lista2->primeiro->prox;
    lista2->tamanhoLista = lista1->tamanhoLista;
    
    /*Percorre a lista1 e copia o ID do item para o item da lista 2
     fazendo uma copia da lista 1*/
    while(pCelulaLista1->prox != NULL){
        pCelulaLista2->item.id = pCelulaLista1->item.id;
        pCelulaLista1 = pCelulaLista1->prox;
        pCelulaLista2 = pCelulaLista2->prox;
    }
    
}

void concatena(TLista *lista,TLista *lista2)
{
    int i,tamanho,tamanho2;
    TCelula *pCelulaLista1,*pCelulaLista2;
    
    imprimir(lista);
    imprimir(lista2);
    
    if(lista != NULL && lista2 != NULL){
        
        tamanho = lista->tamanhoLista;
        tamanho2 = lista2->tamanhoLista; 
        
        pCelulaLista1 = lista->primeiro;
        pCelulaLista2 = lista2->primeiro;
        
        printf("tamanho: %d\n",tamanho);
        printf("tamanho2: %d\n",lista2->tamanhoLista);
        
        while(pCelulaLista1->prox != NULL){
            pCelulaLista1 = pCelulaLista1->prox;
        }
    
        pCelulaLista1->prox = pCelulaLista2->prox;
        lista->ultimo = lista2->ultimo;
        lista->tamanhoLista = (tamanho + tamanho2);
    }
    else
        printf("Erro\n");
}

void troca(TLista *lista,int nCelula)
{
    int tamanho,i;
    TCelula *pCelulaAtual,*pCelulaAnterior,*pCelulaAux;
    
    pCelulaAtual = lista->primeiro;
    tamanho = lista->tamanhoLista;
    
    for(i=1;i<=nCelula;i++){
        pCelulaAnterior = pCelulaAtual;
        pCelulaAtual = pCelulaAtual->prox;
    }
    
    pCelulaAnterior->prox = pCelulaAtual->prox;
    pCelulaAnterior->prox = pCelulaAtual;
}

void inverte(TLista *lista)
{
    int i,tamanho;
    TCelula *pCelulaAtual,*pCelulaAnterior,*pCelulaAux;
    
    pCelulaAux = lista->primeiro;
    pCelulaAtual = lista->primeiro;
    tamanho = lista->tamanhoLista;   
            
    while(tamanho > 1){
        
        /*celula aux percorre até o ultimo elemento definido pela
          variavel tamanho que é decrementada a cada passada do while
          para que a celula anterior a ultima seja trocada de posição*/
        for(i=1;i<=tamanho;i++){
            pCelulaAnterior = pCelulaAux;
            pCelulaAux = pCelulaAux->prox;
        }
        
        /*Se celula aux é diferente de NULL
          o ultimo elemento (pCelulaAux)
          troca de lugar com o primeiro elemento (pCelulaAtual)
          A celula anterior a ultima agora aponta para NULL*/        
        if(pCelulaAux != NULL){
            pCelulaAux->prox = pCelulaAtual->prox;  /*Ultimo elemento agora é igual ao primeiro*/
            pCelulaAtual->prox = pCelulaAux;    
            pCelulaAnterior->prox = NULL;
        }
        else
            printf("Erro !\n");
        
        pCelulaAtual = pCelulaAtual->prox; /*Celula atual recebe a proxima celula*/
        
        tamanho--;/*Tamanho é decrementado para que a ultima posição da lista -1 seja acessada na proxima passada*/
    }
    
    for(i=1;i<=tamanho;i++){ /*Percorremos até a ultima celula*/
        pCelulaAtual = pCelulaAtual->prox;
    }
    
    lista->ultimo = pCelulaAtual; /*lista->ultimo é igual a ultima celula encontrada*/
}

