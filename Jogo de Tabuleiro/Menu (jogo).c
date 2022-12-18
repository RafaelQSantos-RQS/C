#include <stdio.h>
#include <stdlib.h>

void regras(void);
void sobre(void);
void saida(void);
int main(){
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
    printf("\t\t\t\t\t\t\t################################################\n");
    printf("\t\t\t\t\t\t\t INSIRA A OP��O QUE DESEJA: ");
    scanf("%d",&sel);
    switch(sel){
    case 1:
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
    }
    return 0;
}

void regras(void){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t##########################################################################################################################\n");
    printf("\t\t\t#                                                      REGRAS DO JOGO                                                    #\n");
    printf("\t\t\t#________________________________________________________________________________________________________________________#\n");
    printf("\t\t\t#                                                                                                                        #\n");
    printf("\t\t\t#\t1 - Trata-se de um jogo de tabuleiro para 2 a 5 pssoas.                                                          #\n");
    printf("\t\t\t#\t2 - Todos os jogadores partem da mesma linha de partida, vale ressaltar que o caminho � visto de cima para baixo.#\n");
    printf("\t\t\t#\t3 - Cada jogador tem sua vez de jogar um dado com valores de 1 a 6, para avan�ar posi��es.                       #\n");
    printf("\t\t\t#\t4 - Existem 2(dois) tipos de posi��es: Simples e Especiais.                                                      #\n");
    printf("\t\t\t#\t\t4.1 - Posi��es simples: S�o apenas posi��es e n�o afetar�o nem negativamente e nem positivamente.        #\n");
    printf("\t\t\t#\t\t4.2 - Posi��es especiais: S�o posi��es onde o jogador receber� uma carta com uma vantagem ou desvantagem.#\n");
    printf("\t\t\t#\t5 - O primeiro jogador a chegar na posi��o 50 vence o jogo.                                                      #\n");
    printf("\t\t\t#                                                                                                                        #\n");
    printf("\t\t\t##########################################################################################################################\n");
    printf("\n\n");
    system("pause");
}

void sobre(void){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t################################################\n");
    printf("\t\t\t\t\t\t\t#     DESENVOLVEDOR: RAFAEL QUEIROZ SANTOS     #\n");
    printf("\t\t\t\t\t\t\t#     MOTIVO: AVALIA��O FINAL DE ALGORITMOS    #\n");
    printf("\t\t\t\t\t\t\t################################################\n");
    printf("\n\n");
    system("pause");
}

void saida(void){
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t################################################\n");
        printf("\t\t\t\t\t\t\t#           VOC� EST� SAINDO DO JOGO           #\n");
        printf("\t\t\t\t\t\t\t################################################\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("pause");
}
