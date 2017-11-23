#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

struct player{
    char nome[30];
    int pontos;
};
struct player play1,play2;
char vet_pergunta[16],vet_resposta[16];




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

int main(){
    setlocale(LC_ALL, "Portuguese");

    painel();

    return 0;
}

void painel(){
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
    carregar_arquivo();
}

void carregar_arquivo(){
    FILE *fp;
    int sort;
    char url_tema[16] = {'a','r','q','u','i','v','o','s','/','P',' ','.','t','x','t'},t;
    char url_resposta[16] = {'a','r','q','u','i','v','o','s','/','R',' ','.','t','x','t'};

    system("cls");
    printf("\n \n \n \n");
    puts("               Iniciando o Jogo...");
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
             printf("DICA: %s \n \n",vet_pergunta);
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
        printf("REPOSTA: %s",vet_resposta);
    }
    fclose (fp);
}


