#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

//------------------------- DECLARANDO VARIÁVEIS GLOBAIS ------------------------------------
int nJog, // Quantidade de jogadores
tab[51][5]={0}, //Matriz tabuleiro
jogador=1, // Número do jogador em ação
jogada, // Variável para selecionar a ação do jogador
pos[5]={1,1,1,1,1}, // Vetor que armazenará a posição de cada jogador
valDado, // Valor que sair do dado
posEsp[10] = {4,8,12,16,20,24,28,32,36,40};// Posições especiais

//------------------------- DECLARANDO AS FUNÇÕES CRIADAS -----------------------------------
void janelaMaximizada(void);
void barraDeCarregamento(void);
int menu_inicial();
void inicializar(void);
void regras(void);
void sobre(void);
void saida(void);
void tabuleiro(void);
void posTabuleiro(void);
void dado(void);
void imagens_dado(int numero);
void menuDaJogada(void);
void cartas(void);
void imagens_cartas(int numero);
void fimDeJogo();
void SetColor(int ForgC);

//------------------------- INICIO DA FUNÇÃO MAIN -------------------------------------------
int main(){
    janelaMaximizada();
    barraDeCarregamento();
    int inicio;
    setlocale(LC_ALL,"Portuguese");
    for(int i=0;i<nJog;i++) tab[0][i]=i+1; //Inserindo o cabeçalho do tabuleiro
    for(;;){
        inicio = menu_inicial();
        barraDeCarregamento();
    switch(inicio){
    case 1:
        inicializar();
        break;
    case 2:
        regras();
        break;
    case 3:
        sobre();
        break;
    case 4:
        saida();
        return 0;
        break;
    }
    if(inicio == 1) break;
    }

    for(;;){
        menuDaJogada();
        dado();
        // Modificando o valor da posição
        pos[jogador-1] = pos[jogador-1] + valDado;

        // for que testa se o jogador caiu em uma posição para receber a carta especial
        for(int i=0;i<10;i++) if(pos[jogador-1] == posEsp[i]){cartas();break;}

        //if para verificar se o jogador ganhou o jogo
        if(pos[jogador-1]>=50){fimDeJogo(); break;}

        posTabuleiro();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t###############################\n");
        printf("\t\t\t\t\t\t\t\t#                             #\n");
        printf("\t\t\t\t\t\t\t\t# Fim da jogada do jogador %d  #\n",jogador);
        printf("\t\t\t\t\t\t\t\t#                             #\n");
        printf("\t\t\t\t\t\t\t\t###############################\n");
        if(jogador == nJog){ jogador = 1; }else{ jogador++; }
        Sleep(1000);
        system("cls");
    }
return 0;
}
//------------------------------- FIM DA FUNÇÃO MAIN ------------------------------------------

