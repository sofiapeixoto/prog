#include "menus.h"

void menuJogador(){
    int opcao, pontuacao, numperguntas, respostascertas;
    char nome[20], sigla[10];
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
                pontuacao = jogo(2, &numperguntas, &respostascertas);
                break;
            case 2:
                pontuacao = jogo(4, &numperguntas, &respostascertas);
                break;
            case 0:
                printf("A sair do jogo...\n");

            default:
                printf("Opção inválida!!\n");
        }
        
        if(opcao == 1 || opcao == 2){
            guardarPontuacao(nome, sigla, pontuacao);
            
            printf("Pontuação Final: %d ", pontuacao);
            
            int percentagemcertas,*numcertas,numerradas;
            
            percentagemcertas=(totalcertas / numperguntas)*100;
            printf("Percentagem de Perguntas Certas: %d \%",percentagemcertas);
            
            numerradas=numperguntas-numcertas;
            printf("Total de Perguntas Certas: %d\n Total de Perguntas Erradas: %d\n", numcertas,numerradas);
            
            RANKING utilizadores[100];
            int totalutilizadores = lerPontuacao(utilizadores);
            mostrarRanking(utilizadores,&totalutilizadores);
            
            opcao = 0;
        }
    }while(opcao != 0);
}

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