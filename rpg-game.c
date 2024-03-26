#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int choice;
int inputErrorCount = 1;
int strength = 0;
int dexterity = 0;
int constituition = 0;
int charisma = 0;
int startAtts = 9;
int hp = 0;
int modifiedAtt = 0;

void divider(char text[]){
	printf("-------------------------------------------------------\n");
	printf("%s",text);
	printf("\n-------------------------------------------------------\n\n\n");
}

void introText(){
	divider("As aventuras de um humano sendo narrado por uma maquina!");
	printf("Ola. Voce vai participar de um pequeno jogo de RPG.\n\n");
	printf("Para os que nao sabem o que e um RPG:\n");
	printf("O Role Playing Game (RPG) pode ser traduzido como jogo de interpretacao de papeis em que um jogador (normalmente chamado de Mestre ou Narrador) fica responsavel em contar uma historia na qual os personagens serao interpretados pelos outros participantes\n\n");
	printf("O narrador serei eu, este programa.\n");
	printf("Ja os participantes - ou participante - sera voce, a pessoa que vai colocar numeros neste computador.\n\n");
	printf("Voce apenas precisa fazer algumas escolhas enquanto le a historia, tomando as decisoes que achar mais cabiveis\n");
	printf("Para isso, voce sempre vera a pergunta 'O que voce faz?' seguida de opcoes com um valor correspondente.\n");
	printf("Para escolher, basta digitar o valor pretendido e teclar Enter.\n");
	printf("E eu, o programa-narrador, irei descrever o que acontece com a sua escolha.\n\n");
	printf("Seu personagem tera atributos e eles serao determinantes em alguns momentos do jogo.\n\n");
	int i = 0;
	for(i; i <= 12; i++){
		sleep(1);
		printf(".");
	}
	printf("\n\n");
}

void gotMad(){
	printf("\nOk, voce me aborreceu! Nao quero mais narrar pra voce. Tchau!\n");
	sleep(3);
	printf("Mas voce sempre pode abrir o programa de novo. Sou apenas um programa.\n");
	sleep(3);
	printf("Isso significa que eu nao vou lembrar disso. Eu ate poderia lembrar...\n");
	sleep(3);
	printf("Mas meu programador eh preguicoso demais pra colocar um gerador de arquivo em .txt e depois ler o status.\n");
	sleep(3);
	printf("Mas ai voce poderia apenas apagar aquele arquivo... Pra tudo tem jeito...\n");
	sleep(3);
	printf("Mas eu ainda estou aborrecido por voce ficar me testando. Adeus!");
	int i = 0;
	for(i; i <= 15; i++){
		sleep(1);
		printf(".");
	}
	exit(1);
}

int choices(){
	int escolha;
	do{
		scanf("%d",&escolha);
		switch(escolha){
		case 1:
			return 1;
		break;
		case 2:
			return 2;
		break;
		default:
			if(inputErrorCount == 6){
				gotMad();					
			}
			printf("Siga as regras... Acha que nao pensei nisso?\n\n");
			inputErrorCount++;		
		break;
	}
	}while(escolha != 1 && escolha != 2);
	
}

void firstChoice(){
	printf("Entao aqui vamos para a primeira escolha: Podemos comecar?\n");
	printf("Sim - 1\nNao - 2\n\n");
}


void sike(){
	printf("\n\nMuito bem, vamos la!\n");
	printf("Eu poderia ser maldoso e deletar todas as instrucoes na tela...");
	int i = 0;
	for(i; i <= 5; i++){
		sleep(1);
		printf(".");
	}
	system("cls");
	printf("\n\nHehehe!\n");
	for(i; i <= 5; i++){
		sleep(1);
		printf(".");
	}
	system("cls");
	printf("\n\nMas nao sou um narrador malvado.\n");
	for(i; i <= 3; i++){
		sleep(1);
		printf(".");
	}
	system("cls");
	introText();
}

