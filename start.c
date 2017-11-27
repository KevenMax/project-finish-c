#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

struct player{
    char nome[13];
    int pontos;
};

/*variaveis globais*/
struct player play1,play2;

char *vet_pergunta,*vet_resposta;
int play_atual,play_esperando;

/*funcoes usadas*/

void sleep(time_t delay);
void painel(int *P_op);
void cadastro_player(void);
void carregar_arquivo(void);
void painel_inicio(char *P);
void sorteio_pontuacao(int *P_pont_rodada);
void painel_jogada(int *P_pont_rodada, char *P_mostrar_letras,char *P_letras_digitadas, int *P_cont_letras, int *P_ver_ganhador);
void mostra_play_atual(int *P_pont_rodada);

int main(void){
setlocale(LC_ALL, "Portuguese");
int op,ver_ganhador,cont_letras,troca;

/*variaveis usadas na funcao do sorteio*/
int pontos_rodada=0;
do{
    /*inciando o menu do jogo*/
    do{
        painel(&op);
        if(op<0||op>2){
            printf("\nOpção Inválida! Digite outra opção!\n");
            system("pause");
            system("cls");
        }
    }while(op<0||op>2);

    /*iniando algumas variaveis antes de comecar o jogo:*/
    play1.pontos = 0; play2.pontos = 0; cont_letras=0;play_atual=1;play_esperando=2;

    /*declarando e iniciando alguns vetores*/
    char mostrar_letras[16];
    char letras_digitadas[19]={"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};

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
            ver_ganhador=0;
            do{
                sorteio_pontuacao(&pontos_rodada);
                painel_jogada(&pontos_rodada,mostrar_letras,letras_digitadas,&cont_letras,&ver_ganhador);
                if(ver_ganhador!=1){
                    mostra_play_atual(&pontos_rodada);
                }
            }while(ver_ganhador==0);

            if(play1.pontos>play2.pontos){
                printf(" ---------------------------------------------------------------------------------------------\n");
                printf("|                                                                                             |\n");
                printf("|                    ++   ***************************************   ++                        |\n");
                printf("|                  +++++  ***************************************  +++++                      |\n");
                printf("|                 ++  ++++***************************************++++  ++                     |\n");
                printf("|                ++     ++***************************************++     ++                    |\n");
                printf("|               ++       +***************************************+       ++                   |\n");
                printf("|              ++         ***************************************         ++                  |\n");
                printf("|               ++         *************************************         ++                   |\n");
                printf("|                ++         ***********************************         ++                    |\n");
                printf("|                  ++        *********************************        ++                      |\n");
                printf("|                    ++++     *******************************     ++++                        |\n");
                printf("|                        ++++   ***************************   ++++                            |\n");
                printf("|                           +++   ***********************   +++                               |\n");
                printf("|                             ++++  *******************  ++++                                 |\n");
                printf("|                                 +++ *************** +++                                     |\n");
                printf("|                                    +++***********+++                                        |\n");
                printf("|                                        ********                                             |\n");
                printf("|                                         ******                                              |\n");
                printf("|                                       ***********                                           |\n");
                printf("|                                      *************                                          |\n");
                printf("|                                   *******************                                       |\n");
                printf("|                                  +++++++++++++++++++++                                      |\n");
                printf("|                                  +++++++++++++++++++++                                      |\n");
                printf("|                              +++++++++++++++++++++++++++++                                  |\n");
                printf("|                              +++++++++++++++++++++++++++++                                  |\n");
                printf("|                                                                                             |\n");
                printf("|                                                                                             |\n");
                printf("|                           CAMPEÃO: %12s, COM %3d PONTOS...                          |\n",play1.nome,play1.pontos);
                printf("|                                                                                             |\n");
                printf(" ---------------------------------------------------------------------------------------------\n");


            }
            else{
                if(play1.pontos<play2.pontos){
                        printf(" ---------------------------------------------------------------------------------------------\n");
                        printf("|                                                                                             |\n");
                        printf("|                    ++   ***************************************   ++                        |\n");
                        printf("|                  +++++  ***************************************  +++++                      |\n");
                        printf("|                 ++  ++++***************************************++++  ++                     |\n");
                        printf("|                ++     ++***************************************++     ++                    |\n");
                        printf("|               ++       +***************************************+       ++                   |\n");
                        printf("|              ++         ***************************************         ++                  |\n");
                        printf("|               ++         *************************************         ++                   |\n");
                        printf("|                ++         ***********************************         ++                    |\n");
                        printf("|                  ++        *********************************        ++                      |\n");
                        printf("|                    ++++     *******************************     ++++                        |\n");
                        printf("|                        ++++   ***************************   ++++                            |\n");
                        printf("|                           +++   ***********************   +++                               |\n");
                        printf("|                             ++++  *******************  ++++                                 |\n");
                        printf("|                                 +++ *************** +++                                     |\n");
                        printf("|                                    +++***********+++                                        |\n");
                        printf("|                                        ********                                             |\n");
                        printf("|                                         ******                                              |\n");
                        printf("|                                       ***********                                           |\n");
                        printf("|                                      *************                                          |\n");
                        printf("|                                   *******************                                       |\n");
                        printf("|                                  +++++++++++++++++++++                                      |\n");
                        printf("|                                  +++++++++++++++++++++                                      |\n");
                        printf("|                              +++++++++++++++++++++++++++++                                  |\n");
                        printf("|                              +++++++++++++++++++++++++++++                                  |\n");
                        printf("|                                                                                             |\n");
                        printf("|                                                                                             |\n");
                        printf("|                           CAMPEÃO: %12s, COM %3d PONTOS...                          |\n",play2.nome,play2.pontos);
                        printf("|                                                                                             |\n");
                        printf(" ---------------------------------------------------------------------------------------------\n");
                }
                else{
                        printf(" ---------------------------------------------------------------------------------------------\n");
                        printf("|                                                                                             |\n");
                        printf("|                                      EMPATE!!!                                              |\n");
                        printf("|                        OS DOIS PLAYERS FORAM CAMEPEÕES!!!                                   |\n");
                        printf(" ---------------------------------------------------------------------------------------------\n");
                }
            }
        }
        if(op==2){
                system("cls");
                printf("***************************************\n");
                printf("*         DESENVOLVIDO POR:           *\n");
                printf("*         - KEVEN MAX                 *\n");
                printf("*         - LUIS FERNANDO             *\n");
                printf("***************************************\n");
                printf("*              VERSÃO                 *\n");
                printf("*                1.0                  *\n");
                printf("*                                     *\n");
                printf("***************************************\n");
                ver_ganhador=1;
        }

system("pause");
system("cls");
}while(ver_ganhador==1);
return 0;
}

