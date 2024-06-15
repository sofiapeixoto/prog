#include "grupo1.h"
typedef struct {
    char pergunta[300];
    char r1[100];
    char r2[100];
    char r3[100];
    char r4[100];
    int rcerta;
} Perguntas1;

//* Função de Ler Perguntas do Grupo 1. 
// Criamos um ficheiro para ler as perguntas (r). Limitamos o número máximo de perguntas para 50. 
// Verificamos de linha a linha a pergunta e as respostas que estão separadas por ';' .
// O número total de perguntas vai ser adicionado até á última linha.

int lerPerguntas1 (Perguntas1 perguntas1[]){        
        
    FILE *ficheiroLer;
        ficheiroLer = fopen("perguntas_grupo_1.txt", "r");
        
        if (ficheiroLer == NULL) {
            printf("Não foi possível abrir o ficheiro.\n");
        return 0;
        }
        
    int totalperguntas = 0;
    char linha[700];
    
    while (fgets(linha, sizeof(linha), ficheiroLer) != NULL && totalperguntas < 50) {
        // Separar as coisas da linha usando strtok
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

//* Função de Baralhar Perguntas do Grupo 1.
// Baralha-se as perguntas para terem uma ordem aleatória sempre que se for jogar

void baralharPerguntas1 (Perguntas1 perguntas1[], int totalperguntas) {
    srand(time(NULL));
    for (int i = totalperguntas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        PerguntasOrdem temp = perguntas1[i];
        perguntas1[i] = perguntas1[j];
        perguntas1[j] = temp;
    }
}

//* Função de Meter as Perguntas do Grupo 1.
// Criamos um ficheiro .txt que contém TODAS as perguntas do GRUPO1.

void meterPerguntas1(){
    Perguntas1 perguntas;
    
    printf("Pergunta: "); 
    fgets(perguntas.pergunta, 300, stdin);
    perguntas.pergunta[strcspn(perguntas.pergunta, "\n")] = '\0';
            
    printf("Resposta 1: "); 
    fgets(perguntas.r1, 300, stdin);
    perguntas.r1[strcspn(perguntas.r1, "\n")] = '\0';
            
    printf("Resposta 2: "); 
    fgets(perguntas.r2, 300, stdin);
    perguntas.r2[strcspn(perguntas.r2, "\n")] = '\0';
            
    printf("Resposta 3: ");
    fgets(perguntas.r3, 300, stdin);
    perguntas.r3[strcspn(perguntas.r3, "\n")] = '\0';
            
    printf("Resposta 4: ");
    fgets(perguntas.r4, 300, stdin);
    perguntas.r4[strcspn(perguntas.r4, "\n")] = '\0';
            
    printf("Resposta certa: ");scanf("%d",&perguntas.rcerta); 
    getchar();
    
    FILE *perguntas1;
    perguntas1 =fopen("perguntas_grupo_1.txt", "a+");
    
    if (perguntas1 == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        }
    
    fprintf(perguntas1, "%s;\n%s;\n%s;\n%s;\n%s;\n%d\n",perguntas.pergunta,perguntas.r1,perguntas.r2,perguntas.r3,perguntas.r4,perguntas.rcerta );
    fclose(perguntas1);
}