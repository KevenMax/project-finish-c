#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct player{
    char nome[30];
    int pontos;
};

/*variaveis globais*/
struct player play1,play2;
char vet_pergunta[16],vet_resposta[16];

/*funcoes usadas*/
void painel_jogada(int *P);
void sleep(time_t delay);
void painel(int *P_pont_rodada);
void cadastro_player();
void sorteio_pontuacao();
void start();

int main(){
setlocale(LC_ALL, "Portuguese");
int op,ganhador;

/*variaveis usadas na funcao do sorteio*/
int pontos_rodada=0;

    /*inciando o menu do jogo*/
    do{
        painel(&op);
        if(op<0||op>2){
            printf("\nOpção Inválida! Digite outra opção!\n");
            system("pause");
            system("cls");
        }
    }while(op<0||op>1);
    /*iniando algumas variaveis antes de comecar o jogo:*/
    play1.pontos = 0; play2.pontos = 0;

        /*sair do jogo -> 0*/
        if(op==0){
            system("cls");
            printf("Saindo...");
            exit(0);
        }

        /*iniciar o jogo ->1*/
        if(op==1){
            /*cadastro dos players*/
            cadastro_player();
            /*carregando a palavra a ser decifrada*/
            carregar_arquivo();

            /*loop do sorteio ate sair um vencedor, caso houver um vencedor, volta pro menu do jogo*/
            ganhador=1;
            do{
                painel_jogada(&pontos_rodada);
                sorteio_pontuacao(&pontos_rodada);
            }while(ganhador==1);
        }

return 0;
}

void painel(int *P){

    system("start arquivos/roda_roda.mp3");
    /*int op;*/
    puts("");
    puts("               *********    ***********    ********           ******                             ");
    puts("               ***   ***    ***********    **********        ********                            ");
    puts("               ***   ***    ***     ***    ***     ***      ***    ***                           ");
    puts("               *********    ***     ***    ***     ***     ***      ***                          ");
    puts("               ******       ***     ***    ***     ***    **************                         ");
    puts("               ** ****      ***********    **********    ***          ***                        ");
    puts("               ***  ****    ***********    ********     ***            ***                       ");
    puts("");
    puts("                                      **  **                                                      ");
    puts("                                       ****                                                       ");
    puts("                                       ****                                                       ");
    puts("                                      **  **                                                      ");
    puts("");
    puts("               *********    ***********    ********           ******                              ");
    puts("               ***   ***    ***********    **********        ********                             ");
    puts("               ***   ***    ***     ***    ***     ***      ***    ***                            ");
    puts("               *********    ***     ***    ***     ***     ***      ***                           ");
    puts("               ******       ***     ***    ***     ***    **************                          ");
    puts("               ** ****      ***********    **********    ***          ***                         ");
    puts("               ***  ****    ***********    ********     ***            ***                        ");
    puts("");
    puts("               |-----------------------------------------------------------|     ");
    puts("               |                       0 - Sair                            |    ");
    puts("               |                       1 - Iniciar                         |    ");
    puts("               |                       2 - Ranking                         |    ");
    puts("               |-----------------------------------------------------------|    ");
    printf("               Digite sua opção: ");
    scanf("%d",&*P);
    /*op_menu(op);*/

}

void cadastro_player(){
    system("start arquivos/null.mp3");
    system("cls");
    printf("               Digite o Player 1:");
    scanf(" %29[^\n]s", play1.nome);
    printf("               Digite o Player 2:");
    scanf(" %29[^\n]s", play2.nome);

}

void carregar_arquivo(){
    FILE *fp;
    int sort;
    char url_tema[16] = {'a','r','q','u','i','v','o','s','/','P',' ','.','t','x','t'},t;
    char url_resposta[16] = {'a','r','q','u','i','v','o','s','/','R',' ','.','t','x','t'};

    system("cls");
    printf("\n \n \n \n");
    puts("                                      Iniciando o Jogo...");
    sleep(2);
    system("cls");


    srand(time(NULL));
    sort = rand() % 3;

    url_resposta[10] = url_tema[10] = sort + '0';

    /*carregando um tema*/
    fp = fopen(url_tema, "r");
    if (fp == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       exit(0);
    }
    else{
         while(fscanf(fp,"%s",vet_pergunta)!= EOF){
            printf(" ");
         }
    }
    fclose (fp);
    /*carregando a resposta do tema acima*/
    fp = fopen(url_resposta, "r");
    if (fp == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       exit(0);
    }
    else{
         while(fscanf(fp,"%s",vet_resposta)!= EOF)
            printf(" ");
    }
    fclose (fp);
}

