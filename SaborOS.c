#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//Arquivo de gerenciamento e persist�ncia de dados
FILE *registroVendas;

//Vari�vel de escolha para navega��o no menu
int escolha = 0;

// Pre�o da quentinha e pre�o por kg
enum PrecoRefeicao{
	QUILO = 30, // N�o foi explicitado nas especifica��es
	// do projeto o pre�o do KG da refei��o, valor aleat�rio
	QUENTINHA = 20
} refeicao;

//Pre�o das bebidas
enum Bebidas{
	COCA_LATA = 4, COCA_2L = 10,
	PEPSI_LATA = 3, PEPSI_2L = 8
} bebida;

//Meses do ano para Relat�rio Mensal
enum Meses{
	JANEIRO = 1, FEVEREIRO,
	MARCO, ABRIL,
	MAIO, JUNHO,
	JULHO, AGOSTO,
	SETEMBRO, OUTUBRO,
	NOVEMBRO, DEZEMBRO
} meses;

//struct de informa��o para cada venda realizada
struct Vendas{
	char tipo[16]; // "a quilo" ou "quentinha"
	int peso;
	int qtdBebidas;
	float precoFinal;
};


//Fun��es ajudantes para reutiliza��o de c�digo
void printVenda(int i, struct Vendas venda){
	printf("\n\n***** [%d] *****\n", i);
	printf("Tipo: %s\n", venda.tipo);
	printf("Peso: %d\n", venda.peso);
	printf("Qtd. Bebidas: %d\n", venda.qtdBebidas);
	printf("Pre�o: %.2f\n", venda.precoFinal);
}

void repetirEscolha(){
	fflush(stdin);
	printf("Insira um valor v�lido.\n");
	fscanf(stdin, "%d", &escolha);
}

void validarEscolha(int qtdOpcoes){
	switch(qtdOpcoes){
		case 2:
			while(escolha != 1 && escolha != 2){
				repetirEscolha();
			}	
			break;
		case 3:
			while(escolha != 1 && escolha != 2 && escolha != 3){
				repetirEscolha();
			}	
			break;
		case 4:
			while(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4){
				repetirEscolha();
			}	
			break;
	}	
}

void listaBebidas(){
	printf("\n\nDigite qual bebida foi vendida: \n");
	printf("1- Coca-Cola Latinha\n");
	printf("2- Coca-Cola 2 Litros\n");
	printf("3- Pepsi Latinha\n");
	printf("4- Pepsi 2 Litros\n");
}

void printDiaMes(int dia, int mes){
	switch(mes){
		case JANEIRO:
			printf("\n\n****** [%d / JANEIRO] ******\n\n", dia);
			break;
		case FEVEREIRO:
			printf("\n\n****** [%d / FEVEREIRO] ******\n\n", dia);
			break;
		case MARCO:
			printf("\n\n****** [%d / MAR�O] ******\n\n", dia);
			break;
		case ABRIL:
			printf("\n\n****** [%d / ABRIL] ******\n\n", dia);
			break;
		case MAIO:
			printf("\n\n****** [%d / MAIO] ******\n\n", dia);
			break;
		case JUNHO:
			printf("\n\n****** [%d / JUNHO] ******\n\n", dia);
			break;
		case JULHO:
			printf("\n\n****** [%d / JULHO] ******\n\n", dia);
			break;
		case AGOSTO:
			printf("\n\n****** [%d / AGOSTO] ******\n\n", dia);
			break;
		case SETEMBRO:
			printf("\n\n****** [%d / SETEMBRO] ******\n\n", dia);
			break;
		case OUTUBRO:
			printf("\n\n****** [%d / OUTUBRO] ******\n\n", dia);
			break;
		case NOVEMBRO:
			printf("\n\n****** [%d / NOVEMBRO] ******\n\n", dia);
			break;
		case DEZEMBRO:
			printf("\n\n****** [%d / DEZEMBRO] ******\n\n", dia);
			break;
	}
}

//Calculando o pre�o por peso, com o peso em gramas, fazendo a
//convers�o para quilos
float calcularPrecoPorPeso(int peso){
	return QUILO * (peso * 0.001);
}

//Adicionando os 50 centavos da embalagem ao pre�o fixo da quentinha
float quentinha(){
	return QUENTINHA + 0.5;
}