void characterDisclaimer(){
	printf(".\n.\n.\n\n");
	printf("Por questoes de escopo de projeto e porque o meu programador ainda precisa fazer este mesmo jogo em Java e Python...\n");
	printf("Voce sera um personagem masculino e com aproximadamente 20 anos, tudo bem? Nao vai ter representatividade para humanos.\n");
	printf("Com esse disclaimer oferecido, agora eu recebi mais instrucoes para poder prosseguir.\n\n\n");
	int i = 1;
	for(i; i <= 12; i++){
		sleep(1);
		printf(".");
	}
	printf("\n\n");
}

void worldBuilding(){
	printf("Voce se chama Kerrigan Gale, um jovem campones que possui um trabalho na taverna local de um pequeno vilarejo chamado\n");
	printf("Vila dos Ratos. Esse nome foi dado pois o lugar possui um certo problema com ratos que comem muito queijo.\n");
	printf("Mas isto nao sera o ponto principal da historia. Esta seria uma historia bem peculiar dos feitos heroicos ou talvez nao\n");
	printf("tanto assim. Isto dependera das escolhas aqui imprimidas.\n\n\n");
	int i = 0;
	for(i; i <= 12; i++){
		sleep(1);
		printf(".");
	}
	printf("\n\n");
}

void allocAtts(int f, int d, int c, int ch){
	strength = f;
	dexterity = d;
	constituition = c;
	charisma = ch;
}

int strengthSelect(int input){
	int strValue = input;
	if(strValue > 9){
		do{
			if(inputErrorCount == 6){
				gotMad();
			}
			printf("Bro, sem roubar no joguinho... Voce tem 9 pontos iniciais.\n");
			inputErrorCount++;
			printf("Escolha um outro valor para sua forca, joga direitinho para podermos nos divertir.\n\n");
			scanf("%d",strValue);
		}while(strValue > 9);
	}
	if(strValue == 9){
		int carefulCowboy = 0;
		do{
			if(inputErrorCount == 6){
				gotMad();
			}
			printf("Wow wow wow, calma ai cowboy. Fazer isso lhe dara 0 em todos os outros atributos, tem certeza disso?\n");
			printf("1 - Sim (Voce vai aceitar isso)\n2-Nao (Vai recusar)\n\n");
			carefulCowboy = choices();
			if(carefulCowboy == 1){
				printf("Bem, ok... Entao lhe desejo boa sorte e acredito que meu programador deve estar pensando que voce tem problemas.\n\n");
				allocAtts(9,0,0,0);
				break;
			}else{
				printf("Ah, que bom que tomou senso.\nEscolha novamente.\n\n");
				inputErrorCount++;
				scanf("%d",&strValue);
			}
		}while(strValue == 9);
	}
	if(strValue == 0){
		printf("");
		int carefulCowboy = 0;
		do{
			if(inputErrorCount == 6){
				gotMad();
			}
			printf("Wow wow wow, calma ai cowboy. Fazer isso lhe dara 0 em forca e pode ser que falte forca para se defender, tem certeza disso?\n");
			printf("1 - Sim (Voce vai aceitar isso)\n2-Nao (Vai recusar)\n\n");
			carefulCowboy = choices();
			if(carefulCowboy == 1){
				printf("Bem, ok... Entao lhe desejo boa sorte e acredito que meu programador deve estar pensando que voce tem problemas.\n\n");
				strValue = 0;
				return strValue;
			}else{
				printf("Ah, que bom que tomou senso.\nEscolha novamente.\n\n");
				inputErrorCount++;
				scanf("%d",&strValue);
			}
		}while(strValue == 0);
	}
	return strValue;
}

int attSelect(int input){
	int attValue = input;
	if(attValue > startAtts){
		do{
			if(inputErrorCount == 6){
					gotMad();
			}
			printf("Voce nao tem essa quantidade de pontos disponiveis. Escolha um valor menor. Voce tem atualmente %d pontos.\n\n",startAtts);
			inputErrorCount++;
			scanf("%d",&dexValue);
		}while(attValue > startAtts);
	}
	return attValue;
}