void sleep(time_t delay){
    time_t timer0, timer1;
    time(&timer0);
    do{
        time(&timer1);
    }while((timer1-timer0) < delay);
}

void painel(int *P_op){

    system("start arquivos/roda_roda.mp3");
        puts("");
        puts("*********     *********     ********           ******                             ");
        puts("***   ***    ***********    **********        ********                            ");
        puts("***   ***    ***     ***    ***     ***      ***    ***                           ");
        puts("********     ***     ***    ***     ***     ************                         ");
        puts("******       ***     ***    ***     ***    **************                         ");
        puts("** ****      ***********    **********    ***          ***                        ");
        puts("***  ****     *********     ********     ***            ***                       ");
        puts("");
        puts("                 ****   *****   *****                                                        ");
        puts("                 ****  **  *** **  ***                                                       ");
        puts("                   **  ** * ** ** * **                                                        ");
        puts("                   **  ***  ** ***  **                                                    ");
        puts("                   **   *****   *****                                                        ");
        puts("");
        puts("*********     *********     ********           ******                              ");
        puts("***   ***    ***********    **********        ********                             ");
        puts("***   ***    ***     ***    ***     ***      ***    ***                            ");
        puts("*********    ***     ***    ***     ***     ************                          ");
        puts("******       ***     ***    ***     ***    **************                          ");
        puts("** ****      ***********    **********    ***          ***                         ");
        puts("***  ****     *********     ********     ***            ***                        ");
        puts("");
        puts("|-----------------------------------------------------------|     ");
        puts("|                       0 - Sair                            |    ");
        puts("|                       1 - Iniciar                         |    ");
        puts("|                       2 - Sobre                           |    ");
        puts("|-----------------------------------------------------------|    ");
      printf("Digite sua opção: ");
        scanf(" %d",&*P_op);
}

void cadastro_player(void){
    system("start arquivos/null.mp3");
    system("cls");
      printf("\n|---------------------------------------------------------------------------------------------|\n");
        printf("                                                                                               \n");
        printf("                Digite o Player 1: ");
        scanf(" %12[^\n]s", play1.nome);
        printf("                Digite o Player 2: ");
        scanf(" %12[^\n]s", play2.nome);

}

