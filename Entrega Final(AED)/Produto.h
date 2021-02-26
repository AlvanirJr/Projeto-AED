#ifndef _PRODUTO_H
#define _PRODUTO_H

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>


typedef struct produto{
	char nome_produto[50];
	int IDproduto;
	float preco;
	
}produto;
 typedef struct no_produto{
 	produto dado;
 	struct no_produto *proximo;
 }no_produto;


typedef struct lista_produto {
	no_produto *inicio;
} lista_produto;

produto ler_produto(lista_produto *l);

void inicializar_lista_produto(lista_produto *l);
void adcionar_produto_inicio(lista_produto *l, produto p);
void listar_produto(lista_produto *l);
void salvar_produto(lista_produto *l);
void carregar_produtos(lista_produto *l);
void booblesort(lista_produto *l, int tamanho);


produto* localizar_idproduto(lista_produto*l, int ID);
produto* localizar_idproduto_simple(lista_produto*l, int ID);
void excluir_produto(lista_produto *l);

#endif
