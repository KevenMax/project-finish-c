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
void painel_jogada(int *P_pont_rodada, char *P_mostrar_letras,char *P_letras_digitadas, int *P_cont_letras);
void sleep(time_t delay);
void painel(int *P_pont_rodada);
void cadastro_player();
void sorteio_pontuacao();
void painel_inicio(char *P);

int main(){
setlocale(LC_ALL, "Portuguese");
int op,ganhador,cont_letras;

/*vetores*/

/*variaveis usadas na funcao do sorteio*/
int pontos_rodada=0;

    /*inciando o menu do jogo*/
    do{
        painel(&op);
        if(op<0||op>1){
            printf("\nOpção Inválida! Digite outra opção!\n");
            system("pause");
            system("cls");
        }
    }while(op<0||op>1);

    /*iniando algumas variaveis antes de comecar o jogo:*/
    play1.pontos = 0; play2.pontos = 0, cont_letras=0;

    char mostrar_letras[16]="_______________";
    char letras_digitadas[20]={"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};

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
            /*funcao para exobor o priemiro painel*/
            painel_inicio(mostrar_letras);
            /*loop do sorteio ate sair um vencedor, caso houver um vencedor, volta pro menu do jogo*/
            ganhador=1;
            do{
                sorteio_pontuacao(&pontos_rodada);

                painel_jogada(&pontos_rodada,mostrar_letras,letras_digitadas,&cont_letras);
            }while(ganhador==1);

        }

return 0;
}

void painel(int *P){

    //system("start arquivos/roda_roda.mp3");
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

void painel_inicio(char *P){
    int z;

    for(z=0;z<16;z++){
        if(z<strlen(vet_resposta))
            P[z]='_';
        else
            P[z]=' ';
    }

        printf(" ---------------------------------------------------------------------------------------------\n");
        printf("|                                                                    |      PLACAR ATUAL      |\n");
        printf("|                                                                    | -----------------------|\n");
        printf("|           APERTE QUALQUER TECLA PARA SORTEAR A PONTUAÇÃO           |  %10s  : %4d    |\n",play1.nome,play1.pontos);
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
        printf("|                x        %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c                     x                 |\n",P[0],P[1],P[2],P[3],P[4],P[5],P[6],P[7],P[8],P[9],P[10],P[11],P[12],P[13],P[14]);
        printf("|                x                                                          x                 |\n");
        printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
        printf("|                                                                                             |\n");
        printf("|                                                                                             |\n");
        printf("|---------------------------------------------------------------------------------------------|\n");
        system("pause");
        system("cls");
}

void painel_jogada(int *P_pont_rodada, char *P_mostrar_letras,char *P_letras_digitadas,int *P_cont_letras){
    /*contadores*/
    int z,y;

    char resposta[20];

    char letra;
    int sair;

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
        printf("|                x        %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c                     x                 |\n",P_mostrar_letras[0],P_mostrar_letras[1],P_mostrar_letras[2],P_mostrar_letras[3],P_mostrar_letras[4],P_mostrar_letras[5],P_mostrar_letras[6],P_mostrar_letras[7],P_mostrar_letras[8],P_mostrar_letras[9],P_mostrar_letras[10],P_mostrar_letras[11],P_mostrar_letras[12],P_mostrar_letras[13],P_mostrar_letras[14]);
        printf("|                x                                                          x                 |\n");
        printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
        printf("|                                                                                             |\n");
        printf("|                                                                                             |\n");
        printf("|---------------------------------------------------------------------------------------------|\n");
        printf("|LETRAS JA DIGITADAS: %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c|\n",P_letras_digitadas[0],P_letras_digitadas[1],P_letras_digitadas[2],P_letras_digitadas[3],P_letras_digitadas[4],P_letras_digitadas[5],P_letras_digitadas[6],P_letras_digitadas[7],P_letras_digitadas[8],P_letras_digitadas[9],P_letras_digitadas[10],P_letras_digitadas[11],P_letras_digitadas[12],P_letras_digitadas[13],P_letras_digitadas[14],P_letras_digitadas[15],P_letras_digitadas[16],P_letras_digitadas[17],P_letras_digitadas[18],P_letras_digitadas[19]);
        printf(" ---------------------------------------------------------------------------------------------\n");
        printf("Digite uma letra: ");
        scanf(" %c",&letra);

        /*TESTE PRA VE SE TEM ALGUMA LETRA JÁ DIGITADA*/
        for(z=0;z<20;z++){
            if(P_letras_digitadas[z]==letra){
                printf("Letra ja foi digitada...\n\n");
                sair=1;
                system("pause");
                break;
            }
        }

    system("cls");
    }while(sair==1);
    printf("\n\n\n%d\n\n",*P_cont_letras);
    system("pause");
    P_letras_digitadas[*P_cont_letras]=letra;
    *P_cont_letras=*P_cont_letras + 1;

    system("cls");


    for(z=0;z<strlen(vet_resposta);z++){
        if(vet_resposta[z]==letra)
            P_mostrar_letras[z]=letra;
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
    printf("|                x        %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c                     x                 |\n",P_mostrar_letras[0],P_mostrar_letras[1],P_mostrar_letras[2],P_mostrar_letras[3],P_mostrar_letras[4],P_mostrar_letras[5],P_mostrar_letras[6],P_mostrar_letras[7],P_mostrar_letras[8],P_mostrar_letras[9],P_mostrar_letras[10],P_mostrar_letras[11],P_mostrar_letras[12],P_mostrar_letras[13],P_mostrar_letras[14]);
    printf("|                x                                                          x                 |\n");
    printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
    printf("|                                                                                             |\n");
    printf("|                                                                                             |\n");
    printf(" ---------------------------------------------------------------------------------------------\n");
    printf("|LETRAS JA DIGITADAS: %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c|\n",P_letras_digitadas[0],P_letras_digitadas[1],P_letras_digitadas[2],P_letras_digitadas[3],P_letras_digitadas[4],P_letras_digitadas[5],P_letras_digitadas[6],P_letras_digitadas[7],P_letras_digitadas[8],P_letras_digitadas[9],P_letras_digitadas[10],P_letras_digitadas[11],P_letras_digitadas[12],P_letras_digitadas[13],P_letras_digitadas[14],P_letras_digitadas[15],P_letras_digitadas[16],P_letras_digitadas[17],P_letras_digitadas[18],P_letras_digitadas[19]);
    printf(" ---------------------------------------------------------------------------------------------\n");

    system("pause");
    system("cls");
}

void sorteio_pontuacao(int *P_pont_rodada){
srand(time(NULL));
/*contadores*/
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
        /*BRUXA V[7] == 0*/
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

if(j==7){
    system("pause");
    system("cls");
}




*P_pont_rodada = valores_pontos[v[7]];
}