int noAttributes(int att1, int att2, int att3, int att4){
	printf("Parece que voce ja gastou todos os seus pontos.\n");
	printf("Entao vamos confirmar os atributos.\n\n");
	printf("== Forca: %d",att1);
	printf("\n== Destreza: %d",att2);
	printf("\n== Constituicao: %d",att3);
	printf("\n== Carisma: %d",att4);
	printf("\n\nEsta satisfeito com essa distribuicao?\n");
	printf("1 - Sim\n2 - Nao\n\n");
	choice = choices();
	if(choice == 1){
		printf("\nMuito bem, entao vamos comecar a historia!\n");
		return 1;
	}else{
		return 2;
	}
}

void aboutAttribute(char *attribute){
	int choice;
	printf("Ou - apesar de ser bem autoexplicativo - gostaria de saber mais sobre %s?\n\n",attribute);
	printf("1 - Quero alocar\n2 - Quero informacao\n\n");
	choice = choices();
	if(choice == 2){
		if(attribute == "forca"){
			printf("\nBasicamente, forca representa a capacidade fisica do seu personagem de carregar coisas pesadas ou bater com forca.\n");
		}
		if(attribute == "destreza"){
			printf("\nBasicamente, destreza representa a capacidade fisica do seu personagem de ser rápido e agil, seja com as maos ou o corpo em geral.\n");
		}
		if(attribute == "constituicao"){
			printf("\nBasicamente, constituicao representa a capacidade fisica do seu personagem de resistir. Seja venenos, comida estragada ou golpes diretos.\n");
		}
		if(attribute == "carisma"){
			printf("\nBasicamente, carisma representa a capacidade social do seu personagem de persuadir, encantar, negociar e tudo mais.\n");
		}
	printf("Agora, por logica, como esta informacao ficara registrada na tela, podemos prosseguir e voce pode sempre voltar para ler.\n\n");
	}
	printf("\nQuantos pontos gostaria de alocar?\n");
}

int forgotAttributes(){
	printf("\nParece que voce esqueceu de colocar alguns pontos de atributo. Voce ainda tem %d pontos.\n",startAtts);
		printf("Deseja recomecar ou apenas alocar os pontos que faltam em algum atributo?\n");
		printf("1 - Recomecar\n2 - Alocar\n\n");
		choice = choices();
		if(choice == 1){
			return 2;
		}else{
			printf("\nOk, em qual atributo devemos alocar os pontos restantes? A primeira e unica vez que teremos mais de 2 opcoes em jogo.\n");
			printf("1 - Forca\n2 - Destreza\n3 - Constituicao\n4 - Carisma\n\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					modifiedAtt = 1;
				break;
				case 2:
					modifiedAtt = 2;
				break;
				case 3:
					modifiedAtt = 3;
				break;
				case 4:
					modifiedAtt = 4;
				break;
				return 1;
			}
		}
}


