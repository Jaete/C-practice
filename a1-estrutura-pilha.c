#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define PLATE_SIZE 7
#define GARAGE_SIZE 5

/*
	Integrantes do trabalho:
	- Victor Jaete Fontenele, RA 1230115795
*/

struct Stack {
	int top;
	char item[GARAGE_SIZE][PLATE_SIZE]; 
};

char letters_char[26] = {'A', 'B', 'C', 'D', 'E', 'F', 
'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

char numbers_char[10] = {'0', '1', '2', '3', '4', '5', 
'6', '7', '8', '9'};

char generate_number(){
	int random = rand() % (9 + 1 - 0) + 0;
	return numbers_char[random];
}

char generate_letter(){
	char letter;
	int rand_letter = rand() % (25 + 1 - 0) + 0;
	letter = letters_char[rand_letter];
	return letter;
}

void generate_plate(char *plate){
	int i;
	for (i = 0; i < PLATE_SIZE; i++){
		float is_letter = rand()%2;
		if (is_letter == 0){
			plate[i] = generate_letter();
		}else{
			plate[i] = generate_number();
		}		
	}
}

void get_current_plate(char *current_plate, struct Stack *garage, int ind){
	int j = PLATE_SIZE - 1;
	while(j >= 0){
		current_plate[j] = garage->item[ind][j];
		j--;
	}
}

void show_garage(struct Stack *garage){
	printf("\n\n***** [GARAGEM] *****\n\n");
	int i = garage->top;
	if (garage->top == -1){
		printf("Garagem vazia.\n");
	}
	while(i >= 0){
		char current_plate[PLATE_SIZE];
		get_current_plate(current_plate, garage, i);
		printf("Carro %d -> %s\n", i + 1, current_plate); 
		i--;
	}
	printf("\n\n");
}

void remove_car(int position, struct Stack *garage){
	struct Stack temp;
	temp.top = -1;
	if(garage->top == -1){
		printf("Garagem já está vazia.\n");
	}
	char current_plate[PLATE_SIZE];
	while(position < garage->top){
		get_current_plate(current_plate, garage, garage->top);
		printf("Carro %s manobrando para abrir caminho.\n", current_plate);
		temp.top++;
		strcpy(temp.item[temp.top], garage->item[garage->top]); 
		garage->item[garage->top--];
	}
	get_current_plate(current_plate, garage, garage->top);
	printf("Carro %s saindo do estacionamento.\n", current_plate);
	while(temp.top > -1){
		get_current_plate(current_plate, &temp, temp.top);
		printf("Carro %s retornando para a vaga.\n", current_plate);
		strcpy(garage->item[garage->top], temp.item[temp.top]);
		garage->top++;
		temp.item[temp.top--];
	}
	garage->top--;
}

void car_operation(char operation, struct Stack *garage){
	char car_plate[PLATE_SIZE];
	switch(operation){
		case 'E':
			if (garage->top == GARAGE_SIZE -1){
				printf("Não existe vaga disponível no estacionamento.\n");
				break;
			}
			generate_plate(car_plate);
			garage->top++;
			strcpy(garage->item[garage->top], car_plate);
			printf("\nCarro de placa %s acabou de entrar.\n", garage->item[garage->top]);
			break;
		case 'S':
			if(garage->top == -1){
				printf("O estacionamento já está vazio.");
				break;
			}
			printf("Qual dos carros irá sair?\n");
			printf("Selecione o numero correspondente.\n");
			show_garage(garage);
			int option, i;
			setbuf(stdin, NULL);
			scanf("%d", &option);
			option--;
			remove_car(option, garage);
			break;
		case 'V':
			show_garage(garage);
	}
}

int main(void){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	struct Stack garage;
	garage.top = -1;
	char option;
	do{
		printf("\n\n***** [MENU] *****\n\n");
		printf("Qual operação realizar?\n");
		printf("E - Entrada de carro.\n");
		printf("S - Saída de carro.\n");
		printf("V - Ver os carros na garagem.\n");
		printf("Q - Sair do sistema.\n");
		setbuf(stdin, NULL);
		scanf("%c", &option);
		option = toupper(option);
		if (option == 'Q'){
			printf("Saindo do sistema.\n");
			exit(0);
		}
		car_operation(option, &garage);
	}while(option == 'E' || option == 'S' || option == 'Q' || option == 'V');
	return 0;
}
