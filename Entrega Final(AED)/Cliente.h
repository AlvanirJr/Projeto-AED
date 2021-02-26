#ifndef _CLIENTE_H
#define _CLIENTE_H

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>


typedef struct cliente {
	char nome[30];
	char endereco[50];
	char telefone[20];
	int IDcliente;

}cliente;

typedef struct no_cliente{
	cliente dado;
	struct  no_cliente *proximo;

}no_cliente;


typedef struct lista_cliente {
	no_cliente *inicio;
} lista_cliente;


cliente ler_cliente(lista_cliente *l);
cliente* localizar_idcliente(lista_cliente*l, int ID);

void inicializar_lista_cliente(lista_cliente *l);
void adcionar_cliente_inicio(lista_cliente *l, cliente c);
void listar_cliente(lista_cliente *l);
void salvar_cliente(lista_cliente *l);
void carregar_clientes(lista_cliente *l);
void excluir_cliente(lista_cliente *l);
cliente* localizar_idcliente_simple(lista_cliente*l, int ID);
#endif
