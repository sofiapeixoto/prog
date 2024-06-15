#include "files.h"

/* PERGUNTAS NORMAIS */
int lerPerguntas(Perguntas perguntas[]) {
    FILE *ficheiro;
    ficheiro = fopen("perguntas.txt", "r");

    if (ficheiro == NULL) {
        printf("Não foi possível abrir o ficheiro.\n");
        return 0;
    }

    int totalperguntas = 0;
    char linha[700];

    while (fgets(linha, sizeof(linha), ficheiro) != NULL && totalperguntas < 50) {
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
                strncpy(perguntas[totalperguntas].r4, token, sizeof(perguntas[totalperguntas].r4) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                perguntas[totalperguntas].rcerta = atoi(token);

            totalperguntas++;
        }
    }

    fclose(ficheiro);
    return totalperguntas;
}

void baralharPerguntas(Perguntas perguntas[], int totalperguntas) {
    srand(time(NULL));
    for (int i = totalperguntas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Perguntas temp = perguntas[i];
        perguntas[i] = perguntas[j];
        perguntas[j] = temp;
    }
}

void meterPerguntas() {
    Perguntas pergunta;

    printf("Pergunta: ");
    fgets(pergunta.pergunta, sizeof(pergunta.pergunta), stdin);
    pergunta.pergunta[strcspn(pergunta.pergunta, "\n")] = '\0';

    printf("Resposta 1: ");
    fgets(pergunta.r1, sizeof(pergunta.r1), stdin);
    pergunta.r1[strcspn(pergunta.r1, "\n")] = '\0';

    printf("Resposta 2: ");
    fgets(pergunta.r2, sizeof(pergunta.r2), stdin);
    pergunta.r2[strcspn(pergunta.r2, "\n")] = '\0';

    printf("Resposta 3: ");
    fgets(pergunta.r3, sizeof(pergunta.r3), stdin);
    pergunta.r3[strcspn(pergunta.r3, "\n")] = '\0';
    printf("Resposta 4: ");
    fgets(pergunta.r4, sizeof(pergunta.r4), stdin);
    pergunta.r4[strcspn(pergunta.r4, "\n")] = '\0';

    printf("Resposta certa: ");
    scanf("%d", &pergunta.rcerta);
    getchar();

    FILE *ficheiro;
    ficheiro = fopen("perguntas.txt", "a+");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo de pergunta.\n");
        return;
    }

    fprintf(ficheiro, "%s;\n%s;\n%s;\n%s;\n%s;\n%d\n", pergunta.pergunta, pergunta.r1, pergunta.r2, pergunta.r3, pergunta.r4, pergunta.rcerta);
    fclose(ficheiro);
}


/* PERGUNTAS DE ORDEM */
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

    fprintf(perguntasOrdem, "%s;%s;%s;%s;%d\n", pergunta.pergunta, pergunta.r1, pergunta.r2, pergunta.r3,
            pergunta.rcerta);
    fclose(perguntasOrdem);
}

