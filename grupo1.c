#include "grupo1.h"

int lerPerguntas1(Perguntas1 perguntas1[]) {        
    FILE *ficheiroLer;
    ficheiroLer = fopen("perguntas_grupo_1.txt", "r");
    
    if (ficheiroLer == NULL) {
        printf("Não foi possível abrir o ficheiro.\n");
        return 0;
    }
    
    int totalperguntas = 0;
    char linha[700];
    
    while (fgets(linha, sizeof(linha), ficheiroLer) != NULL && totalperguntas < 50) {
        char *token = strtok(linha, ";");
        if (token != NULL) {
            strncpy(perguntas1[totalperguntas].pergunta, token, sizeof(perguntas1[totalperguntas].pergunta) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas1[totalperguntas].r1, token, sizeof(perguntas1[totalperguntas].r1) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas1[totalperguntas].r2, token, sizeof(perguntas1[totalperguntas].r2) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas1[totalperguntas].r3, token, sizeof(perguntas1[totalperguntas].r3) - 1);
            
            token = strtok(NULL, ";");
            if (token != NULL)
                strncpy(perguntas1[totalperguntas].r4, token, sizeof(perguntas1[totalperguntas].r4) - 1);

            token = strtok(NULL, ";");
            if (token != NULL)
                perguntas1[totalperguntas].rcerta = atoi(token);

            totalperguntas++;
        }
    }

    fclose(ficheiroLer);
    return totalperguntas;
}

void baralharPerguntas1(Perguntas1 perguntas1[], int totalperguntas) {
    srand(time(NULL));
    for (int i = totalperguntas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Perguntas1 temp = perguntas1[i];
        perguntas1[i] = perguntas1[j];
        perguntas1[j] = temp;
    }
}

void meterPerguntas1() {
    Perguntas1 perguntas;
    
    printf("Pergunta: "); 
    fgets(perguntas.pergunta, 300, stdin);
    perguntas.pergunta[strcspn(perguntas.pergunta, "\n")] = '\0';
            
    printf("Resposta 1: "); 
    fgets(perguntas.r1, 100, stdin);
    perguntas.r1[strcspn(perguntas.r1, "\n")] = '\0';
            
    printf("Resposta 2: "); 
    fgets(perguntas.r2, 100, stdin);
    perguntas.r2[strcspn(perguntas.r2, "\n")] = '\0';
            
    printf("Resposta 3: ");
    fgets(perguntas.r3, 100, stdin);
    perguntas.r3[strcspn(perguntas.r3, "\n")] = '\0';
            
    printf("Resposta 4: ");
    fgets(perguntas.r4, 100, stdin);
    perguntas.r4[strcspn(perguntas.r4, "\n")] = '\0';
            
    printf("Resposta certa: ");
    scanf("%d", &perguntas.rcerta);
    getchar();
    
    FILE *perguntas1;
    perguntas1 = fopen("perguntas_grupo_1.txt", "a+");
    
    if (perguntas1 == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }
    
    fprintf(perguntas1, "%s;%s;%s;%s;%s;%d\n", perguntas.pergunta, perguntas.r1, perguntas.r2, perguntas.r3, perguntas.r4, perguntas.rcerta);
    fclose(perguntas1);
}
