#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
	Reutilizei o trabalho da aula 7 onde
	tem aquele CRUD completo dos livros
	
	O método de busca binário não fazia muito
	sentido para pesquisar por livros (mais de um)
	filtrados pelo autor ou por quantia de páginas
	
	Então foi criada uma pesquisa de um único livro
	filtrado pelo nome (precisa match exato da busca)
	
	Criei uma opção a mais no menu para
	ordenação dos livros, tanto por
	nome quanto por quantia de páginas
	(A partir da linha 71)
*/


FILE *file;
int choice = 0;
int binarySearchBounds = 0;

enum OrderOptions{
		ALPHABETIC = 1, PAGES
};

struct Book{
	char title[100];
	char author[100];
	int pages;
};

/* 
	Funcoes auxiliares para reaproveitamento de codigo 
*/

/* Divisoria pra estetica no programa */
void header(char *text){
	printf("*** [%s] ***\n\n", text);
}

/* Auxiliar para imprimir livro */
void printBook(int id, struct Book book){
	printf("\n*** [%d] ***\n", id);
	printf("Título: %s\n", book.title);
	printf("Autor: %s\n", book.author);
	printf("Páginas: %d\n\n", book.pages);	
}

/*
	Funcoes principais
*/

/*Funcao para ordenar os livros por qtd. pagina*/
int getListSize(struct Book tmp){
	file = fopen("bookList.txt", "rb");
	int size;
	while (fread(&tmp, sizeof(tmp), 1, file)){
    	size++;
    }
    fclose(file);
    return size;
	
}

/*Função para ordenar os livros por página
  Ou ordem alfabética
*/
void orderBy(int option){
	struct Book tmp;
	file = fopen("bookList.txt", "rb");
	int size = 0;
	int i, j;
	size = getListSize(tmp);
    struct Book books[size];
    fseek(file, 0, SEEK_SET);
    i = 0;
    while(fread(&tmp, sizeof(tmp), 1, file)){
    	books[i] = tmp;	
    	i++;
	}
	i = 0;
	switch(option){
		case ALPHABETIC:
			/*Bubble sort usando strcmp*/
			for (i = 0; i < size; i++){
		    	for(j = i + 1; j < size; j++){
		    		if(strcmp(books[i].title, books[j].title) > 0){
		    			tmp = books[i];
		    			books[i] = books[j];
		    			books[j] = tmp;
					}
				}
			}
			break;
		case PAGES:
			/*Bubble sort comparando páginas*/
			for (i = 0; i < size; i++){
		    	for(j = i + 1; j < size; j++){
		    		if(books[i].pages < books[j].pages){
						tmp = books[i];
						books[i] = books[j];
						
					}
				}
			}
			break;
	}
	fclose(file);
	i = 0;
	file = fopen("bookList.txt", "wb");
	for(i = 0; i < size; i++){
		fwrite(&books[i], sizeof(tmp), 1, file);
	}
	fclose(file);
}

/* Funcao para registro de um livro novo */
void inscribe(){
	struct Book book;
	printf("\n");
	header("Cadastrar");
	printf("Qual é o nome do livro?\n");
	fflush(stdin);
	scanf("%[^\n]", book.title);
	printf("E qual(quais) é(são) o(s) autor(es) de '%s'\n", book.title);
	fflush(stdin);
	scanf("%[^\n]", book.author);
	printf("E quantas páginas tem '%s'\n", book.title);
	fflush(stdin);
	scanf("%d", &book.pages);
	file = fopen("bookList.txt", "ab");
	fwrite(&book, sizeof(book), 1, file);
	fclose(file);
}

/* Funcao para ver todos os livros */
void seeAll(){
	struct Book book;
	int i = 0;
	file = fopen("bookList.txt", "rb");
	int booksFound = 0;
	while(fread(&book, sizeof(book), 1, file)){
		i++;
		printBook(i, book); // Chamando funcao auxiliar
		booksFound = 1;
	}
	fclose(file);
	if(booksFound == 0){
		printf("Não encontramos nenhum livro.\n\n");
	}
}

/* Funcao para dar o inicio a selecao de indice */
void selectFromAll(char *context){
	header(context);
	printf("Dentre os livros: \n");
	seeAll();
	printf("O índice do livro está acima das informações, ex: *** [1] ***\n");
	printf("Este é o livro de índice 1.\n");
	printf("\n\nInforme um valor, indicando seu índice.\n");
}

/* Funcao para ver o livro por nome
   Feito com busca binária
 */
 
void byName(char *search, FILE *file, int e, int size){
	if(binarySearchBounds > size){
		printf("\n\nNão foi encontrado nenhum livro.\n\n");
		main(); /* De volta ao menu*/
	}
	struct Book book;
	int m;
	/* Agora realizando a busca binaria */
	m = (e + size) / 2;
	file = fopen("bookList.txt", "rb");
	fseek(file, m * sizeof(book), SEEK_SET);
	fread(&book, sizeof(book), 1, file);
	int str_cmp_result = strcmp(book.title, search);
	/* Com os livros ordenados alfabeticamente pode-se procurar binariamente*/
	if(str_cmp_result == 0){
		fclose(file);
		printBook(1, book);
		main(); /* Por algum motivo quando termina essa função não queria voltar ao menu */
	}else if(str_cmp_result < 0){
		binarySearchBounds++; /* Incremena um contador para o limite de busca ser 
								Igual ao tamanho do arquivo*/
		byName(search, file, m + 1, size);
	}else if(str_cmp_result > 0){
		byName(search, file, e, m - 1);
	}
	
}

