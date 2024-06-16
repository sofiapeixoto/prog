#include "menus.h" //menus.c precisa de ter incluido o menus.h 


/*MENU JOGADOR. O jogador escreve o nome, sigla e escolhe o tipo de jogo ou se quer sair*/
void menuJogador(){
    int opcao, pontuacao = 0, numcertas = 0, numperguntas = 0;
    char nome[50], sigla[10];
    printf("Insira o seu nome: ");
    scanf("%s",nome);
    printf("Insira a sua sigla: ");
    scanf("%s",sigla);
    do{
        printf ("\nBem-Vindo, %s (%s)!\n", nome, sigla);
        printf ("1- Jogo Curto\n");
        printf ("2- Jogo Normal\n");
        printf ("0- SAIR\n\n");
        printf ("INSIRA OPÇÃO: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                numperguntas = 6;
                pontuacao = jogo(2, &numcertas);
                break;
            case 2:
                numperguntas = 12;
                pontuacao = jogo(4, &numcertas);
                break;
            case 0:
                printf("A sair do jogo...\n");

            default:
                printf("Opção inválida!!\n");
        }
        
/*Caso o jogador jogue aparece no final a pontuação, a percentagem de certas, o numero de certas e erradas e o ranking*/   
        
        if(opcao == 1 || opcao == 2){
            guardarPontuacao(nome, sigla, pontuacao);
            
            printf("Pontuação Final: %d ", pontuacao);
            
            float percentagemcertas;
            percentagemcertas = (numcertas * 100) / numperguntas;
            printf("Percentagem de Perguntas Certas: %f%%\n", percentagemcertas);
            
            int numerradas;
            numerradas = numperguntas - numcertas;
            printf("Total de Perguntas Certas: %d\n Total de Perguntas Erradas: %d\n", numcertas,numerradas);
            
            RANKING utilizadores[100];
            int totalutilizadores = lerPontuacao(utilizadores);
            mostrarRanking(utilizadores, totalutilizadores);
            opcao = 0;
        }
    }while(opcao != 0);
}
/*MENU ADMINISTRADOR. Usam credenciais para entrar*/

void menuAdmin(){
    int opcao;
    char utilizador[50], password[10];
    char utilizador1[] = "sofia";
    char utilizador2[] = "ines";
    char password1[] = "2006";

    printf("Utilizador: ");
    scanf("%s", utilizador);

    printf("Password: ");
    scanf("%s", password);
    
/*Comparação entre os utilizadores colocados e os certos. O mesmo para as passwords*/
    
    if ((strcmp(utilizador, utilizador1) != 0 &&
         strcmp(utilizador, utilizador2) != 0)
        || strcmp(password, password1) != 0){
        return;
    }


    do{
        printf("\nAcesso autorizado!\n");
        printf("Qual grupo deseja aceder?\n (1) Grupo1 e Grupo2\n (3) Grupo3\n");
        scanf("%d", &opcao);
        getchar();
        
/*O administrador escolhe o grupo onde quer colocar mais perguntas*/
        
        switch (opcao) {
            case 1:
                meterPerguntas();
                break;

            case 3:
                meterPerguntaOrdem();
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }while(opcao != 0);
}
/*MENU PRINCIPAL. O utilizador escolhe se é admin ou jogador*/

void menuPrincipal() {
    int opcao;

    do{
        printf("(1) Jogador ou (2) Administrador?\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                menuJogador();
                break;

            case 2:
                menuAdmin();
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }while(opcao != 0);
}