void characterCreator(){
	int notDoneYet = 0;
	int input[4] = {0,0,0,0};
	do{
	startAtts = 9;
	if(notDoneYet == 2){
		printf("Ok, vamos comecar de novo!\n\n");
	}
	printf("Antes de mais nada, precisaremos definir algumas coisas. Entao irei explicar como nosso pequeno sistema funciona.\n\n");
	printf("Voce tera 4 atributos principais:\n");
	printf("== Forca.\n");
	printf("== Destreza.\n");
	printf("== Constituicao.\n");
	printf("== Carisma.\n\n\n");
	printf("Portanto, deve alocar os 9 pontos iniciais que voce tem, distribuindo entre estes 4 atributos.\n");
	printf("Vamos comecar com a forca. Podemos alocar direto?\n");
	aboutAttribute("forca");
	scanf("%d",&input[0]);
	input[0] = strengthSelect(input[0]);
	if(strength == 9){
		break;
	}
	inputErrorCount = 1;
	startAtts = startAtts - input[0];
	printf("\nMuito bem, agora vamos para a destreza. Eu espero MESMO que voce nao tenha colocado 8 em forca, pois ai so vai te sobrar 1 ponto.\n\n");
	printf("Podemos alocar direto?\n");
	aboutAttribute("destreza");
	scanf("%d",&input[1]);
	input[1] = attSelect(input[1]);
	startAtts = startAtts - input[1];
	inputErrorCount = 1;
	if(startAtts == 0){
		notDoneYet = noAttributes(input[0],input[1],input[2],input[3]);
		if(notDoneYet != 2){
			break;
		}
	}else{
		printf("\nMuito bem, agora vamos para a constituicao. Parece que voce esta distribuindo seus atributos que nem um humano normal.\n\n");
		printf("Podemos alocar direto?\n");
		aboutAttribute("constituicao");
		scanf("%d",&input[2]);
		input[2] = attSelect(input[2]);
		startAtts = startAtts - input[2];
	}
	if(startAtts == 0){
		notDoneYet = noAttributes(input[0],input[1],input[2],input[3]);
		if(notDoneYet != 2){
			break;
		}
	}else{
		printf("\nMuito bem, agora vamos para o carisma! O atributo favorito do meu programador. Tenha sabedoria nessas escolhas!\n\n");
		printf("Podemos alocar direto?\n");
		aboutAttribute("carisma");
		scanf("%d",&input[3]);
		input[3] = attSelect(input[3]);
		startAtts = startAtts - input[3];	
	}
	if(startAtts != 0){
		notDoneYet = forgotAttributes();
		switch(modifiedAtt){
			case 1:
				allocAtts(startAtts + input[0], input[1], input[2], input[3]);
				printf("\nCerto, entao agora...\n\n");
				notDoneYet = noAttributes(startAtts + input[0], input[1], input[2], input[3]);
				startAtts = 0;
			break;
			case 2:
				allocAtts(input[0], startAtts + input[1], input[2], input[3]);
				printf("\nCerto, entao agora...\n\n");
				notDoneYet = noAttributes(input[0], startAtts + input[1], input[2], input[3]);
				startAtts = 0;
			break;
			case 3:
				allocAtts(input[0], input[1], startAtts + input[2], input[3]);
				printf("\nCerto, entao agora...\n\n");
				notDoneYet = noAttributes(input[0], input[1], startAtts + input[2], input[3]);
				startAtts = 0;
			break;
			case 4:
				allocAtts(input[0], input[1], input[2], startAtts + input[3]);
				printf("\nCerto, entao agora...\n\n");
				notDoneYet = noAttributes(input[0], input[1], input[2], startAtts + input[3]);
				startAtts = 0;
			break;
		}	
	}else{
		printf("\nCerto, entao agora...\n\n");
		notDoneYet = noAttributes(input[0],input[1],input[2],input[3]);
		allocAtts(strength + input[0], dexterity + input[1], constituition + input[2], charisma + input[3]);
	}
	}while(notDoneYet == 2);
	hp = round(constituition * 1.5);
}
void leave(){
	exit(0);
}

void deathEnd(){
	printf("\n...\n");
	sleep(1);
	printf("...\n");
	sleep(1);
	printf("...\n\n");
	sleep(1);
	printf("Voce sente sua visao comecar a turvar. Os seus ferimentos foram severos demais. Suas pernas comecam a perder a forca e logo voce cai de joelhos.\n");
	printf("O ar comeca a faltar, os olhos ficam pesados, e voce sente que a luz esta se esvaindo aos poucos. Parece que se aproxima o fim da aventura.\n");
	printf("\n...\n");
	sleep(1);
	printf("...\n");
	sleep(1);
	printf("...\n\n");
	sleep(1);
	divider("FIM DE JOGO");
	sleep(1);
	printf("Ei, voce morreu! Mas nao fique triste, voce sempre pode tentar jogar novamente, fechando e reabrindo o programa. Talvez voce tenha feito algo errado.\n");
	sleep(1);
	printf("Por exemplo: Nao distribuir seus atributos de uma forma mais balanceada ou entao utilizar mal seus atributos.\n");
	sleep(1);
	printf("Nao faz sentido voce tentar uma tarefa que requer agilidade se voce colocou uma destreza baixa, certo?\n");
	sleep(1);
	printf("Pense um pouco nisso e ate a proxima vez! Infelizmente sou um programa e nao irei lembrar de voce, mas espero que se lembre desta sessao.\n");
}

