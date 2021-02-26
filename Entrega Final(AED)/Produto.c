#include"Produto.h"

void inicializar_lista_produto(lista_produto *l){
	
	l->inicio = NULL;
}


void adcionar_produto_inicio(lista_produto *l, produto p){
	
	no_produto *novo =  (no_produto *) malloc (sizeof(no_produto));
	novo->proximo = l->inicio;
	novo->dado = p;
	l->inicio = novo;

}

produto ler_produto(lista_produto *l){
	
	produto *p = (produto *) malloc (sizeof(produto));
	__fpurge(stdin);

	int codProduto;
	produto *temp = NULL;

	do{

		printf("Digite o codigo do produto: \n");
		scanf("%d", &codProduto);
		__fpurge(stdin);

		temp = localizar_idproduto_simple(l, codProduto);

		if (temp!=NULL){

			printf("\n\n ID JA CADASTRADO \n\n" );

		}

	}while (temp!=NULL);


	p->IDproduto = codProduto;

	printf("Digite o nome do produto: \n");
	fgets(p->nome_produto, sizeof(p->nome_produto), stdin);

	__fpurge(stdin);
	printf("Digite o valor do produto: \n");
	scanf("%f", &p->preco);

	return *p;

}


void salvar_produto(lista_produto *l){

	FILE *fp;
	fp = (FILE *) fopen("produto.txt", "wb");
	if(fp != NULL){
		no_produto *temp;
		temp = l->inicio;
		while(temp != NULL){
			fwrite(&temp->dado, sizeof(produto), 1, fp);
			temp = temp->proximo;
		}
		fclose(fp);

	}
}




void listar_produto(lista_produto *l){

	no_produto *temp;
	temp = l->inicio;
	printf("---------------Lista de produtos------------\n");
	while(temp != NULL){
		//printf("%d\n%s\n%s\n%d\n", temp->dado.IDproduto, temp->dado.nome, temp->dado.endereco, temp->dado.telefone);
		printf("\nIdentificao do produto: %d\n", temp->dado.IDproduto);
		printf("\nNome: %s", temp->dado.nome_produto);
		printf("\nPreco: %f\n", temp->dado.preco);
		temp = temp->proximo;

	}

	printf("-----------------------------------------------\n");
	system("read b");

}

void booblesort(lista_produto *l, int tamanho){
    
    int i, j;
    
    int trocou;

    no_produto *temp;

    for(j = 0; j < tamanho; j++){

		temp = l->inicio;

        for(i = 0; i < tamanho-1; i++){
            if((temp->proximo->dado.IDproduto < temp->dado.IDproduto) && temp!=NULL){

            	produto produto = temp->dado;
            	temp->dado = temp->proximo->dado;
            	temp->proximo->dado = produto;

            }

            	temp = temp->proximo;
                trocou = 1;
        }

        

         if(!trocou)
         break;

 	}

 		printf("\n ORDENACAO TERMINADA \n");
 		system("read b");

}

void carregar_produtos(lista_produto *l){

	FILE *fp;
	produto *dado;
	dado = (produto *) malloc(sizeof(produto));

	inicializar_lista_produto(l);

	fp = (FILE *) fopen("produto.txt", "rb");
	if(fp != NULL){

		while(fread(dado, sizeof(produto), 1, fp)){

			adcionar_produto_inicio(l, *dado);
			dado = (produto *) malloc(sizeof(produto));
		}
		fclose(fp);
	}

}


produto* localizar_idproduto(lista_produto*l, int ID) {
	produto *c = NULL;
	no_produto *temp;
	temp = l->inicio;
	int Id;
	printf("Digite o ID de Produto que deseja pesquisar: \n");
	scanf("%d", &Id);

	while(temp != NULL) {
		if(temp->dado.IDproduto == Id) {
			c = &temp->dado;
			break;
		}
		temp = temp->proximo;
	}

	if (c!=NULL){

	printf("-----------------------------------------------\n");
	
		printf("\nIdentificao do produto: %d\n", c->IDproduto);
		printf("\nNome: %s", c->nome_produto);
		printf("\nPreco: %f\n", c->preco);
	
	printf("-----------------------------------------------\n");
	
	}else{

	printf("\n PRODUTO NAO ECONTRADO! \n");

	}

	system("read b");

	return c;
}

produto* localizar_idproduto_simple(lista_produto*l, int Id) {
	produto *c = NULL;
	no_produto *temp;
	temp = l->inicio;

	while(temp != NULL) {
		if(temp->dado.IDproduto == Id) {
			c = &temp->dado;
			break;
		}
		temp = temp->proximo;
	}

	return c;
}

void excluir_produto(lista_produto *l){

	no_produto *temp, *retorno;
	temp = l->inicio;

	int Id;
	printf("Digite o ID do Produto que deseja excluir: \n");
	scanf("%d", &Id);

	if (temp->proximo == NULL){

		l->inicio = NULL;

	}else{
		while (temp != NULL && temp->dado.IDproduto != Id) {
		
		    retorno = temp;
		    temp = temp->proximo;
		
		}
		if (temp != NULL) {
		
		    retorno->proximo = temp->proximo;
		    free (temp);
		
		}
	}


	printf("-----------------------------------------------\n");
	printf("-------------------REMOVIDO--------------------\n");
	printf("-----------------------------------------------\n");
	system("read b");

}