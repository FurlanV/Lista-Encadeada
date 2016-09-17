#include<stdlib.h>
#include <stdio.h>
#include "TADListaLinear.h"
#include "Menu.h"

int opcoes()
{
    int opc;
    
    printf("\n0. Sair\n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no fim\n");
    printf("3. Escolher onde inserir\n");
    printf("4. Remover primeiro elemento\n");
    printf("5. Remover ultimo elemento\n");
    printf("6. Escolher onde remover\n");
    printf("7. Pesquisar elemento\n");
    printf("8. Mover o menor item da lista\n");
    printf("9. Copiar elementos da lista 1 para lista 2\n");
    printf("10. Inverter lista\n");
    printf("11. Imprimir lista\n");
    printf("Opcao: ");scanf("%d",&opc);
    
    return opc;
}

void itemMenu(int opcMenu,TLista *lista,TLista *lista2,Titem *item)
{    
    int opcLista;
    if(opcMenu != 4 && opcMenu != 5 && opcMenu != 6 && opcMenu != 7 && opcMenu != 8 && opcMenu != 9 && opcMenu != 10){
        printf("ID:\n");
        scanf("%d",&(item->id));
    }
    
    switch(opcMenu){
        case 0:
            exit(1);
            break;
        case 1:         
            inserirInicio(lista,item);
            break;
        case 2:
            inserirFim(lista,item);
            break;
        case 3:
            inserir(lista,item);
            break;
        case 4:            
            removerInicio(lista,item);
            break;
        case 5:            
            removerFim(lista,item);
            break;
        case 6:
            remover(lista,item);
            break;
        case 7:
            pesquisar(lista);
            break;
        case 8:
            moveMenor(lista);
            break;
        case 9:
            copia(lista,lista2);
            printf("Lista copiada com sucesso !\n"); 
            imprimir(lista);
            imprimir(lista2);                       
            break;
        case 10:
            system("clear");
            printf("\nLista original:\n");
            imprimir(lista);
            printf("Lista invertida\n");
            inverte(lista);
            imprimir(lista);
            break;
        case 11:
                imprimir(lista);       
            break;
        default:
            printf("Opcao Invalida !\n");
            break;                       
    }
}

void menu(TLista *lista,TLista *lista2,Titem *item)
{
    int opcMenu,nElementos,i; 
    
    printf("0. Sair\n");
    printf("1. Iniciar lista manualmente\n");
    printf("2. Iniciar lista automatica\n");
    printf("Opcao: ");scanf("%d",&opcMenu);
    
    while(opcMenu < 0 || opcMenu > 2){
        printf("0. Sair\n");
        printf("1. Iniciar lista manualmente\n");
        printf("2. Iniciar lista automatica\n");
        printf("Opcao: ");scanf("%d",&opcMenu);
    }
    
    switch(opcMenu){
        case 1:
            
            opcMenu = opcoes();
            
            while(opcMenu != 0){
                itemMenu(opcMenu,lista,lista2,item);
                opcMenu = opcoes();
            }
           
            break;
        case 2:
            
            if(lista->tamanhoLista == 0){
                printf("Digite o numero de elementos\n");
                scanf("%d",&nElementos);
            
                for(i=0; i<nElementos; i++){
                    item->id = (rand()%217);
                    inserirInicio(lista,item);
                }
            }
            
            opcMenu = opcoes();
            
            while(opcMenu != 0){
                itemMenu(opcMenu,lista,lista2,item);
                opcMenu = opcoes();
            }
    }
}