/* Funcao para ver os livros por autor */
void byAuthor(){
	struct Book book;
	char search[100];
	printf("Vamos procurar pelo autor. \n");
	printf("(Deve ser escrito como foi cadastrado)\n");
	printf("\nInsira o nome do autor para busca: ");
	fflush(stdin);
	scanf("%[^\n]", search);
	printf("\n");
	int i = 0;
	int booksFound = 0; // Registrando se houve livros encontrados ou nao
	file = fopen("bookList.txt", "rb");
	while(fread(&book, sizeof(book), 1, file)){
		i++;
		if(strcmp(book.author, search) == 0){
			printBook(i, book);
			booksFound = 1;
		}
	}
	if(booksFound == 0){
		printf("Não encontramos nenhum livro com estes critérios.\n\n");
	}
	fclose(file);
}

/* Funcao para ver os livros por qtd. paginas */
void byPages(){
	struct Book book;
	int search, size;
	printf("Vamos procurar pela quantidade de páginas. \n");
	printf("\nInsira a quantidade: ");
	fflush(stdin);
	scanf("%d", &search);
	printf("\n");
	int i = 0;
	int booksFound = 0;
	file = fopen("bookList.txt", "rb");
	while(fread(&book, sizeof(book), 1, file)){
		i++;
		if(book.pages == search){
			printBook(i, book);
		}
	}
	if(booksFound == 0){
		printf("Não encontramos nenhum livro com estes critérios.\n\n");
	}
	fclose(file);
}

/* Submenu para escolha do tipo de busca */
void search(){
	header("Procurar");
	printf("Você deseja filtrar por: \n");
	printf("1- Qtd. Páginas\t\t2-Autor(es)\t3- Nome do livro\n");
	fflush(stdin);
	do{
		scanf("%d", &choice);
		switch(choice){
		case 1:
			byPages();
			break;
		case 2:
			byAuthor();
			break;
		case 3:
			printf("Digite o nome do livro: ");
			char title[100];
			fflush(stdin);
			scanf("%[^\n]", title);
			struct Book book;
			int size = getListSize(book);
			byName(title, file, 0, size - 1);
			break;
		default: 
			printf("\nInsira um valor válido.\n");
			break;
		}
	}while(choice != 1 && choice != 2);
	
}

/* Funcao para editar um livro */
void edit(){
	struct Book book;
	int i = 0;
	selectFromAll("Atualizar");
	fflush(stdin);
	scanf("%d", &i);
	file = fopen("bookList.txt", "rb+");
	fseek(file, sizeof(book)*(i-1), SEEK_SET);
	fread(&book, sizeof(book), 1, file);
	printf("Qual o novo nome de '%s'?\n", book.title);
	fflush(stdin);
	scanf("%[^\n]", book.title);
	printf("Qual o novo autor de '%s'?\n", book.title);
	fflush(stdin);
	scanf("%[^\n]", book.author);
	printf("Quantas páginas tem '%s'?\n", book.title);
	fflush(stdin);
	scanf("%d", &book.pages);
	fseek(file, sizeof(book)*(i-1), SEEK_SET);
	fwrite(&book, sizeof(book), 1, file);
	printf("Livro atualizado com sucesso!\n");
	fclose(file);
}

/* Funcao para deletar um livro */
void erase(){
	FILE *helper;
	struct Book book;
	int i = 0;
	selectFromAll("Apagar");
	fflush(stdin);
	scanf("%d", &i);
	file = fopen("bookList.txt", "rb");
	helper = fopen("helperList.txt", "wb");
	if(helper){
		int j = 1;
		while(fread(&book, sizeof(book), 1, file)){
			if(j != i){
				fwrite(&book, sizeof(book), 1, helper);
			}
			j++;
		}	
	}
	remove("bookList.txt");
	fclose(helper);
	file = fopen("bookList.txt", "wb");
	helper = fopen("helperList.txt", "rb");
	while(fread(&book, sizeof(book), 1, helper)){
		fwrite(&book, sizeof(book), 1, file);
	}
	printf("Livro apagado com sucesso.\n");
	remove("helperList.txt");
	fclose(file);
}

/* Funcao para ordenar os livros */
void order(){
	printf("Deseja ordenar por:\n");
	printf("1- Alfabética\t2- Qtd. Páginas\n");
	fflush(stdin);
	scanf("%d", &choice);
	if(choice == 1){
		orderBy(ALPHABETIC);
	}else{
		orderBy(PAGES);
	}
	printf("\n\n**** Ordenado com sucesso! ****\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	do{
		header("Minha Biblioteca");
		printf("\nBem vindo à biblioteca.\n");
		printf("O que deseja fazer?\n\n");
		printf("1- Cadastrar um livro.\n");
		printf("2- Ver todos os livros.\n");
		printf("3- Pesquisar um livro.\n");
		printf("4- Atualizar um livro.\n");
		printf("5- Apagar um livro.\n");
		printf("6 - Ordenar os livros\n");
		printf("7 - Sair\n\n");
		fflush(stdin);
		scanf("%d", &choice);
		switch(choice){
			case 1:
				inscribe();
				printf("\n\n");
				break;
			case 2:
				seeAll();
				printf("\n\n");
				break;
			case 3:
				search();
				printf("\n\n");
				break;
			case 4:
				edit();
				printf("\n\n");
				break;
			case 5:
				erase();
				printf("\n\n");
				break;
			case 6:
				order();
				break;
			case 7:
				printf("\n\n");
				header("Obrigado!");
				exit(0);
				break;
			default:
				printf("Insira um valor válido.\n\n");
				break;					
		}
	}while(choice != 7);
	
}
