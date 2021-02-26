#include "Pedido.h"
#include "Item.h"
#include "Cliente.h"

void inicializar_lista_pedido(lista_pedido *l){
	
	l->inicio = NULL;
}


void adcionar_pedido_inicio(lista_pedido *l, pedido p){

	no_pedido *novo =  (no_pedido *) malloc (sizeof(no_pedido));
	novo->proximo = l->inicio;
	novo->dado = p;
	l->inicio = novo;

}

pedido ler_pedido(lista_produto *lp, lista_cliente* lc){
	
	pedido *p = (pedido *) malloc (sizeof(pedido));
	__fpurge(stdin);

	float valor_total = 0;

	printf("\nAdicionar o ID do Pedido: ");
	scanf("%d", &p->IDpedido);
	__fpurge(stdin);

	printf("Digite a data do pedido: \n");
	fgets(p->DATAAAA, sizeof(p->DATAAAA), stdin);

	cliente *c = (cliente *) malloc (sizeof(cliente));

	do{

	c = localizar_idcliente(lc,-1);

	}while(c==NULL);

	if (c!=NULL){

		p->IDcliente = c->IDcliente;

		printf("\nDigite -1 para para a insercao de produtos\n");

			int sair = 0;

			do {

				produto *produto = NULL;

				do{
				
				produto	 = localizar_idproduto(lp, -1);

				}while (produto==NULL);

				if (produto!=NULL){

					adcionar_item_inicio(&p->itens, ler_item(produto->IDproduto));

				}

				lista_item li = p->itens; 

				no_item *temp_item;
				temp_item = li.inicio;

				while(temp_item != NULL){

					produto = localizar_idproduto_simple(lp, temp_item->dado.Id_produto);
					valor_total+=produto->preco*temp_item->dado.Qtd_produto;
					temp_item = temp_item->proximo;

				}

				p->precototal = valor_total;

					printf("\nAdicionar outro item? Digite 0 para continuar ou -1 para sair: ");
					scanf("%d", &sair);
					__fpurge(stdin);

			}while(sair!=-1);

		


	}else{

		printf("\nCliente nao encontrado!");

	}

	return *p;

}



void listar_pedido(lista_pedido *l, lista_produto *lp){

	no_pedido *temp;
	temp = l->inicio;
	printf("---------------Lista de pedidos------------\n");

	while(temp != NULL){

		printf("\nId do Pedido: %d\n", temp->dado.IDpedido);
		printf("\nId do Cliente: %d\n", temp->dado.IDcliente);
		printf("\nData do Pedido: %s\n", temp->dado.DATAAAA);

		lista_item li = temp->dado.itens; 

		no_item *temp_item;
		temp_item = li.inicio;

		while(temp_item != NULL){

			printf("\n->Id do Item: %d | Quantidade: %d ", temp_item->dado.IDItem, temp_item->dado.Qtd_produto);
			produto *produto = localizar_idproduto_simple(lp, temp_item->dado.Id_produto);
			printf(" |Id do Produto %d | Valor Parcial: %.2f \n", produto->IDproduto,produto->preco*temp_item->dado.Qtd_produto);
			temp_item = temp_item->proximo;

		}	

		printf("\nPreco total do pedido: %.2f\n", temp->dado.precototal);

		temp = temp->proximo;

	}

	printf("-----------------------------------------------\n");
	system("read b");

}

void salvar_pedido(lista_pedido *l){

	FILE *fp;
	fp = (FILE *) fopen("pedido.txt", "wb");
	if(fp != NULL){
		no_pedido *temp;
		temp = l->inicio;
		while(temp != NULL){
			fwrite(&temp->dado, sizeof(pedido), 1, fp);
			temp = temp->proximo;
		}
		fclose(fp);

	}
}

void carregar_itens_pedido(lista_pedido *l){

	FILE *fp;
	pedido *dado;
	dado = (pedido *) malloc(sizeof(pedido));

	inicializar_lista_pedido(l);

	fp = (FILE *) fopen("pedido.txt", "rb");
	if(fp != NULL){

		while(fread(dado, sizeof(pedido), 1, fp)){

			adcionar_pedido_inicio(l, *dado);
			dado = (pedido *) malloc(sizeof(pedido));
		}
		fclose(fp);
	}

}