//Adicionando bebida a partir da escolha feita no input, pr� validado
int adicionarBebida(int bebida, int quantidade){
	switch(bebida){
		case 1:
			return COCA_LATA * quantidade;
			break;
		case 2:
			return COCA_2L * quantidade;
			break;
		case 3:
			return PEPSI_LATA * quantidade;
			break;
		case 4:
			return PEPSI_2L * quantidade;
			break;
		default:
			return 0;
	}
}

//Checando qual m�s � a partir do input recebido, pr� validado, para uso de escrita
void registrarMes(int mes){
	switch(mes){
		case JANEIRO:
			registroVendas = fopen("registroVendasJaneiro", "ab");
			break;
		case FEVEREIRO:
			registroVendas = fopen("registroVendasFevereiro", "ab");
			break;
		case MARCO:
			registroVendas = fopen("registroVendasMarco", "ab");
			break;
		case ABRIL:
			registroVendas = fopen("registroVendasAbril", "ab");
			break;
		case MAIO:
			registroVendas = fopen("registroVendasMaio", "ab");
			break;
		case JUNHO:
			registroVendas = fopen("registroVendasJunho", "ab");
			break;
		case JULHO:
			registroVendas = fopen("registroVendasJulho", "ab");
			break;
		case AGOSTO:
			registroVendas = fopen("registroVendasAgosto", "ab");
			break;
		case SETEMBRO:
			registroVendas = fopen("registroVendasSetembro", "ab");
			break;
		case OUTUBRO:
			registroVendas = fopen("registroVendasOutubro", "ab");
			break;
		case NOVEMBRO:
			registroVendas = fopen("registroVendasNovembro", "ab");
			break;
		case DEZEMBRO:
			registroVendas = fopen("registroVendasDezembro", "ab");
			break;
	}
}

//Checando qual m�s � a partir do input recebido, pr� validado, para uso de leitura
void analisarMes(int mes){
	switch(mes){
		case JANEIRO:
			registroVendas = fopen("registroVendasJaneiro", "rb");
			break;
		case FEVEREIRO:
			registroVendas = fopen("registroVendasFevereiro", "rb");
			break;
		case MARCO:
			registroVendas = fopen("registroVendasMarco", "rb");
			break;
		case ABRIL:
			registroVendas = fopen("registroVendasAbril", "rb");
			break;
		case MAIO:
			registroVendas = fopen("registroVendasMaio", "rb");
			break;
		case JUNHO:
			registroVendas = fopen("registroVendasJunho", "rb");
			break;
		case JULHO:
			registroVendas = fopen("registroVendasJulho", "rb");
			break;
		case AGOSTO:
			registroVendas = fopen("registroVendasAgosto", "rb");
			break;
		case SETEMBRO:
			registroVendas = fopen("registroVendasSetembro", "rb");
			break;
		case OUTUBRO:
			registroVendas = fopen("registroVendasOutubro", "rb");
			break;
		case NOVEMBRO:
			registroVendas = fopen("registroVendasNovembro", "rb");
			break;
		case DEZEMBRO:
			registroVendas = fopen("registroVendasDezembro", "rb");
			break;
	}
}

//Checando qual m�s � a partir do input recebido, pr� validado, para uso de print na tela
char *stringMes(int mes){
	switch(mes){
			case JANEIRO:
				return "[JANEIRO]";
			case FEVEREIRO:
				return "[FEVEREIRO]";
			case MARCO:
				return "[MAR�O]";
			case ABRIL:
				return "[ABRIL]";
			case MAIO:
				return "[MAIO]";
			case JUNHO:
				return "[JUNHO]";
			case JULHO:
				return "[JULHO]";
			case AGOSTO:
				return "[AGOSTO]";
			case SETEMBRO:
				return "[SETEMBRO]";
			case OUTUBRO:
				return "[OUTUBRO]";
			case NOVEMBRO:
				return "[NOVEMBRO]";
			case DEZEMBRO:
				return "[DEZEMBRO]";
		}
}