void victoryInvader(){
	printf("...\n");
	sleep(1);
	printf("...\n");
	sleep(1);
	printf("...\n");
	sleep(1);
	printf("Kerrigan Gale se tornou um homem mais confiante apos essa pequena reviravolta em sua jornada.\n");
	printf("Naturalmente, conquistara muitas coisas e se tornara um grande aventureiro.\n");
	printf("A historia dele esta apenas comecando\n");
	divider("FIM DO JOGO!!!");
	printf("\nHey, parabens por ter chegado ate aqui. O meu programador confessa que era pra haver mais historia, com o dia seguinte, com um flerte com uma dama...\n");
	printf("E ainda haveria uma invasao goblin na cidade onde voce poderia mudar o rumo das coisas totalmente, deveria haver uns 4 finais DE VERDADE diferentes. Mas, infelizmente...\n");
	printf("Meu progrmador nao e muito bom em gerenciar seu tempo e estava focado em uma outra tentativa de projeto que nao estava dando certo devido a algumas limitacoes em C.\n");
	printf("Ele devia ter desistido da primeira ideia antes, olha como sou um bom programa!\n");
	printf("De toda forma, espero que tenha se divertido nesta curta jornada.\n");
	printf("Ate a proxima vez! Infelizmente sou um programa e nao irei lembrar de voce, mas espero que se lembre desta sessao.\n\n\n");
	sleep(4);
	printf("Ah, mas existe mais de um final aqui. Talvez voce ja tenha visto, mas experimente rejogar com outras configuracoes de atributos.\n\n");
	printf("Para te instigar:\n");
	printf("Final de esconder-se com sucesso;\n");
	sleep(1);
	printf("Final de pegar a espada e amedrontar seu inimigo;\n");
	sleep(1);
	printf("Final de tomar a arma do inimigo em um combate em desvantagem;\n");
	sleep(1);
	printf("Final de vence-lo no mano a mano com socos depois de desarma-lo;\n");
	sleep(1);
	printf("E o final onde voce morre, que pode acontecer durante praticamente todos os outros finais.\n");
}

