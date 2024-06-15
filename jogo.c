#include "jogo.h"

void mostrarPerguntas(Perguntas pergunta){
    printf("%s\n", pergunta.pergunta);
    printf("%s\n", pergunta.r1);
    printf("%s\n", pergunta.r2);
    printf("%s\n", pergunta.r3);
    printf("%s\n", pergunta.r4);
}

void mostrarPerguntasOrdem (PerguntasOrdem perguntas){
    printf("%s\n", perguntas.pergunta);
    printf("%s\n", perguntas.r1);
    printf("%s\n", perguntas.r2);
    printf("%s\n", perguntas.r3);
}

int lerResposta(Perguntas pergunta){
    int resposta;

    printf("\nResposta:");
    scanf("%d", &resposta);
    if(resposta == pergunta.rcerta){
        printf("ACERTOU! +5\n\n");
        return 5;
    }else{
        printf("Errou!\n\n");
        return 0;
    }
}
int lerResposta1(Perguntas pergunta){
    int resposta;

    printf("\nResposta:");
    scanf("%d", &resposta);
    if(resposta == pergunta.rcerta){
        printf("ACERTOU! +5\n\n");
        return 5;
    }else{
        printf("Errou! -2 Pontos \n\n");
        return -2;
    }
}

int lerResposta2(PerguntasOrdem perguntas){
    int resposta;

    printf("\nResposta:");
    scanf("%d", &resposta);
    if(resposta == perguntas.rcerta){
        printf("ACERTOU! +5\n\n");
        return 5;
    }else{
        printf("Errou!\n\n");
        return 0;
    }
}

int jaRespondida(int id, int perguntasRespondidas[]){
    for(size_t i = 0; i < 50; i++) {
        if(perguntasRespondidas[i] == id)
            return 1;
    }
    return 0;
}

int grupo1(int *numrespondidas, int numperguntas, Perguntas perguntas[], int perguntasRespondidas[], int totalperguntas){
    srand(time(NULL));
    printf("\nSELECIONA A CORRETA!! Selecionar a opção correta dentro de 4 hipóteses. Não retira pontos!!\n\n");
    int id = 0, pontos = 0;

    do{
        do {
            id = rand() % (totalperguntas + 1);
        }while(jaRespondida(id, perguntasRespondidas));
        perguntasRespondidas[*numrespondidas] = id;

        Perguntas pergunta = perguntas[id];
        mostrarPerguntas(pergunta);
        pontos += lerResposta(pergunta);

        (*numrespondidas)++;
    }while(*numrespondidas % numperguntas != 0);

    return pontos;
}

int grupo2(int *numrespondidas, int numperguntas, Perguntas perguntas[], int perguntasRespondidas[], int totalperguntas){
    srand(time(NULL));
    printf("\nFUGA DE PONTOS!! Selecionar a opção correta dentro de 4 hipóteses. Se errar, a pontuação é retirada!\n\n");
    int id = 0, pontos = 0;

    do{
        do {
            id = rand() % (totalperguntas + 1);
        }while(jaRespondida(id, perguntasRespondidas));
        perguntasRespondidas[*numrespondidas] = id;

        Perguntas pergunta = perguntas[id];
        mostrarPerguntas(pergunta);
        pontos += lerResposta1(pergunta);

        (*numrespondidas)++;
    }while(*numrespondidas % numperguntas != 0);

    return pontos;
}

int grupo3(int *numrespondidas, int numperguntas, PerguntasOrdem perguntas[], int perguntasRespondidas[], int totalperguntas){
    srand(time(NULL));
    printf("\nORDENAR!! Colocar por ordem as 3 opções apresentadas. Não são retirados pontos!\n\n");
    int id = 0, pontos = 0;

    do{
        do {
            id = rand() % (totalperguntas + 1);
        }while(jaRespondida(id, perguntasRespondidas));
        perguntasRespondidas[*numrespondidas] = id;

        PerguntasOrdem pergunta = perguntas[id];
        mostrarPerguntasOrdem(pergunta);
        pontos += lerResposta2(pergunta);

        (*numrespondidas)++;
    }while(*numrespondidas % numperguntas != 0);

    return pontos;
}

int jogo(int numperguntas){
    int pontuacao, numrespondidas = 0;
    Perguntas perguntas[50];
    int perguntasRespondidas[50];
    
    int totalperguntasFicheiro = lerPerguntas(perguntas);
    baralharPerguntas(perguntas, totalperguntasFicheiro);

    pontuacao += grupo1(&numrespondidas, numperguntas, perguntas, perguntasRespondidas, totalperguntasFicheiro);
    pontuacao += grupo2(&numrespondidas, numperguntas, perguntas, perguntasRespondidas, totalperguntasFicheiro);
    
    PerguntasOrdem perguntasOrdem[30];
    int perguntasOrdemRespondidas[50];
    
    int totalperguntasOrdem = lerPerguntasOrdem(perguntasOrdem);
    baralharPerguntasOrdem(perguntasOrdem, totalperguntasOrdem);
    
    pontuacao += grupo3(&numrespondidas, numperguntas, perguntasOrdem, perguntasOrdemRespondidas, totalperguntasOrdem);


    return pontuacao;
}