void sleep(time_t delay){
    time_t timer0, timer1;
    time(&timer0);
    do{
        time(&timer1);
    }while((timer1-timer0) < delay);
}

void painel_jogada(int *P_pont_rodada){
    /*contadores*/
    int z,y;

    char resposta[20];
    char letras_digitadas[26]={"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
    char mostrar_letras[16]="_______________";
    char letra;
    printf("%s\n\n",letras_digitadas);
    int sair;

    for(z=0;z<16;z++){
        if(z<strlen(vet_resposta))
            mostrar_letras[z]='_';
        else
            mostrar_letras[z]=' ';
    }


    do{
        sair=0;

        printf(" ---------------------------------------------------------------------------------------------\n");
        printf("|                                                                    |      PLACAR ATUAL      |\n");
        printf("|                                                                    | -----------------------|\n");
        printf("|           ESSA RODADA VALE %3d PONTOS POR LETRA                    |  %10s  : %4d    |\n",*P_pont_rodada,play1.nome,play1.pontos);
        printf("|                                                                    |                        |\n");
        printf("|                                                                    |  %10s  : %4d    |\n",play2.nome,play2.pontos);
        printf("|---------------------------------------------------------------------------------------------\n");
        printf("|                                                                                             |\n");
        printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
        printf("|                x                                                          x                 |\n");
        printf("|                x               TEMA ->%20s                x                 |\n",vet_pergunta);
        printf("|                x                                                          x                 |\n");
        printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
        printf("|                x                                                          x                 |\n");
        printf("|                x        %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c                     x                 |\n",mostrar_letras[0],mostrar_letras[1],mostrar_letras[2],mostrar_letras[3],mostrar_letras[4],mostrar_letras[5],mostrar_letras[6],mostrar_letras[7],mostrar_letras[8],mostrar_letras[9],mostrar_letras[10],mostrar_letras[11],mostrar_letras[12],mostrar_letras[13],mostrar_letras[14]);
        printf("|                x                                                          x                 |\n");
        printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
        printf("|                                                                                             |\n");
        printf("|                                                                                             |\n");
        printf("|---------------------------------------------------------------------------------------------|\n");
        printf("|LETRAS JA DIGITADAS:                                                                         |\n");
        printf(" ---------------------------------------------------------------------------------------------\n");
        printf("Digite uma letra: ");
        scanf(" %c",&letra);

        for(z=0;z<26;z++){
            if(letras_digitadas[z]==letra){
                printf("Letra ja foi digitada...\n\n");
                sair=1;
                system("pause");
                break;
            }
        }
    system("cls");
    }while(sair==1);

    system("cls");

    /*TESTE PRA VE SE TEM ALGUMA LETRA JÁ DIGITADA*/
    /*for(z=0;z<strlen())*/
    for(z=0;z<strlen(resposta);z++){
        if(resposta[z]==letra)
            mostrar_letras[z]=letra;
    }
    printf(" ---------------------------------------------------------------------------------------------\n");
    printf("|                                                                    |      PLACAR ATUAL      |\n");
    printf("|                                                                    | -----------------------|\n");
    printf("|           ESSA RODADA VALE %3d PONTOS POR LETRA                    |    Player 1: %4d      |\n",*P_pont_rodada,play1.pontos);
    printf("|                                                                    |                        |\n");
    printf("|                                                                    |    Player 2: %4d      |\n",play2.pontos);
    printf("|---------------------------------------------------------------------------------------------\n");
    printf("|                                                                                             |\n");
    printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
    printf("|                x                                                          x                 |\n");
    printf("|                x               TEMA ->%20s                x                 |\n",vet_pergunta);
    printf("|                x                                                          x                 |\n");
    printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
    printf("|                x                                                          x                 |\n");
    printf("|                x        %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c                     x                 |\n",mostrar_letras[0],mostrar_letras[1],mostrar_letras[2],mostrar_letras[3],mostrar_letras[4],mostrar_letras[5],mostrar_letras[6],mostrar_letras[7],mostrar_letras[8],mostrar_letras[9],mostrar_letras[10],mostrar_letras[11],mostrar_letras[12],mostrar_letras[13],mostrar_letras[14]);
    printf("|                x                                                          x                 |\n");
    printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
    printf("|                                                                                             |\n");
    printf("|                                                                                             |\n");
    printf(" ---------------------------------------------------------------------------------------------\n");
}

void sorteio_pontuacao(int *P_pont_rodada){
srand(time(NULL));

int i,j,cres;
int valores_pontos[25]={10,10,15,20,20,25,30,30,40,40,40,50,50,60,60,70,75,80,80,90,100,1,1,1,0};
int v[15];

for(j=0;j<7;j++){
    for(i=0;i<15;i++){
        v[i]=rand()%25;

    }
    if(j<6){
        /*VISUAL DO SORTEIO 1*/
        if(j%2==0){
                printf("\n\n                 --------------------------------------------------------------------\n");
                    printf("                 ||       BRUXA   = 0    ||      -> PERDE TUDO E PASSA A VEZ!      ||\n");
                    printf("                 --------------------------------------------------------------------\n");
                    printf("                 ||     AZARENTO  = 1    ||      ->     PASSA A VEZ!               ||\n");
                    printf("                 --------------------------------------------------------------------\n");
                    printf("\n");
                    printf("                                                  ___                          \n");
                    printf("                                                 |   |                           \n");
                    printf("                                                 |   |                           \n");
                    printf("                                              _ _|   |_ _                        \n");
                    printf("                                              \\         /                        \n");
                    printf("                                               \\       /                         \n");
                    printf("                                                \\     /                          \n");
                    printf("                                                 \\   /                           \n");
                    printf("                                                  \\ /                            \n");
                    printf("                                                   v                                       \n");
                    printf("                                                                                      \n");
                    printf("      *******-----*******-----*******-----*******-----*******-----*******-----*******-----*******\n");
                    printf("      *     *     *     *     *     *     *     *     *     *     *     *     *     *     *     *\n");
                    printf("      * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d *\n",valores_pontos[v[0]],valores_pontos[v[1]],valores_pontos[v[2]],valores_pontos[v[3]],valores_pontos[v[4]],valores_pontos[v[5]],valores_pontos[v[6]],valores_pontos[v[7]],valores_pontos[v[8]],valores_pontos[v[9]],valores_pontos[v[10]],valores_pontos[v[11]],valores_pontos[v[12]],valores_pontos[v[13]],valores_pontos[v[14]]);
                    printf("      *     *     *     *     *     *     *     *     *     *     *     *     *     *     *     *\n");
                    printf("      *******-----*******-----*******-----*******-----*******-----*******-----*******-----*******\n");
                    printf("                                                                                      \n");
        }
        /*VISUAL DO SORTEIO 2*/
        else{
                printf("\n\n                 --------------------------------------------------------------------\n");
                    printf("                 ||       BRUXA   = 0    ||      -> PERDE TUDO E PASSA A VEZ!      ||\n");
                    printf("                 --------------------------------------------------------------------\n");
                    printf("                 ||     AZARENTO  = 1    ||      ->     PASSA A VEZ!               ||\n");
                    printf("                 --------------------------------------------------------------------\n");
                    printf("\n");
                    printf("                                                  ___                          \n");
                    printf("                                                 |   |                           \n");
                    printf("                                                 |   |                           \n");
                    printf("                                              _ _|   |_ _                        \n");
                    printf("                                              \\         /                        \n");
                    printf("                                               \\       /                         \n");
                    printf("                                                \\     /                          \n");
                    printf("                                                 \\   /                           \n");
                    printf("                                                  \\ /                            \n");
                    printf("                                                   v                                       \n");
                    printf("                                                                                      \n");
                    printf("       -----*******-----*******-----*******-----*******-----*******-----*******-----*******-----\n");
                    printf("      |     *     *     *     *     *     *     *     *     *     *     *     *     *     *     |\n");
                    printf("      | %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d * %3d |\n",valores_pontos[v[0]],valores_pontos[v[1]],valores_pontos[v[2]],valores_pontos[v[3]],valores_pontos[v[4]],valores_pontos[v[5]],valores_pontos[v[6]],valores_pontos[v[7]],valores_pontos[v[8]],valores_pontos[v[9]],valores_pontos[v[10]],valores_pontos[v[11]],valores_pontos[v[12]],valores_pontos[v[13]],valores_pontos[v[14]]);
                    printf("      |     *     *     *     *     *     *     *     *     *     *     *     *     *     *     |\n");
                    printf("       -----*******-----*******-----*******-----*******-----*******-----*******-----*******-----\n");
                    printf("                                                                                      \n");
        }
    }
    else{
        /*RUXA V[7] == 0*/
        if(valores_pontos[v[7]]==0){
            printf("\n\n                                  ------------------------------------\n");
                printf("                                 |   ****  ****  *   * *   *  ***     |\n");
                printf("                                 |   *   * *   * *   *  * *  *   *    |\n");
                printf("                                 |   ****  ****  *   *   *   *****    |\n");
                printf("                                 |   *   * *  *  *   *  * *  *   *    |\n");
                printf("                                 |   ****  *   *  ***  *   * *   *    |\n");
                printf("                                 |  PERDEU TUDO!!! E PASSOU A VEZ!!!  |\n");
                printf("                                  ------------------------------------ \n");
                printf("                                                  ___                           \n");
                printf("                                                 |***|                           \n");
                printf("                                                 |***|                           \n");
                printf("                                              _ _|***|_ _                        \n");
                printf("                                              \\*********/                        \n");
                printf("                                               \\*******/                         \n");
                printf("                                                \\*****/                          \n");
                printf("                                                 \\***/                           \n");
                printf("                                                  \\*/                            \n");
                printf("                                                   v                                       \n");
                printf("                                               *********                                      \n");
                printf("      ----- ----- ----- ----- ----- ----- -----*********----- ----- ----- ----- ----- ----- -----\n");
                printf("     |     |     |     |     |     |     |     **     **     |     |     |     |     |     |     |\n");
                printf("     | %3d | %3d | %3d | %3d | %3d | %3d | %3d ** %3d ** %3d | %3d | %3d | %3d | %3d | %3d | %3d |\n",valores_pontos[v[0]],valores_pontos[v[1]],valores_pontos[v[2]],valores_pontos[v[3]],valores_pontos[v[4]],valores_pontos[v[5]],valores_pontos[v[6]],valores_pontos[v[7]],valores_pontos[v[8]],valores_pontos[v[9]],valores_pontos[v[10]],valores_pontos[v[11]],valores_pontos[v[12]],valores_pontos[v[13]],valores_pontos[v[14]]);
                printf("     |     |     |     |     |     |     |     **     **     |     |     |     |     |     |     |\n");
                printf("      ----- ----- ----- ----- ----- ----- -----*********----- ----- ----- ----- ----- ----- -----\n");
                printf("                                               *********                                          \n");
        }
        else{
            /*AZARENTO V[7] == 1*/
            if(valores_pontos[v[7]]==1){
            printf("\n\n                          -----------------------------------------------------\n");
                printf("                         |    ***  *****  ***  ****  ***** *   * *****  ***    |\n");
                printf("                         |   *   *    *  *   * *   * *     **  *   *   *   *   |\n");
                printf("                         |   *****   *   ***** ****  ****  * * *   *   *   *   |\n");
                printf("                         |   *   *  *    *   * *  *  *     *  **   *   *   *   |\n");
                printf("                         |   *   * ***** *   * *   * ***** *   *   *    ***    |\n");
                printf("                         |                  PASSOU A VEZ!!!                    |\n");
                printf("                          -----------------------------------------------------\n");
                printf("                                                  ___                           \n");
                printf("                                                 |***|                           \n");
                printf("                                                 |***|                           \n");
                printf("                                              _ _|***|_ _                        \n");
                printf("                                              \\*********/                        \n");
                printf("                                               \\*******/                         \n");
                printf("                                                \\*****/                          \n");
                printf("                                                 \\***/                           \n");
                printf("                                                  \\*/                            \n");
                printf("                                                   v                                       \n");
                printf("                                               *********                                      \n");
                printf("      ----- ----- ----- ----- ----- ----- -----*********----- ----- ----- ----- ----- ----- -----\n");
                printf("     |     |     |     |     |     |     |     **     **     |     |     |     |     |     |     |\n");
                printf("     | %3d | %3d | %3d | %3d | %3d | %3d | %3d ** %3d ** %3d | %3d | %3d | %3d | %3d | %3d | %3d |\n",valores_pontos[v[0]],valores_pontos[v[1]],valores_pontos[v[2]],valores_pontos[v[3]],valores_pontos[v[4]],valores_pontos[v[5]],valores_pontos[v[6]],valores_pontos[v[7]],valores_pontos[v[8]],valores_pontos[v[9]],valores_pontos[v[10]],valores_pontos[v[11]],valores_pontos[v[12]],valores_pontos[v[13]],valores_pontos[v[14]]);
                printf("     |     |     |     |     |     |     |     **     **     |     |     |     |     |     |     |\n");
                printf("      ----- ----- ----- ----- ----- ----- -----*********----- ----- ----- ----- ----- ----- -----\n");
                printf("                                               *********                                          \n");
            }
            /*PONTUAÇAO VALIDA!!*/
            else{
            printf("\n\n                       -----------------------------------------------------\n");
                printf("                      |                     SUA RODADA VALE                 |\n");
                printf("                      |                                                     |\n");
                printf("                      |                       **********                    |\n");
                printf("                      |                       *  %3d   *                    |\n",valores_pontos[v[7]]);
                printf("                      |                       **********                    |\n");
                printf("                      |                     PONTOS POR LETRA                |\n");
                printf("                       -----------------------------------------------------\n");
                printf("                                                  ___                           \n");
                printf("                                                 |***|                           \n");
                printf("                                                 |***|                           \n");
                printf("                                              _ _|***|_ _                        \n");
                printf("                                              \\*********/                        \n");
                printf("                                               \\*******/                         \n");
                printf("                                                \\*****/                          \n");
                printf("                                                 \\***/                           \n");
                printf("                                                  \\*/                            \n");
                printf("                                                   v                                       \n");
                printf("                                               *********                                      \n");
                printf("      ----- ----- ----- ----- ----- ----- -----*********----- ----- ----- ----- ----- ----- -----\n");
                printf("     |     |     |     |     |     |     |     **     **     |     |     |     |     |     |     |\n");
                printf("     | %3d | %3d | %3d | %3d | %3d | %3d | %3d ** %3d ** %3d | %3d | %3d | %3d | %3d | %3d | %3d |\n",valores_pontos[v[0]],valores_pontos[v[1]],valores_pontos[v[2]],valores_pontos[v[3]],valores_pontos[v[4]],valores_pontos[v[5]],valores_pontos[v[6]],valores_pontos[v[7]],valores_pontos[v[8]],valores_pontos[v[9]],valores_pontos[v[10]],valores_pontos[v[11]],valores_pontos[v[12]],valores_pontos[v[13]],valores_pontos[v[14]]);
                printf("     |     |     |     |     |     |     |     **     **     |     |     |     |     |     |     |\n");
                printf("      ----- ----- ----- ----- ----- ----- -----*********----- ----- ----- ----- ----- ----- -----\n");
                printf("                                               *********                                          \n");
            }
        }
    }

    if(j<6){
        sleep(1);
        system("cls");
    }
}

if(j==7)
    system("pause");



*P_pont_rodada = valores_pontos[v[7]];
}