//Adicionando uma venda de refei��o manualmente, com o programa presumindo
//que � a refei��o � quilo.
void vendaRefeicaoManual(){
	struct Vendas venda;
	strcpy(venda.tipo, "A quilo");
	printf("Digite o peso em gramas da refei��o vendida: ");
	fflush(stdin);
	fscanf(stdin, "%d", &venda.peso);
	float preco = calcularPrecoPorPeso(venda.peso);
	printf("\n\nO pre�o por %d gramas � %.2f", venda.peso, preco);
	printf("\n\nHouve bebida nessa venda?\n");
	printf("1- Sim\t2- N�o\n");
	fflush(stdin);
	fscanf(stdin, "%d", &escolha);
	validarEscolha(2);
	if(escolha != 2){
		listaBebidas();
		fflush(stdin);
		fscanf(stdin, "%d", &escolha);
		validarEscolha(4);
		printf("E quantas bebidas v�o ser?\n");
		fflush(stdin);
		fscanf(stdin, "%d", &venda.qtdBebidas);
		if(venda.qtdBebidas != 0){
			preco = preco + adicionarBebida(escolha, venda.qtdBebidas);
		}
		venda.precoFinal = preco;
		printf("\nO pre�o final da refei��o com bebidas � de: %.2f", venda.precoFinal);
	}else{
		venda.precoFinal = preco;
		printf("\nO pre�o final da refei��o � de: %.2f", venda.precoFinal);
	}
	printf("\n\nE quando foi feita essa venda?\n");
	printf("Inserir o m�s de venda.\n");
	printf("Exemplo:\nJaneiro -> 1\nFevereiro -> 2\n");
	fscanf(stdin, "%d", &meses);
	registrarMes(meses);
	printf("\nTipo: %s\n", venda.tipo);
	printf("Peso: %d\n", venda.peso);
	printf("Qtd. Bebidas: %d\n", venda.qtdBebidas);
	printf("Pre�o: %.2f\n", venda.precoFinal);
	fwrite(&venda, sizeof(venda), 1, registroVendas);
	fclose(registroVendas);
	printf("Venda registrada!\n");
}

//Adicionando uma venda de refei��o manualmente, com o programa presumindo
//que � a quentinha.
void vendaQuentinhaManual(){
	struct Vendas venda;
	strcpy(venda.tipo, "Quentinha");
	venda.peso = 600;
	venda.precoFinal = quentinha();
	printf("\n\nHouve bebida nessa venda?\n");
	printf("1- Sim\t2- N�o\n");
	fscanf(stdin, "%d", &escolha);
	validarEscolha(2);
	if(escolha != 2){
		listaBebidas();
		fflush(stdin);
		fscanf(stdin, "%d", &escolha);
		validarEscolha(4);
		printf("\nE quantas bebidas v�o ser?\n");
		fflush(stdin);
		fscanf(stdin, "%d", &venda.qtdBebidas);
		venda.precoFinal += adicionarBebida(escolha, venda.qtdBebidas);
		printf("\nO pre�o final da quentinha com bebidas � de: %.2f", venda.precoFinal);
	}else{
		printf("\nO pre�o final da quentinha � de: %.2f", venda.precoFinal);
	}
	printf("\n\nE quando foi feita essa venda?\n");
	printf("Inserir o m�s de venda.\n");
	printf("Exemplo:\nJaneiro -> 1\nFevereiro -> 2\n");
	fscanf(stdin, "%d", &meses);
	registrarMes(meses);
	printf("\nTipo: %s\n", venda.tipo);
	printf("Peso: %d\n", venda.peso);
	printf("Qtd. Bebidas: %d\n", venda.qtdBebidas);
	printf("Pre�o: %.2f\n", venda.precoFinal);
	fwrite(&venda, sizeof(venda), 1, registroVendas);
	fclose(registroVendas);
	printf("Venda registrada!\n");
}

