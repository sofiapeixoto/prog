#include "jogo.h"

void mostrarPerguntas(Perguntas pergunta){
    printf("%s\n", pergunta.pergunta);
    printf("%s\n", pergunta.r1);
    printf("%s\n", pergunta.r2);
    printf("%s\n", pergunta.r3);
    printf("%s\n", pergunta.r4);
}

int lerResposta(Perguntas pergunta){
    int resposta;

    printf("Resposta:\n");
    scanf("%d", &resposta);
    if(resposta == pergunta.rcerta){
        printf("ACERTOU! +5");
        return 5;
    }else{
        printf("Errou!");
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
    printf("SELECIONA A CORRETA!! Selecionar a opção correta dentro de 4 hipóteses. Não retira pontos!!\n");
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

int jogo(int numperguntas){
    int pontuacao, numrespondidas = 0;
    Perguntas perguntas[50];
    int perguntasRespondidas[50];

    PerguntasOrdem perguntasOrdem[30];
    int perguntasOrdemRespondidas[50];
    
    int totalperguntasFicheiro = lerPerguntas(perguntas);
    baralharPerguntas(perguntas, totalperguntasFicheiro);

    pontuacao += grupo1(&numrespondidas, numperguntas, perguntas, perguntasRespondidas, totalperguntasFicheiro);

    int totalperguntasOrdem = lerPerguntasOrdem(perguntasOrdem);
    baralharPerguntasOrdem(perguntasOrdem, totalperguntasOrdem);


    return pontuacao;
}
