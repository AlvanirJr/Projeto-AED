#include "telas.h"

int menu_principal() {
	int op;
	system("clear");
	printf("|--------------------------------------------|\n");
	printf("|                                            |\n");
	printf("|       ALVANIR VARIEDADES DE PRODUTOS       |\n");
	printf("|               EDICAO 1.0                   |\n");
	printf("|--------------------------------------------|\n");
	printf("\n");
	printf("1\tCadastar Clientes\n");
	printf("2\tCadastrar Produto\n");
	printf("3\tControle Pedido\n");
	printf("4\tSair\n");
	printf("\n_");
	
	scanf("%d", &op);
	return op;
}

int menu_cliente() {
	int op;
	system("clear");
	printf("|--------------------------------------------|\n");
	printf("|                                            |\n");
	printf("|           CADASTRO DE CLIENTES             |\n");
	printf("|                                            |\n");
	printf("|--------------------------------------------|\n");
	printf("\n");
	printf("1\tInserir Cliente\n");
	printf("2\tListar Clientes\n");
	printf("3\tVoltar para o menu principal\n");
	printf("4\tSalvar Arquivo dos Clientes\n");
	printf("5\tCarregar Arquivo dos Clientes\n");
	printf("6\tLocalizar por ID\n");
	printf("7\tRemover Cliente por ID\n");
	printf("\n_");
	
	scanf("%d", &op);
	return op;

}

int menu_pedido() {
	int op;
	system("clear");
	printf("|--------------------------------------------|\n");
	printf("|                                            |\n");
	printf("|           CADASTRO DE PEDIDO               |\n");
	printf("|                                            |\n");
	printf("|--------------------------------------------|\n");
	printf("\n");
	printf("1\tInserir Pedido\n");
	printf("2\tListar Pedidos\n");
	printf("3\tVoltar ao menu principal\n");
	printf("4\tSalvar Arquivo dos Pedidos\n");
	printf("5\tCarregar Arquivo dos Pedidos\n");
	printf("\n_");
	
	scanf("%d", &op);
	return op;

}

int menu_produto() {
	int op;
	system("clear");
	printf("|--------------------------------------------|\n");
	printf("|                                            |\n");
	printf("|           CADASTRO DE PRODUTOS             |\n");
	printf("|                                            |\n");
	printf("|--------------------------------------------|\n");
	printf("\n");
	printf("1\tInserir Produto\n");
	printf("2\tListar Produtos\n");
	printf("3\tVoltar para o menu principal\n");
	printf("4\tSalvar Dados dos Produtos\n");
	printf("5\tCarregar Dados dos Produtos\n");
	printf("6\tLocalizar Produto por ID\n");
	printf("7\tExcluir Produto por ID\n");
	printf("8\tOrdenar Produtos por ID\n");
	printf("\n_");
	
	scanf("%d", &op);
	return op;

}

