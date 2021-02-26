#ifndef _ITEM_H
#define _ITEM_H

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>


typedef struct item{
	int IDItem;
	int Qtd_produto;
	int Id_produto;
}item;

typedef struct no_item{
	item dado;
	struct no_item *proximo;
}no_item;

typedef struct lista_item {
	no_item *inicio;
} lista_item;

void inicializar_lista_item(lista_item *l);

void adcionar_item_inicio(lista_item *l, item i);

item ler_item(int Id_pro);




#endif

