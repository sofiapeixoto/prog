#include "files.h"

int lerPerguntasOrdem(PerguntasOrdem perguntas[]) {
    FILE *LerperguntasOrdem = fopen("perguntasordem.txt", "r");
    
    if (LerperguntasOrdem == NULL) {
        printf("Não foi possível abrir o ficheiro.\n");
        return 0;
    }
    
    int totalperguntas = 0;
    char linha[700];
    
    while (fgets(linha, sizeof(linha), LerperguntasOrdem) != NULL && totalperguntas < 30) {
        char *token = strtok(linha, ";");
        if (token != NULL) {
            strncpy(perguntas[totalperguntas].pergunta, token, sizeof(perguntas[totalperguntas].pergunta) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas[totalperguntas].r1, token, sizeof(perguntas[totalperguntas].r1) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas[totalperguntas].r2, token, sizeof(perguntas[totalperguntas].r2) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas[totalperguntas].r3, token, sizeof(perguntas[totalperguntas].r3) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                perguntas[totalperguntas].rcerta = atoi(token);

            totalperguntas++;
        }
    }

    fclose(LerperguntasOrdem);
    return totalperguntas;
}

void baralharPerguntasOrdem(PerguntasOrdem perguntas[], int totalperguntas) {
    srand(time(NULL));
    for (int i = totalperguntas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        PerguntasOrdem temp = perguntas[i];
        perguntas[i] = perguntas[j];
        perguntas[j] = temp;
    }
}

void meterPerguntaOrdem() {
    PerguntasOrdem pergunta;
    printf("Pergunta: \n"); 
    fgets(pergunta.pergunta, 300, stdin);
    pergunta.pergunta[strcspn(pergunta.pergunta, "\n")] = '\0';
            
    printf("Resposta1: "); 
    fgets(pergunta.r1, 100, stdin);
    pergunta.r1[strcspn(pergunta.r1, "\n")] = '\0';
            
    printf("Resposta2: "); 
    fgets(pergunta.r2, 100, stdin);
    pergunta.r2[strcspn(pergunta.r2, "\n")] = '\0';
            
    printf("Resposta3: "); 
    fgets(pergunta.r3, 100, stdin);
    pergunta.r3[strcspn(pergunta.r3, "\n")] = '\0';
            
    printf("Resposta certa: ");
    scanf("%d", &pergunta.rcerta);
    getchar();
    
    FILE *perguntasOrdem = fopen("perguntasordem.txt", "a+");
    
    if (perguntasOrdem == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }
    
    fprintf(perguntasOrdem, "%s;%s;%s;%s;%d\n", pergunta.pergunta, pergunta.r1, pergunta.r2, pergunta.r3, pergunta.rcerta);
    fclose(perguntasOrdem);
}

void entraradmin() {
    int admin, grupos;
    char utilizador[50], password[10];
    char utilizador1[] = "sofia";
    char utilizador2[] = "ines";
    char password1[] = "2006";

    printf("(1) Jogador ou (2) Administrador?\n");
    scanf("%d", &admin);
    getchar();

    switch (admin) {
        case 1:
            // Código para jogador
            break;

        case 2:
            while (1) {
                printf("Utilizador: ");
                scanf("%s", utilizador);

                printf("Password: ");
                scanf("%s", password);

                if ((strcmp(utilizador, utilizador1) == 0 || strcmp(utilizador, utilizador2) == 0) && strcmp(password, password1) == 0) {
                    printf("Acesso autorizado!\n");
                    printf("Qual grupo deseja aceder?\n (1) Grupo1\n (2) Grupo2\n (3) Grupo3\n");
                    scanf("%d", &grupos);

                    switch (grupos) {
                        case 1:
                            meterPerguntas1(); 
                            break;

                        case 2:
                            meterPerguntas2(); 
                            break;

                        case 3:
                            meterPerguntaOrdem();
                            break;

                        default:
                            printf("Opção inválida!\n");
                            break;
                    }
                    return;
                } else {
                    printf("NÃO ESTÁ AUTORIZADO!!!\n");
                }
            }
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }
}