//Preenchendo as 100 vendas di�rias aleatoriamente
void vendasDiaria(){
	struct Vendas venda;
	int random;
	int qtdVenda;
	for(qtdVenda = 1; qtdVenda <= 100; qtdVenda++){
		// Random de 1 ou 0
		random = rand()%2;
		if(random == 0){
			//A quilo
			strcpy(venda.tipo, "A quilo");
			venda.peso = rand()%(900 + 1 - 300) + 300; // Peso aleat�rio entre 300 e 900 gramas
			venda.qtdBebidas = rand()%(2 + 1 - 0) + 0; // Quantidade aleat�ria de bebidas entre 0 e 2
			venda.precoFinal = calcularPrecoPorPeso(venda.peso);
			if(venda.qtdBebidas != 0){
				// Se houver bebida
				int bebida = rand()%(4 + 1 - 1) + 1; // Qual das bebidas, aleatorio
				venda.precoFinal += adicionarBebida(bebida, venda.qtdBebidas);
			}
			fwrite(&venda, sizeof(venda), 1, registroVendas); // Registra no arquivo
		}else{
			//Quentinha
			strcpy(venda.tipo, "Quentinha");
			venda.peso = 600; //Peso padr�o da quentinha
			venda.qtdBebidas = rand()%(2 + 1 - 0) + 0; // Quantidade aleat�ria de bebidas entre 0 e 2
			venda.precoFinal = quentinha(); // Pre�o padr�o da quentinha
			if(venda.qtdBebidas != 0){
				//Se houver bebida
				int bebida = rand()%(4 + 1 - 1) + 1; // Qual das bebidas, aleatorio
				venda.precoFinal += adicionarBebida(bebida, venda.qtdBebidas);
			}
			fwrite(&venda, sizeof(venda), 1, registroVendas); // Registra no arquivo
		}
	}
}

//Preenchendo os dados equivalentes a 1 ano de vendas
void preencherDados(){
	int mes;
	//Loop para cada m�s
	for(mes = JANEIRO; mes <= DEZEMBRO; mes++){
		int dia;
		//Abre um novo arquivo bin�rio para cada m�s
		registrarMes(mes);
		if(mes == FEVEREIRO){ // Se m�s fevereiro, loop dos dias tem apenas 28 itera��es
			for(dia = 1; dia <= 28; dia++){
				vendasDiaria();
			}
		}else{
			//Se m�s n�o � fevereiro, loop dos dias tem 30 itera��es, sendo o "m�s comercial"
			for(dia = 1; dia <= 30; dia++){
				vendasDiaria();
			}	
		}
		fclose(registroVendas);
	}
	if(registroVendas != NULL){ // Checa se por ventura o arquivo n�o est� ainda aberto
		fclose(registroVendas); // e fecha se estiver
	}
	printf("\n\n**** Vendas geradas com sucesso! ****\n\n");
}

// Relat�rio di�rio, onde pode-se escolher o m�s e o dia para ver os valores.
void relatorioDiario(){
	struct Vendas venda;
	int mes, dia, i;
	int quentinha = 0;
	int quilo = 0;
	float faturamentoDiario, pesoVendido;
	printf("Insira o n�mero equivalente ao m�s que deseja consultar.\n");
	printf("Exemplo:\n Janeiro -> 1\n");
	printf("Fevereiro -> 2\n");
	fflush(stdin);
	fscanf(stdin, "%d", &mes);
	analisarMes(mes); // abrindo o arquivo de leitura do m�s solicitado
	printf("Insira o valor do dia do m�s.\n");
	fflush(stdin);
	fscanf(stdin, "%d", &dia);
	fseek(registroVendas, sizeof(venda) * (dia - 1) * 100, SEEK_SET); //movendo o ponteiro para o dia espec�fico
	printDiaMes(dia, mes);
	for(i = 1; i <= 100; i++){
		fread(&venda, sizeof(venda), 1, registroVendas);
		if(strcmp(venda.tipo, "A quilo")){
			quilo++;
		}
		if(strcmp(venda.tipo, "Quentinha")){
			quentinha++;
		}
		faturamentoDiario += venda.precoFinal; // adicionando ao faturamento di�rio
		pesoVendido += venda.peso; // adicionando ao peso vendido di�rio
	}
	pesoVendido = (pesoVendido * 0.001); // convertendo para kg
	//mostrando o faturamento total do dia
	printf("****** Faturamento do dia ******\n");
	printf("Quentinhas vendidas: %d\n", quentinha);
	printf("Refei��es a quilo vendidas: %d\n", quilo);
	printf("Total de peso de comida vendido: %.2fkg\n", pesoVendido);
	printf("Total de faturamento: R$%.2f", faturamentoDiario);
}