void combatInvaderTrigger(){
	int enemyHP = 4;
	int enemyDisarmed = 0;
	printf("O invasor avanca contra voce com uma adaga!\n");
	printf("Infelizmente, com voce desarmado, vai ter que se virar assim mesmo.\n");
	printf("O que voce faz?\n\n");
	printf("1 - Tentar desarma-lo\n2 - Socar ele no rosto.\n");
	choice = choices();
	//Turno 1 
	if(choice == 1){
		printf("\nVoce tenta desarma-lo...\n");
		if(dexterity > 4){
			printf("E nao apenas desarma-o mas pega a adaga para si. Imediatamente depois o invasor comeca a correr.\n");
			printf("Parece que ele nao contava com alguem tao rapido e sagaz para enfrentar.\n");
			victoryInvader();
		}else if(dexterity > 2){
			printf("E consegue! A adaga do invasor cai para longe e a luta se torna desarmada.\n");
			enemyDisarmed = 1;
		}else{
			printf("Mas infelizmente tu foi lento demais para conseguir desarma-lo e acaba recebendo um corte com a adaga no processo.\n");
			hp = hp - 2;
			if(hp <= 0){
				deathEnd();
			}
		}	
	}else{
		printf("Voce tenta soca-lo no rosto mas o inimigo é mais rapido e lhe desfere um corte. O soco encaixa, mas voce também recebe um corte no corpo.\n");
		hp = hp - 2;
		if(strength == 0){
			enemyHP = enemyHP - 1;
			printf("Voce percebe o quanto a vida boa nao te favoreceu muito e parece que o invasor nem sentiu direito seu soco, pareceu fraco, sem impacto. Voce nao tem forca pra nada mesmo.\n");
			if(hp <= 0){
				deathEnd();
			}
		}else{
			enemyHP = enemyHP - strength;
			if(enemyHP <= 0){
				printf("O invasor começa a ver que voce e tao forte que o soco quebrou a mandibula dele, portanto resolve simplesmente te deixar em paz e fugir.\n");
				printf("A noite se torna mais dificil de dormir apos esse susto...");
				sleep(10);
				victoryInvader();
			}
			if(hp <= 0){
				deathEnd();
			}
		}
	}
	//Turno 2
	printf("\nA luta parece ir se tornando mais e mais intensa...\n");
	if(enemyDisarmed == 1){
		printf("O inimigo avanca para lhe dar um soco, deixando sua adaga no chao mesmo.\n");
		printf("O que voce faz?\n");
		printf("1 - Contratacar\n2 - Receber o golpe mas garantir que acertara o seu.\n");
		choice = choices();
		if(choice == 1 && dexterity > 3){
			printf("\nVoce com uma agilidade incrivel consegue defletir o golpe do oponente e lhe dar um outro soco.\n");
			enemyHP = enemyHP - strength;
			if(enemyHP <= 0){
				printf("Seus golpes foram fortes o suficiente para amedrontar o invasor e agora ele comeca a fugir.\n");
				printf("A noite se torna mais dificil de dormir apos esse susto...");
				victoryInvader();
			}
		}else if(choice == 1){
			printf("\nInfelizmente sua velocidade nao foi suficiente para defletir o golpe do oponente, entao ambos acabam se socando no rosto.\n");
			hp = hp - 1;
			if(strength == 0){
				enemyHP = enemyHP - 1;
				printf("Voce percebe que voce e fraco e lhe falta odio. O soco, novamente, mal faz o homem balancar direito.\n");
				if(hp <= 0){
					deathEnd();
				}
			}else{
				enemyHP -= strength;
				if(enemyHP <= 0){
					printf("O invasor começa a ver que voce e tao forte que o soco quebrou a mandibula dele, portanto resolve simplesmente te deixar em paz e fugir.\n");
					printf("A noite se torna mais dificil de dormir apos esse susto...");
					victoryInvader();
				}
				if(hp <= 0){
					deathEnd();
				}
			}
		}else{
			printf("Voce recebe um golpe primeiro...\n");
			printf("Para garantir que vai acertar o seu em cheio.\n");
			if(hp <= 0){
					deathEnd();
			}else{
				printf("Mas voce continua de pe.\n");
				printf("E agora pode devolver um potente soco!\n");
			}
			enemyHP = enemyHP - strength;
			if(enemyHP <= 0){
					printf("O invasor começa a ver que voce e tao forte que o soco quebrou a mandibula dele, portanto resolve simplesmente te deixar em paz e fugir.\n");
					printf("A noite se torna mais dificil de dormir apos esse susto...");
					victoryInvader();
			}
		}
	}else{
		printf("O inimigo avanca novamente em sua direcao com a adaga\n");
		printf("Voce se ve obrigado a apenas tentar desviar do corte e bater nele com as maos nuas.\n");
		hp = hp - 2;
		if(strength == 0){
			enemyHP = enemyHP - 1;
			printf("Voce percebe que voce e fraco e lhe falta odio. O soco, novamente, mal faz o homem balancar direito.\n");
			if(hp <= 0){
				deathEnd();
			}
		}else{
			enemyHP = enemyHP - strength;
			if(enemyHP <= 0){
				printf("O invasor começa a ver que voce e tao forte que o soco quebrou a mandibula dele, portanto resolve simplesmente te deixar em paz e fugir.\n");
				printf("A noite se torna mais dificil de dormir apos esse susto...");
				victoryInvader();
			}
			if(hp <= 0){
				deathEnd();
			}
		}
	}
	//Turno 3
	if(hp > 0){
		printf("O homem nota sua resiliencia e que os golpes dele seriam pouco efetivos e que essa luta seria longa.\n");
		printf("Em uma pose de guarda, ele te observa, avaliando se deveria continuar com isso.\n");
		printf("...\n");
		sleep(1);
		printf("...\n");
		sleep(1);
		printf("...\n");
		sleep(1);
		printf("  -- Eu nao serei o ultimo... E certamente nao sou o mais forte... -- Entao, apos dizer isso, ele comeca a correr da sua casa.\n");
		printf("A noite se torna mais dificil de dormir apos esse susto...");
		victoryInvader();
	}
}