void carregar_arquivo(void){
    FILE *fp;

    char letra;
    int sort,contagem;
    char url_tema[16] = {'a','r','q','u','i','v','o','s','/','P',' ','.','t','x','t'};
    char url_resposta[16] = {'a','r','q','u','i','v','o','s','/','R',' ','.','t','x','t'};

    srand(time(NULL));
    sort = rand() % 3;

    url_resposta[10] = url_tema[10] = sort + '0';

    /*carregando um tema*/
    fp = fopen(url_tema, "r");
    if (fp == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       exit(0);
    }

    /*descobrir quantos caracteres tem o tema carregado*/
    contagem=0;
    do{
        letra=fgetc(fp);
        if(letra!=EOF)
            contagem++;
    }while(letra!=EOF);
    fclose(fp);

    /*fazendo alocacao dinamica de acordo com a quantidade de caracteres do tema*/
    vet_pergunta=(char*) malloc(sizeof(char)*contagem);

    /*salvando o tema no vet_pergunta dinmico*/
    fp = fopen(url_tema, "r");
    while(fscanf(fp,"%s",vet_pergunta)!=EOF){
        strupr(vet_pergunta);
    }
    fclose (fp);

    /*carregando a resposta do tema acima*/
    fp = fopen(url_resposta, "r");
    if (fp == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       exit(0);
    }

    /*descobrir quantos caracteres tem a resposta*/
    contagem=0;
    do{
        letra=fgetc(fp);
        if(letra!=EOF)
            contagem++;
    }while(letra!=EOF);
    fclose(fp);

    /*fazendo alocacao dinamica de acordo com a quantidade de caracteres do tema*/
    vet_resposta=(char*) malloc(sizeof(char)*contagem);

    /*salvando o tema no vet_resposta dinmico*/
    fp = fopen(url_resposta, "r");
    while(fscanf(fp,"%s",vet_resposta)!= EOF){
      strupr(vet_resposta);
    }
    fclose (fp);
}