//------------------------------- CRIAÇÃO DE FUNÇÕES ------------------------------------------
void janelaMaximizada(void){
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

void barraDeCarregamento(void){ // Função para a animação da barra de carregamento
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tCARREGANDO...\n");
    printf("\t\t\t\t\t\t\t\t\t\t  [");
    for(int i=0;i<5;i++){
        SetColor(2);
        printf("#");
        Sleep(500);
    }
    SetColor(7);
    printf("]\n");
    Sleep(500);
}

int menu_inicial(){ //Função do menu inicial
    int sel;
    for(;;){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t################################################\n");
    printf("\t\t\t\t\t\t\t#                   MENU INCIAL                #\n");
    printf("\t\t\t\t\t\t\t#                1 - INICIA LOGO               #\n");
    printf("\t\t\t\t\t\t\t#                2 - REGRINHAS                 #\n");
    printf("\t\t\t\t\t\t\t#                3 - SOBRE                     #\n");
    printf("\t\t\t\t\t\t\t#                4 - SAIR                      #\n");
    printf("\t\t\t\t\t\t\t################################################\n\n");
    printf("\t\t\t\t\t\t\t            INSIRA A OPÇÃO QUE DESEJA: ");
    scanf("%d",&sel);
    if((sel<1)|| (sel>4)){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("t\t\t\t\t\t\t VALOR DIGITADO INCORRETO, DIGITE UM NOVO VALOR \n");
    system("pause");
    }else{
        break;
    }
    }
    return sel;
}

void regras(void){ // Função para apresentar as regras
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t##########################################################################################################################\n");
    printf("\t\t\t#                                                      REGRAS DO JOGO                                                    #\n");
    printf("\t\t\t#________________________________________________________________________________________________________________________#\n");
    printf("\t\t\t#                                                                                                                        #\n");
    printf("\t\t\t#\t1 - Trata-se de um jogo de tabuleiro para 2 a 5 pssoas.                                                          #\n");
    printf("\t\t\t#\t2 - Todos os jogadores partem da mesma linha de partida, vale ressaltar que o caminho é visto de cima para baixo.#\n");
    printf("\t\t\t#\t3 - Cada jogador tem sua vez de jogar um dado com valores de 1 a 6, para avançar posições.                       #\n");
    printf("\t\t\t#\t4 - Existem 2(dois) tipos de posições: Simples e Especiais.                                                      #\n");
    printf("\t\t\t#\t\t4.1 - Posições simples: São apenas posições e não afetarão nem negativamente e nem positivamente.        #\n");
    printf("\t\t\t#\t\t4.2 - Posições especiais: São posições onde o jogador receberá uma carta com uma vantagem ou desvantagem.#\n");
    printf("\t\t\t#\t5 - O primeiro jogador a chegar na posição 50 vence o jogo.                                                      #\n");
    printf("\t\t\t#                                                                                                                        #\n");
    printf("\t\t\t##########################################################################################################################\n");
    printf("\n\n");
    system("pause");
}

void sobre(void){ // Função para saber as informações do desenvolvedor
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t################################################\n");
    printf("\t\t\t\t\t\t\t#     DESENVOLVEDOR: RAFAEL QUEIROZ SANTOS     #\n");
    printf("\t\t\t\t\t\t\t#     MOTIVO: AVALIAÇÃO FINAL DE ALGORITMOS    #\n");
    printf("\t\t\t\t\t\t\t################################################\n");
    printf("\n\n");
    system("pause");
}

void saida(void){ // Função para sair do jogo
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t################################################\n");
        printf("\t\t\t\t\t\t\t#           VOCÊ ESTÁ SAINDO DO JOGO           #\n");
        printf("\t\t\t\t\t\t\t################################################\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void inicializar(void){ //Função para inserir o número de jogadores
    for(;;){
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t###################################\n");
        printf("\t\t\t\t\t\t\t#  Digite o número de jogadores:  #\n");
        printf("\t\t\t\t\t\t\t#        (2 a 5 jogadores)        #\n");
        printf("\t\t\t\t\t\t\t###################################\n\n");
        printf("\t\t\t\t\t\t\tResposta: ");
        scanf("%d",&nJog);
        if((nJog>=2) && (nJog<=5)){
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("\t\t\t\t\t\t\t\t\t########################\n");
            printf("\t\t\t\t\t\t\t\t\t##  Começando o jogo  ##\n");
            printf("\t\t\t\t\t\t\t\t\t########################\n");
            Sleep(1500);
            break;
        }
        printf("\n\t\t\t\tNúmero de jogadores não é válido. Pressione ENTER para tentar novamente.");
        system("pause>nul");
    }
    for(int i=0;i<nJog;i++){ //Colocando os participantes na posição 1 do tabuleiro
        tab[1][i]=i+1;
    }
}

void tabuleiro(void){ // Função para imprimir o tabuleiro
    system("cls");
    printf("\t\t\t\t#######################\n");
    printf("\t\t\t\t###### TABULEIRO ######\n");
    printf("\t\t\t\t#######################\n");
    for(int i=0;i<nJog;i++) tab[0][i]=i+1;
    for(int i=0;i<nJog;i++) printf(" \t%d\t",tab[0][i]);
    printf("\n");
    for(int i=0;i<nJog;i++) printf(" \t-\t");
    printf("\n");
    for(int i=1;i<=50;i++){
        if(i<10) printf(" ");
        printf("%dª",i);
        for(int j=0;j<nJog;j++){ printf("|"); printf("\t%d\t",tab[i][j]); }
        printf("|");
        printf("\n");
    }
}

void dado(void){ // Função que faz o papel do dado
    system("cls");
    srand((unsigned)time(NULL));
    valDado = 1+(rand()%6);
    imagens_dado(valDado);
    printf("\t\t\t\t\t\t\t\tO valor que o dado deu é: %d\n",valDado);
    system("pause");
    system("cls");
}

void imagens_dado(int numero){ // Função para impressão do dado
    switch(numero){
    case 1:
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t############\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t############\n\n");
        break;
    case 2:
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t############\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##      #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##      #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#      ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#      ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t############\n\n");
        break;
    case 3:
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t############\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##      #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##      #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#      ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#      ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t############\n\n");
        break;
    case 4:
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t############\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t############\n\n");
        break;
    case 5:
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t############\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t############\n\n");
        break;
    case 6:
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t############\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##  ##  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t############\n\n");
        break;
    }
}

void menuDaJogada(void){ //Função do menu do jogador da rodada
    for(;;){
        tabuleiro();
        printf("\n\n");
        printf("\t\t\t\t\t#####################################################\n");
        printf("\t\t\t\t\t#                                                   #\n");
        printf("\t\t\t\t\t#  Jogador número %d, selecione o que deseja fazer:  #\n",jogador);
        printf("\t\t\t\t\t#\t1 - Jogar o dado.                           #\n");
        printf("\t\t\t\t\t#\t2 - Verificar em qual casa você se encontra.#\n");
        printf("\t\t\t\t\t#                                                   #\n");
        printf("\t\t\t\t\t#####################################################\n\n");
        printf("\t\t\t\t\t\t\t Opção: ");
        scanf("%d",&jogada);
        if(jogada == 1){
            break;
        }else if(jogada == 2){
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("\t\t\t\t\t#########################################################\n");
            printf("\t\t\t\t\t#                                                       #\n");
            printf("\t\t\t\t\t#   Jogador nº %d, você se encontra na casa de nº %d.    #\n",jogador,pos[jogador-1]);
            printf("\t\t\t\t\t#                                                       #\n");
            printf("\t\t\t\t\t#########################################################\n\n");
            system("pause");
            system("cls");
        }else{
            printf("Jogada não permitida. Favor digite um número compatível.\n");
            system("pause");
            system("cls");
        }
    }
}

void posTabuleiro(void){ //Função para modificar no tabuleiro a posição atual do jogador
    for(int i=1;i<=51;i++) if(i==pos[jogador-1]){ tab[i][jogador-1] = jogador;}else{ tab[i][jogador-1] = 0;}
}

void cartas(void){ // Função para distribuir a carta especial
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t############################################################\n");
    printf("\t\t\t\t\t\t\t#                                                          #\n");
    printf("\t\t\t\t\t\t\t#  VOCÊ CAIU EM UMA CASA ESPECIAL, O Nº DA SUA CARTA É...  #\n");
    printf("\t\t\t\t\t\t\t#                                                          #\n");
    printf("\t\t\t\t\t\t\t############################################################\n");
    system("pause");
    system("cls");
    srand((unsigned)time(NULL));
    switch (1+(rand()%10)){
    case 1:
        imagens_cartas(1);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 1: #\n");
        printf("\t\t\t\t\t\t\t\t\t#   Retorne 1 casas.   #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        pos[jogador-1] = pos[jogador-1] - 1;
        system("pause");
        system("cls");
        break;
    case 2:
        imagens_cartas(2);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 2: #\n");
        printf("\t\t\t\t\t\t\t\t\t#   Retorne 2 casas.   #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        pos[jogador-1] = pos[jogador-1] - 2;
        system("pause");
        system("cls");
        break;
    case 3:
        imagens_cartas(3);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 3: #\n");
        printf("\t\t\t\t\t\t\t\t\t#   Retorne 3 casas.   #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        pos[jogador-1] = pos[jogador-1] - 3;
        system("pause");
        system("cls");
        break;
    case 4:
        imagens_cartas(4);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 4: #\n");
        printf("\t\t\t\t\t\t\t\t\t#  Retorne ao inicio.  #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        pos[jogador-1] = 1;
        system("pause");
        system("cls");
        break;
    case 5:
        imagens_cartas(5);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 5: #\n");
        printf("\t\t\t\t\t\t\t\t\t#    Carta Coringa,    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    Nada acontece.    #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        system("pause");
        system("cls");
        break;
    case 6:
        imagens_cartas(6);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 6: #\n");
        printf("\t\t\t\t\t\t\t\t\t#    Avance 1 casa.    #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        pos[jogador-1] = pos[jogador-1] + 1;
        system("pause");
        system("cls");
        break;
    case 7:
        imagens_cartas(7);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 7: #\n");
        printf("\t\t\t\t\t\t\t\t\t#    Avance 2 casas.   #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        pos[jogador-1] = pos[jogador-1] + 2;
        system("pause");
        system("cls");
        break;
    case 8:
        imagens_cartas(8);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 8: #\n");
        printf("\t\t\t\t\t\t\t\t\t#    Avance 3 casas.   #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        pos[jogador-1] = pos[jogador-1] + 3;
        system("pause");
        system("cls");
        break;
    case 9:
        imagens_cartas(9);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 4: #\n");
        printf("\t\t\t\t\t\t\t\t\t#    Avance 4 casas.   #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        pos[jogador-1] = pos[jogador-1] + 4;
        system("pause");
        system("cls");
        break;
    case 10:
        imagens_cartas(10);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t# Carta especial nº 10:#\n");
        printf("\t\t\t\t\t\t\t\t\t#    Carta Coringa,    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    Nada acontece.    #\n");
        printf("\t\t\t\t\t\t\t\t\t#                      #\n");
        printf("\t\t\t\t\t\t\t\t\t########################\n");
        pos[jogador-1] = pos[jogador-1] + 2;
        system("pause");
        system("cls");
        break;
    }
}

void imagens_cartas(int numero){ // Função de impressão da carta especial
    switch(numero){
    case 1: //Carta 1
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t############\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ######  #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ######  #\n");
        printf("\t\t\t\t\t\t\t\t\t#          #\n");
        printf("\t\t\t\t\t\t\t\t\t############\n");
        break;
    case 2: //Carta 2
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t################\n");
        printf("\t\t\t\t\t\t\t\t\t#              #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##########  #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##########  #\n");
        printf("\t\t\t\t\t\t\t\t\t#              #\n");
        printf("\t\t\t\t\t\t\t\t\t################\n");
        break;
    case 3: //Carta 3
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t####################\n");
        printf("\t\t\t\t\t\t\t\t\t#                  #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##############  #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ##############  #\n");
        printf("\t\t\t\t\t\t\t\t\t#                  #\n");
        printf("\t\t\t\t\t\t\t\t\t####################\n");
        break;
    case 4: //Carta 4
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t###############################\n");
        printf("\t\t\t\t\t\t\t\t\t#                             #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ######   ######    ######  #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##       ##        ##    #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##        ##      ##     #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##         ##    ##      #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##          ##  ##       #\n");
        printf("\t\t\t\t\t\t\t\t\t#    ##           ####        #\n");
        printf("\t\t\t\t\t\t\t\t\t#  ######       ########      #\n");
        printf("\t\t\t\t\t\t\t\t\t#                             #\n");
        printf("\t\t\t\t\t\t\t\t\t###############################\n");
        break;
    case 5: //Carta 5
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t######################\n");
        printf("\t\t\t\t\t\t\t\t#                    #\n");
        printf("\t\t\t\t\t\t\t\t#  ######    ######  #\n");
        printf("\t\t\t\t\t\t\t\t#    ##        ##    #\n");
        printf("\t\t\t\t\t\t\t\t#     ##      ##     #\n");
        printf("\t\t\t\t\t\t\t\t#      ##    ##      #\n");
        printf("\t\t\t\t\t\t\t\t#       ##  ##       #\n");
        printf("\t\t\t\t\t\t\t\t#        ####        #\n");
        printf("\t\t\t\t\t\t\t\t#      ########      #\n");
        printf("\t\t\t\t\t\t\t\t#                    #\n");
        printf("\t\t\t\t\t\t\t\t######################\n");
        break;
    case 6: //Carta 6
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t###############################\n");
        printf("\t\t\t\t\t\t\t\t#                             #\n");
        printf("\t\t\t\t\t\t\t\t#  ######    ######   ######  #\n");
        printf("\t\t\t\t\t\t\t\t#    ##        ##       ##    #\n");
        printf("\t\t\t\t\t\t\t\t#     ##      ##        ##    #\n");
        printf("\t\t\t\t\t\t\t\t#      ##    ##         ##    #\n");
        printf("\t\t\t\t\t\t\t\t#       ##  ##          ##    #\n");
        printf("\t\t\t\t\t\t\t\t#        ####           ##    #\n");
        printf("\t\t\t\t\t\t\t\t#      ########       ######  #\n");
        printf("\t\t\t\t\t\t\t\t#                             #\n");
        printf("\t\t\t\t\t\t\t\t###############################\n");
        break;
    case 7: //Carta 7
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t###################################\n");
        printf("\t\t\t\t\t\t\t\t#                                 #\n");
        printf("\t\t\t\t\t\t\t\t#  ######    ######   ##########  #\n");
        printf("\t\t\t\t\t\t\t\t#    ##        ##       ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#     ##      ##        ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#      ##    ##         ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#       ##  ##          ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#        ####           ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#      ########       ##########  #\n");
        printf("\t\t\t\t\t\t\t\t#                                 #\n");
        printf("\t\t\t\t\t\t\t\t###################################\n");
        break;
    case 8: //Carta 8
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t#####################################\n");
        printf("\t\t\t\t\t\t\t\t#                                   #\n");
        printf("\t\t\t\t\t\t\t\t#  ######    ###### ##############  #\n");
        printf("\t\t\t\t\t\t\t\t#    ##        ##     ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#     ##      ##      ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#      ##    ##       ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#       ##  ##        ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#        ####         ##  ##  ##    #\n");
        printf("\t\t\t\t\t\t\t\t#      ########     ##############  #\n");
        printf("\t\t\t\t\t\t\t\t#                                   #\n");
        printf("\t\t\t\t\t\t\t\t#####################################\n");
        break;
    case 9: //Carta 9
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t############################\n");
        printf("\t\t\t\t\t\t\t\t#                          #\n");
        printf("\t\t\t\t\t\t\t\t#  ######  ######  ######  #\n");
        printf("\t\t\t\t\t\t\t\t#    ##      ##      ##    #\n");
        printf("\t\t\t\t\t\t\t\t#    ##       ##    ##     #\n");
        printf("\t\t\t\t\t\t\t\t#    ##        ##  ##      #\n");
        printf("\t\t\t\t\t\t\t\t#    ##         ####       #\n");
        printf("\t\t\t\t\t\t\t\t#    ##        ##  ##      #\n");
        printf("\t\t\t\t\t\t\t\t#    ##       ##    ##     #\n");
        printf("\t\t\t\t\t\t\t\t#    ##      ##      ##    #\n");
        printf("\t\t\t\t\t\t\t\t#  ######  ######  ######  #\n");
        printf("\t\t\t\t\t\t\t\t#                          #\n");
        printf("\t\t\t\t\t\t\t\t############################\n");
        break;
    case 10: //Carta 10
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t####################\n");
        printf("\t\t\t\t\t\t\t\t#                  #\n");
        printf("\t\t\t\t\t\t\t\t#  ######  ######  #\n");
        printf("\t\t\t\t\t\t\t\t#    ##      ##    #\n");
        printf("\t\t\t\t\t\t\t\t#     ##    ##     #\n");
        printf("\t\t\t\t\t\t\t\t#      ##  ##      #\n");
        printf("\t\t\t\t\t\t\t\t#       ####       #\n");
        printf("\t\t\t\t\t\t\t\t#      ##  ##      #\n");
        printf("\t\t\t\t\t\t\t\t#     ##    ##     #\n");
        printf("\t\t\t\t\t\t\t\t#    ##      ##    #\n");
        printf("\t\t\t\t\t\t\t\t#  ######  ######  #\n");
        printf("\t\t\t\t\t\t\t\t#                  #\n");
        printf("\t\t\t\t\t\t\t\t####################\n");
        break;
    }
}

void fimDeJogo(){ // Animação de fim de jogo
    srand(time(NULL));
    system("cls & color A");
    for(int i=0;i<100000;i++){ printf("%d",rand()%2); Sleep(0.5); }
    system("cls");
    printf("\n");
    printf("##########  ##########  ####            ####\n");
    printf("#               ##      ## ##          ## ##\n");
    printf("#               ##      ##  ##        ##  ##\n");
    printf("#               ##      ##   ##      ##   ##\n");
    printf("#####           ##      ##    ##    ##    ##\n");
    printf("#               ##      ##     ##  ##     ##\n");
    printf("#               ##      ##      ####      ##\n");
    printf("#               ##      ##                ##\n");
    printf("#               ##      ##                ##\n");
    printf("#           ##########  ##                ##\n\n");
    printf("############################################\n");
    printf("#                                          #\n");
    printf("#      O jogador %d ganhou o jogo.         #\n",jogador);
    printf("#                                          #\n");
    printf("############################################\n");
}

void SetColor(int ForgC){ // Função para colorir partes especificas do código
    WORD wColor; //This handle is needed to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi; //csbi is used for wAttributes word
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){ //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
