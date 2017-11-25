#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


struct player{
    char nome[30];
    int pontos;
};
struct player play1,play2;
char vet_pergunta[16],vet_resposta[16];
int pontuacao_rodada;



void sleep(time_t delay){
    time_t timer0, timer1;
    time(&timer0);
    do{
        time(&timer1);
    }while((timer1-timer0) < delay);
}




void painel();
void op_menu( int op);
void cadastro_player();
void sorteio_pontuacao();
void start();


int main(){
    setlocale(LC_ALL, "Portuguese");

    painel();
    rodada();



    return 0;
}

void painel(){

    system("start arquivos/roda_roda.mp3");
    int op;
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
    puts("               Digite sua opção: ");
    printf("               ");
    scanf("%d",&op);
    op_menu(op);
}


void op_menu(int op){
    system("start arquivos/null.mp3");
    int valor_setado;
    switch(op){
        case 0:
            system("cls");
            exit(0);
            break;
        case 1:
            cadastro_player();
            break;
        default:
            puts("               Opção inválida, tente novamente:");
            break;
    }
}

void cadastro_player(){
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
void sorteio_pontuacao(){
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



pontuacao_rodada = v[7];

}



void rodada(){
    carregar_arquivo();
    sorteio_pontuacao();

}