// Realizando o relat�rio mensal
void relatorioMensal(){
	struct Vendas vendaAtual;
	int mes;
	int quilo = 0;
	int quentinha = 0;
	float faturamentoMensal[DEZEMBRO];
	float pesoVendido;
	char string[25];
	// Loop para cada m�s
	printf("\n\n****** Faturamento Mensal ******\n\n");
	for(mes = JANEIRO; mes <= DEZEMBRO; mes++){
		analisarMes(mes);
		while(fread(&vendaAtual, sizeof(vendaAtual), 1, registroVendas)){
			if(strcmp(vendaAtual.tipo, "A quilo")){
				quilo++;
			}
			if(strcmp(vendaAtual.tipo, "Quentinha")){
				quentinha++;
			}
			faturamentoMensal[mes - 1] += vendaAtual.precoFinal;
			pesoVendido += vendaAtual.peso;
		}
		strcpy(string, stringMes(mes));
		printf("**** %s ****\n", string);
		printf("Quentinhas vendidas: %d\n", quentinha);
		printf("Refei��es a quilo vendidas: %d\n", quilo);
		printf("Total de peso de comida vendido: %.2fkg\n", pesoVendido * 0.001);
		printf("\nFaturamento: R$%.2f\n\n", faturamentoMensal[mes - 1]);
		fclose(registroVendas);
		quentinha = 0;
		quilo = 0;
		pesoVendido = 0;
	}
}

void compararVendas(){
	struct Vendas vendaAtual;
	float faturamentoMensal[DEZEMBRO];
	int mes, i;
	int meses[DEZEMBRO];
	for(mes = JANEIRO; mes <= DEZEMBRO; mes++){
		analisarMes(mes);
		while(fread(&vendaAtual, sizeof(vendaAtual), 1, registroVendas)){
			faturamentoMensal[mes - 1] += vendaAtual.precoFinal;
		}
		meses[mes - 1] = mes;
		fclose(registroVendas);
	}
	for(i = JANEIRO - 1; i < DEZEMBRO; i++){
		int mem, memMeses; // memoria pra auxiliar
		int j; // iterador do loop interno
		for(j = i; j < DEZEMBRO; j++){
			if(faturamentoMensal[i] < faturamentoMensal[j]){
				//Reordenando o faturamento do m�s
				mem = faturamentoMensal[j];
				faturamentoMensal[j] = faturamentoMensal[i];
				faturamentoMensal[i] = mem;
				//Reordenando o m�s em si
				memMeses = meses[j];
				meses[j] = meses[i];
				meses[i] = memMeses;
			}
		}
	}
	int l;
	char string[25];
	for(l = 0; l < DEZEMBRO; l++){
		strcpy(string, stringMes(meses[l]));
		printf("**** %s ****", string);
		printf("\nFaturamento: R$%.2f\n\n", faturamentoMensal[l]);
	}
	printf("\n\n**** M�s com maior faturamento ****\n");
	strcpy(string, stringMes(meses[0]));
	printf("%s\n\n", string);
	printf("**** M�s com menor faturamento ****\n");
	strcpy(string, stringMes(meses[11]));
	printf("%s\n\n", string);
}

int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	printf("Bem vindo ao sistema de registro de vendas!");
	do{
		printf("\n\nO que deseja fazer?\n");
		printf("1- Inserir nova venda manualmente (A quilo)\n");
		printf("2- Inserir nova venda manualmente (Quentinha)\n");
		printf("3- Gerar 1 ano de vendas automaticamente.\n");
		printf("4- Relatorio diario.\n");
		printf("5- Relatorio mensal.\n");
		printf("6- M�s com maior faturamento.\n");
		printf("7- Sair\n\n");
		fflush(stdin);
		fscanf(stdin, "%d", &escolha);
		switch(escolha){
			case 1:
				vendaRefeicaoManual();
				break;
			case 2:
				vendaQuentinhaManual();
				break;
			case 3:
				preencherDados();
				break;
			case 4:
				relatorioDiario();
				break;
			case 5:
				relatorioMensal();
				break;
			case 6:
				compararVendas();
				break;
			case 7:
				printf("\n\n***** Obrigado! *****\n");
				return 0;
			default:
				printf("Insira um valor v�lido.\n");
				break;
		}
	}while(escolha != 7);
}