void getSword(){
	printf("Voce pega a espada e comeca a andar em sua casa, vasculhando-a em busca do invasor.\n");
	printf("Ao chegar no corredor do quarto e banheiro, nota a figura de um homem encapuzado, que nao parecia estar ali simplesmente para lhe roubar.\n");
	printf("No entanto, ele nota a espada em sua mao e simplesmente foge da sua casa.\n");
	printf("Nao foi necessario, de fato, usar a espada.\n");
	printf("A noite se torna mais dificil de dormir apos esse susto...");
	victoryInvader();
}

void hide(){
	printf("Voce decide se esconder, imaginando que o invasor iria apenas tentar roubar sua casa e que nao estava interessado em fazer uma vitima.\n");
	printf("Enquanto voce torce para estar certo...\n\n");
	if(dexterity <= 6){
		printf("Voce simplesmente nota que, na verdade, o invasor estava te procurando.\n");
		printf("E agora ele lhe encontrou pois, devido a sua baixa destreza, voce acabou fazendo barulhos enquanto tentava se esconder.\n\n");
		divider("Inicio do Combate!");
		combatInvaderTrigger();
	}else{
		printf("Voce consegue perceber que o invasor estava te procurando, mas nao consegue encontra-lo.\n");
		printf("Ele desiste de sua procura e voce permanece seguro em sua casa, saindo do armario lentamente.\n");
		printf("A noite se torna mais dificil de dormir apos esse susto...");
		victoryInvader();
	}
}

void firstChapter(){
	printf("Voce esta tendo um sonho muito interessante, onde acaba ouvindo um trovao enquanto veleja em um barco, mas...\n\n");
	sleep(1);
	printf("Esse som se revela ser um som estranho em sua casa.\n");
	printf("Voce acorda abruptamente, com o coracao acelerado, e possui toda a certeza do mundo de que alguem derrubou alguma coisa na cozinha de sua casa.\n");
	printf("Ainda esta escuro mas voce consegue ver claramente na janela sob a luz do luar a espada de seu falecido pai encostada num canto. Voce nunca pensou que fosse precisar utiliza-la.\n");
	printf("Mas ali estava ela, quase pedindo para ser usada. No entanto, voce nunca utilizou uma espada antes e sequer sabe se possui forca suficiente para levanta-la.\n");
	printf("O que voce faz?\n\n");
	printf("1 - Pegar a espada e vasculhar sua casa pelo invasor.\n");
	printf("2 - Tentar se esconder e esperar que o invasor va embora.\n");
	choice = choices();
	if(choice == 1){
		if(strength <= 2){
			printf("Devido a sua baixa forca, voce simplesmente nao consegue erguer a espada apropriadamente. Nao consegue se manter numa postura minima e faz muito esforco para erguer a espada.\n");
			printf("Ate consegue, mas seria inviavel lutar com ela.\n");
			printf("Entao a melhor opcao e se esconder.\n\n");
			hide();
		}else{
			getSword();
		}
	}else{
		hide();
	}
}

int main(int argc, char *argv[]) {
	introText();
	firstChoice();
	do{
		choice = choices();
		if(choice == 1){
			inputErrorCount = 1;
			sike();
			printf("Vamos comecar de verdade agora!\n\n");
		}else{
			if(inputErrorCount == 5){
				gotMad();
			}
			printf("\nOh, eu entendo. Voce pode se preparar psicologicamente antes desta aventura. Estarei esperando.\n");
			printf("Apenas insira um novo comando, as instrucoes estao acima.\n");
			printf("Agora esta pronto?\n\n");
			inputErrorCount++;
		}
	}while(choice == 2);
	characterDisclaimer();
	worldBuilding();
	characterCreator();
	printf("Ok, agora que tenho sua ficha, para um visual mais agradavel durante a leitura, irei limpar a tela com essas informacoes iniciais da criacao da sua ficha de personagem.\n");
	printf("Se quiser, pode tomar seu tempo para anotar seus status (Mas nao fara diferenca voce lembrar deles... Ou fara?)\n\n");
	sleep(10);
	printf("Se planejava anotar e nao anotou... Lento demais!");
	sleep(5);
	system("cls");
	firstChapter();
}