void painel_inicio(char *P){
    int z;

    system("cls");
      printf("\n|---------------------------------------------------------------------------------------------|\n");
        printf("|                                                                    |                        |\n");
        printf("|                                                                    | -----------------------|\n");
        printf("|                       INCIANDO O GAME...                           |                        |\n");
        printf("|                                                                    |                        |\n");
        printf("|                                                                    |                        |\n");
        printf("|---------------------------------------------------------------------------------------------\n");
        printf("|                                                                                             |\n");
        printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
        printf("|                x                                                          x                 |\n");
        printf("|                x                                                          x                 |\n");
        printf("|                x                                                          x                 |\n");
        printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
        printf("|                x                                                          x                 |\n");
        printf("|                x                                                          x                 |\n");
        printf("|                x                                                          x                 |\n");
        printf("|                xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 |\n");
        printf("|                                                                                             |\n");
        printf("|                                                                                             |\n");
        printf("|---------------------------------------------------------------------------------------------|\n");
    sleep(2);
    system("cls");

    for(z=0;z<15;z++){
        if(z<strlen(vet_resposta))
            P[z]='_';
        else
            P[z]=' ';
    }
    P[z]='\0';
        printf("\n|---------------------------------------------------------------------------------------------|\n");
        printf("|        Boa sorte a todos! Observem o tema dessa rodada.            |      PLACAR ATUAL      |\n");
        printf("|                                                                    | -----------------------|\n");
        printf("|       A reposta correspondente ao tema possui%2d letras             |%12s  : %4d    |\n",strlen(vet_resposta),play1.nome,play1.pontos);
        printf("|                                                                    |                        |\n");
        printf("|               O Player 1 sempre começa a 1º rodada.                |%12s  : %4d    |\n",play2.nome,play2.pontos);
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

void sorteio_pontuacao(int *P_pont_rodada){
srand(time(NULL));
/*contadores*/
int i,j,cres;

int valores_pontos[25]={10,10,15,20,20,25,30,30,30,40,45,50,50,60,60,70,75,20,80,90,100,1,1,1,0};
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

void painel_jogada(int *P_pont_rodada, char *P_mostrar_letras,char *P_letras_digitadas,int *P_cont_letras, int *P_ver_ganhador){
    /*contadores*/
    int z,y,sair,teste_letra,troca;


    char letra;

    /*verificar se deu bruxa,azarento ou uma pontuação válida*/

    /*comando caso -> bruxa*/
    if(*P_pont_rodada==0){
            if(play_atual==1){
                play1.pontos=0;
            }
            else{
                play2.pontos=0;
            }
            troca=play_atual;
            play_atual=play_esperando;
            play_esperando=troca;

    }
    else{
        /*comando caso -> azarento*/
        if(*P_pont_rodada==1){
            troca=play_atual;
            play_atual=play_esperando;
            play_esperando=troca;
        }
        /*comando caso -> pontuacao valida*/
        else{
                    /*painel para digitar uma letra*/
                    do{
                            sair=0;

                            printf(" ---------------------------------------------------------------------------------------------\n");
                            printf("|                                                                    |      PLACAR ATUAL      |\n");
                            printf("|                                                                    | -----------------------|\n");
                            printf("|           ESSA RODADA VALE %3d PONTOS POR LETRA                    |%12s  : %4d    |\n",*P_pont_rodada,play1.nome,play1.pontos);
                            printf("|                                                                    |                        |\n");
                            printf("|                                                                    |%12s  : %4d    |\n",play2.nome,play2.pontos);
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
                            printf("|LETRAS JA DIGITADAS: %c- %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c|\n",P_letras_digitadas[0],P_letras_digitadas[1],P_letras_digitadas[2],P_letras_digitadas[3],P_letras_digitadas[4],P_letras_digitadas[5],P_letras_digitadas[6],P_letras_digitadas[7],P_letras_digitadas[8],P_letras_digitadas[9],P_letras_digitadas[10],P_letras_digitadas[11],P_letras_digitadas[12],P_letras_digitadas[13],P_letras_digitadas[14],P_letras_digitadas[15],P_letras_digitadas[16],P_letras_digitadas[17],P_letras_digitadas[18]);
                            printf(" ---------------------------------------------------------------------------------------------\n");
                            sleep(7);
                            system("cls");
                            printf("Digite uma letra: ");
                            scanf(" %c",&letra);
                            letra=toupper(letra);

                            /*TESTE PRA VE SE TEM ALGUMA LETRA JÁ DIGITADA = S -> solicita novamente uma letra*/
                            for(z=0;z<19;z++){
                                if(P_letras_digitadas[z]==letra){
                                    printf("Letra ja foi digitada...\n\n");
                                    sair=1;
                                    system("pause");
                                    break;
                                }
                            }

                        system("cls");
                    /*fim do painel que solicita uma letra*/
                    }while(sair==1);

                    P_letras_digitadas[*P_cont_letras]=letra;   /*atribui a letra digitada ao vetor de letras_digitadas e depois incrementa 1 ao seu contador*/
                    *P_cont_letras=*P_cont_letras + 1;

                    /*verificando a letra com a resposta do tema*/
                    teste_letra = 0;
                    for(z=0;z<strlen(vet_resposta);z++){
                        if(vet_resposta[z]==letra){
                            P_mostrar_letras[z]=letra;
                            teste_letra++;
                        }
                    }

                    /*se tiver a letra */
                    if(teste_letra>0){
                            /*atualizar a pontuação de acordo com o play atual*/
                            if(play_atual==1){
                                play1.pontos+=teste_letra**P_pont_rodada;
                            }
                            else{
                                play2.pontos+=teste_letra**P_pont_rodada;
                            }

                            printf(" ---------------------------------------------------------------------------------------------\n");
                            printf("|                                                                    |      PLACAR ATUAL      |\n");
                            printf("|                   Você acertou %d letra(s):                         | -----------------------|\n",teste_letra);
                            printf("|                                                                    |%12s  : %4d    |\n",play1.nome,play1.pontos);
                            printf("|                        GANHOU %3d PONTOS                           |                        |\n",teste_letra**P_pont_rodada);
                            printf("|                                                                    |%12s  : %4d    |\n",play2.nome,play2.pontos);
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
                            printf("|LETRAS JA DIGITADAS: %c- %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c|\n",P_letras_digitadas[0],P_letras_digitadas[1],P_letras_digitadas[2],P_letras_digitadas[3],P_letras_digitadas[4],P_letras_digitadas[5],P_letras_digitadas[6],P_letras_digitadas[7],P_letras_digitadas[8],P_letras_digitadas[9],P_letras_digitadas[10],P_letras_digitadas[11],P_letras_digitadas[12],P_letras_digitadas[13],P_letras_digitadas[14],P_letras_digitadas[15],P_letras_digitadas[16],P_letras_digitadas[17],P_letras_digitadas[18]);
                            printf(" ---------------------------------------------------------------------------------------------\n");

                    sleep(5);
                    system("cls");

                    /*verificando se a reposta já foi decifrada*/
                    y=0;
                    for(z=0;z<strlen(vet_resposta);z++){
                        if(vet_resposta[z]==P_mostrar_letras[z]){
                            y++;
                        }

                    }
                    /*se a palavra ja foi decifrada, comando para mostrar o campeao e voltar pro menu*/
                    if(y==strlen(vet_resposta)){
                            printf(" ---------------------------------------------------------------------------------------------\n");
                            printf("|                                                                    |      PLACAR ATUAL      |\n");
                            printf("|                       PALAVRA DECIFRADA!!!                         | -----------------------|\n");
                            printf("|                                                                    |%12s  : %4d    |\n",play1.nome,play1.pontos);
                            printf("|                                                                    |                        |\n");
                            printf("|                                                                    |%12s  : %4d    |\n",play2.nome,play2.pontos);
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
                    *P_ver_ganhador=1;
                    sleep(3);
                    system("cls");
                    }


                    }
                    /*se nao tiver a letra -> passa a vez*/
                    else{
                            printf(" ---------------------------------------------------------------------------------------------\n");
                            printf("|                                                                    |      PLACAR ATUAL      |\n");
                            printf("|                      NÃO POSSUI ESSA LETRA!                        | -----------------------|\n");
                            printf("|                                                                    |%12s  : %4d    |\n",play1.nome,play1.pontos);
                            printf("|                        VOCÊ PASSOU A VEZ...                        |                        |\n");
                            printf("|                                                                    |%12s  : %4d    |\n",play2.nome,play2.pontos);
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
                            printf("|LETRAS JA DIGITADAS: %c- %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c - %c|\n",P_letras_digitadas[0],P_letras_digitadas[1],P_letras_digitadas[2],P_letras_digitadas[3],P_letras_digitadas[4],P_letras_digitadas[5],P_letras_digitadas[6],P_letras_digitadas[7],P_letras_digitadas[8],P_letras_digitadas[9],P_letras_digitadas[10],P_letras_digitadas[11],P_letras_digitadas[12],P_letras_digitadas[13],P_letras_digitadas[14],P_letras_digitadas[15],P_letras_digitadas[16],P_letras_digitadas[17],P_letras_digitadas[18]);
                            printf(" ---------------------------------------------------------------------------------------------\n");

                        /*trocando o jogador*/
                        troca=play_atual;
                        play_atual=play_esperando;
                        play_esperando=troca;
                        *P_pont_rodada=1;

                    sleep(5);
                    system("cls");
                    }

        }
    }
}

void mostra_play_atual(int *P_pont_rodada){
    char atual[30],espe[30];

    if(play_atual==1){
        strcpy(atual,play1.nome);
        strcpy(espe,play2.nome);
    }
    else{
        strcpy(atual,play2.nome);
        strcpy(espe,play1.nome);
    }

    if(*P_pont_rodada==1){
        printf(" ---------------------------------------------------------------------------------------------\n");
        printf("|                   %12s PASSOU A VEZ...                     |      PLACAR ATUAL      |\n",espe);
        printf("|                                                                    | -----------------------|\n");
        printf("|                                                                    |%12s  : %4d    |\n",play1.nome,play1.pontos);
        printf("|              %12s É SUA VEZ DE JOGAR AGORA                 |                        |\n",atual);
        printf("|                                                                    |%12s  : %4d    |\n",play2.nome,play2.pontos);
        printf(" ---------------------------------------------------------------------------------------------\n\n\n");
        system("pause");
        system("cls");
    }
    else{
        if(*P_pont_rodada==0){
            printf(" ---------------------------------------------------------------------------------------------\n");
            printf("|        %12s PERDEU TUDO E PASSOU A VEZ...                  |      PLACAR ATUAL      |\n",espe);
            printf("|                                                                    | -----------------------|\n");
            printf("|                                                                    |%12s  : %4d    |\n",play1.nome,play1.pontos);
            printf("|              %12s É SUA VEZ DE JOGAR AGORA                 |                        |\n",atual);
            printf("|                                                                    |%12s  : %4d    |\n",play2.nome,play2.pontos);
            printf(" ---------------------------------------------------------------------------------------------\n\n\n");
            system("pause");
            system("cls");
        }
        else{
            printf(" ---------------------------------------------------------------------------------------------\n");
            printf("|                                                                    |      PLACAR ATUAL      |\n",espe);
            printf("|                                                                    | -----------------------|\n");
            printf("|           %12s CONTINUE JOGANDO                            |%12s  : %4d    |\n",atual,play1.nome,play1.pontos);
            printf("|                                                                    |                        |\n");
            printf("|                                                                    |%12s  : %4d    |\n",play2.nome,play2.pontos);
            printf(" ---------------------------------------------------------------------------------------------\n\n\n");
            sleep(3);
            system("cls");
        }
    }

}

