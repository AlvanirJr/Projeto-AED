#ifndef _PEDIDO_H
#define _PEDIDO_H

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "Item.h"
#include "Produto.h"
#include "Cliente.h"

typedef struct pedido{
	int IDpedido;
	int IDcliente;
	float precototal;
	lista_item itens;
	
	char DATAAAA[10];
}pedido;

 typedef struct no_pedido{
 	pedido dado;
 	struct no_pedido *proximo;
 	
 }no_pedido;

 typedef struct lista_pedido{
	no_pedido *inicio;
} lista_pedido;

#include "Pedido.h"


void inicializar_lista_pedido(lista_pedido *l);

void adcionar_pedido_inicio(lista_pedido *l, pedido p);

pedido ler_pedido(lista_produto *lp, lista_cliente* cliente);

void listar_pedido(lista_pedido *l, lista_produto *lp);

void salvar_pedido(lista_pedido *l);

void carregar_itens_pedido(lista_pedido *l);


#endif
