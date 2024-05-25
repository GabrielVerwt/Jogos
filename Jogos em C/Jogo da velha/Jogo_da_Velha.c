#include <stdio.h>
#include <stdlib.h>

//Funçao tabuleiro
void tabuleiro(char casas2[9]){     //Variavel "casas2" serve para colocar os caracteres que serao substituidos pela "casas"
    system("cls");      //Limpar a tela toda vez que um comando for feito
    printf("    Bem-Vindo ao Jogo da Velha!\n");
    printf("\tAproveite o jogo :)\n\n");

    printf("\t %c | %c | %c\n", casas2[0], casas2[1], casas2[2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n", casas2[3], casas2[4], casas2[5]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n", casas2[6], casas2[7], casas2[8]);
}
//Funçao principal, aqui é onde o jogo funcionará
void main(){
    char casas[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    tabuleiro(casas);       //Faz aparecer o tabuleiro "vazio"
    
    int continuar;  //Variavel que permite continuar o jogo
    int quantidadeJogadas; //Variavel que determina quantas jogadas temos e o limite
    int jogada, vez, i;     //Jogada = qual casa voce marcou / vez = numero de vezes .-. / i serve so pro loop da funcao for()
    do{
        quantidadeJogadas = 1;  //Determina o inicio do jogo
        for(i = 0; i <= 8; i++){       //Limpa todas as casas do tabuleiro
            casas[i] = ' ';
        }
        do{     //Loop do jogo
            tabuleiro(casas);   //Imprime o tabuleiro na tela

            if(vez % 2 == 0){
                printf("\nVez de X\n");     //Diz quando é a vez de quem
            }
            else{
                printf("\nVez de O\n");
            }

            printf("\nDigite a casa para marcar (1 - 9): ");     //O jogador decide em qual casa vai marcar
            scanf("%d", &jogada);

            if(jogada < 1 || jogada > 9){   //Caso digite um valor invalido
                jogada = 0;
            }
            else if(casas[jogada - 1] != ' '){      //Caso a casa escolhida anteriormente nao for vazia
                jogada = 0;                         //O "jogada - 1" que aparece é pq a posicao da casa começa em "0"
            }
            else{       //Se a vez for um numero par, entao marca 'X', se nao, marca 'O'
                if(vez % 2 == 0){
                    casas[jogada - 1] = 'X';
                }
                else{
                    casas[jogada - 1] = 'O';
                }
                quantidadeJogadas++;    //Aumenta o numero da jogada para cada vez que for digitado um numero
                vez++;      //Aumenta o numero da vez, fazendo com que se alterne entre 'X' e 'O'
            }
            //Condiçao de vitoria para 'X'
            if(casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X'){quantidadeJogadas = 11;}
            if(casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X'){quantidadeJogadas = 11;}
            if(casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X'){quantidadeJogadas = 11;}
            if(casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X'){quantidadeJogadas = 11;}
            if(casas[1] == 'X' && casas[4] == 'X' && casas[7] == 'X'){quantidadeJogadas = 11;}
            if(casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X'){quantidadeJogadas = 11;}
            if(casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X'){quantidadeJogadas = 11;}
            if(casas[2] == 'X' && casas[4] == 'X' && casas[6] == 'X'){quantidadeJogadas = 11;}
            //Condiçao de vitoria para 'O'
            if(casas[0] == 'O' && casas[1] == 'O' && casas[2] == 'O'){quantidadeJogadas = 12;}
            if(casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O'){quantidadeJogadas = 12;}
            if(casas[6] == 'O' && casas[7] == 'O' && casas[8] == 'O'){quantidadeJogadas = 12;}
            if(casas[0] == 'O' && casas[3] == 'O' && casas[6] == 'O'){quantidadeJogadas = 12;}
            if(casas[1] == 'O' && casas[4] == 'O' && casas[7] == 'O'){quantidadeJogadas = 12;}
            if(casas[2] == 'O' && casas[5] == 'O' && casas[8] == 'O'){quantidadeJogadas = 12;}
            if(casas[0] == 'O' && casas[4] == 'O' && casas[8] == 'O'){quantidadeJogadas = 12;}
            if(casas[2] == 'O' && casas[4] == 'O' && casas[6] == 'O'){quantidadeJogadas = 12;} 

        }while(quantidadeJogadas <= 9);
        tabuleiro(casas);   //Printa a jogada feita
        if(quantidadeJogadas == 10){
            printf("\nJogo empatado\n");
        }
        if(quantidadeJogadas == 11){
            printf("\nVitoria de X\n");
        }
        if(quantidadeJogadas == 12){
            printf("\nVitoria de O\n");
        }
        printf("\nContinuar? (1 = sim, 0 = nao): ");     //Continuar
        scanf("%d", &continuar);
        
        if(continuar == 0){
            printf("\n---------Fim de Jogo-------\n\n");
        }
    }while(continuar == 1);
}