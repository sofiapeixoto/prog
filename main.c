#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "files.h"

typedef struct {
    char pergunta[256];
    char opcoes[4][256];
    int respostaCorreta;
    int pontos;
} Pergunta;

typedef struct {
    char pergunta[256];
    char opcoes[3][256];
    int respostaCorreta[3];
    int pontos;
} PerguntaOrdem;

void baralhar(Pergunta perguntas[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Pergunta temp = perguntas[i];
        perguntas[i] = perguntas[j];
        perguntas[j] = temp;
    }
}

void baralharOrdem(PerguntaOrdem perguntas[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        PerguntaOrdem temp = perguntas[i];
        perguntas[i] = perguntas[j];
        perguntas[j] = temp;
    }
}

int main() {
    Pergunta perguntas[] = {
            {
                    "Qual � a capital da Fran�a?",
                    {"Madrid", "Roma", "Paris", "Londres"},
                    3,
                    5
            },
            {
                    "Qual � o elemento qu�mico com s�mbolo 'O'?",
                    {"Ouro", "Prata", "Oxig�nio", "H�lio"},
                    3,
                    10
            },
            {
                    "Quem escreveu 'Dom Quixote'?",
                    {"William Shakespeare", "Miguel de Cervantes", "Leo Tolstoy", "Gabriel Garcia Marquez"},
                    2,
                    8
            },
            {
                    "Qual planeta � conhecido como o Planeta Vermelho?",
                    {"V�nus", "J�piter", "Marte", "Saturno"},
                    3,
                    15
            },
            {
                    "Qual � o maior oceano do mundo?",
                    {"Atl�ntico", "�ndico", "�rtico", "Pac�fico"},
                    4,
                    7
            },
            {
                    "Quem pintou a Mona Lisa?",
                    {"Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Claude Monet"},
                    3,
                    12
            },
            {
                    "Qual � a f�rmula qu�mica da �gua?",
                    {"H2O", "CO2", "O2", "H2"},
                    1,
                    6
            },
            {
                    "Em que ano ocorreu a primeira guerra mundial?",
                    {"1914", "1939", "1812", "1945"},
                    1,
                    9
            },
            {
                    "Qual � a l�ngua oficial do Brasil?",
                    {"Espanhol", "Ingl�s", "Portugu�s", "Franc�s"},
                    3,
                    4
            },
            {
                    "Qual � o maior planeta do sistema solar?",
                    {"Terra", "Marte", "J�piter", "Saturno"},
                    3,
                    11
            },
            {
                    "Quem � conhecido como o 'Pai da Computa��o'?",
                    {"Bill Gates", "Charles Babbage", "Steve Jobs", "Alan Turing"},
                    2,
                    10
            },
            {
                    "Qual � a velocidade da luz?",
                    {"300.000 km/s", "150.000 km/s", "500.000 km/s", "100.000 km/s"},
                    1,
                    14
            },
            {
                    "Quem desenvolveu a teoria da relatividade?",
                    {"Isaac Newton", "Albert Einstein", "Nikola Tesla", "Galileu Galilei"},
                    2,
                    13
            },
            {
                    "Qual pa�s � conhecido como a Terra do Sol Nascente?",
                    {"China", "Jap�o", "Coreia do Sul", "Tail�ndia"},
                    2,
                    6
            }
    };

    PerguntaOrdem perguntasOrdem[] = {
            {
                    "Ordene os n�meros em ordem crescente:",
                    {"3", "1", "2"},
                    {2, 3, 1}, // �ndices corretos da ordem crescente
                    5
            },
            {
                    "Ordene as cores em ordem alfab�tica:",
                    {"Verde", "Azul", "Vermelho"},
                    {3, 1, 2}, // �ndices corretos da ordem alfab�tica
                    5
            },
            {
                    "Ordene os meses do ano em ordem inversa:",
                    {"Fevereiro", "Janeiro", "Mar�o"},
                    {2, 1, 3}, // �ndices corretos da ordem inversa
                    5
            }
    };

    int totalPerguntas = sizeof(perguntas) / sizeof(perguntas[0]);
    int totalPerguntasOrdem = sizeof(perguntasOrdem) / sizeof(perguntasOrdem[0]);
    char nome[30];
    char sigla[8];
    int op;
    int numPerguntas;
    int pontuacao = 0;
    int resposta;
    int respostas[3];

    printf("Bem-Vindo ao jogo de EMECA!!!\n");

    printf("Insira o seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Insira a sua sigla: ");
    fgets(sigla, sizeof(sigla), stdin);
    sigla[strcspn(sigla, "\n")] = 0;

    printf("\nBem-Vindo, %s (%s)!\n", nome, sigla);
    printf("1- Jogo Curto\n");
    printf("2- Jogo Normal\n");
    printf("0- SAIR\n\n");
    printf("INSIRA OP��O: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            numPerguntas = 2;
            break;
        case 2:
            numPerguntas = 4;
            break;
        case 0:
            printf("Saindo do jogo.\n");
            return 0;
        default:
            printf("Op��o inv�lida!!\n");
            return 0;
    }

    // Embaralhar as perguntas
    embaralhar(perguntas, totalPerguntas);

    // SELECIONA A CORRETA
    printf("SELECIONA A CORRETA!! Selecionar a op��o correta dentro de 4 hip�teses. N�o retira pontos!!\n");
    for (int i = 0; i < numPerguntas; i++) {
        printf("\nPergunta %d (%d pontos)\n", i + 1, perguntas[i].pontos);
        printf("%s\n", perguntas[i].pergunta);
        for (int j = 0; j < 4; j++) {
            printf("%d) %s\n", j + 1, perguntas[i].opcoes[j]);
        }
        printf("Selecione a op��o correta (1-4): ");
        scanf("%d", &resposta);
        if (resposta == perguntas[i].respostaCorreta) {
            pontuacao += perguntas[i].pontos;
            printf("Correto! Voc� ganhou %d pontos.\n\n", perguntas[i].pontos);
        } else {
            printf("Errado! A resposta correta � %d) %s.\n\n", perguntas[i].respostaCorreta, perguntas[i].opcoes[perguntas[i].respostaCorreta - 1]);
        }
    }

    // FUGA DE PONTOS
    printf("FUGA DE PONTOS!! Selecionar a op��o correta dentro de 4 hip�teses. Se errar, a pontua��o � decrementada.\n");
    embaralhar(perguntas, totalPerguntas);
    for (int i = 0; i < numPerguntas; i++) {
        printf("\nPergunta %d (%d pontos)\n", i + 1, perguntas[i].pontos);
        printf("%s\n", perguntas[i].pergunta);
        for (int j = 0; j < 4; j++) {
            printf("%d) %s\n", j + 1, perguntas[i].opcoes[j]);
        }
        printf("Selecione a op��o correta (1-4): ");
        scanf("%d", &resposta);
        if (resposta == perguntas[i].respostaCorreta) {
            pontuacao += perguntas[i].pontos;
            printf("Correto! Voc� ganhou %d pontos.\n", perguntas[i].pontos);
        } else {
            pontuacao -= perguntas[i].pontos;
            printf("Errado! A resposta correta � %d) %s.\n", perguntas[i].respostaCorreta, perguntas[i].opcoes[perguntas[i].respostaCorreta - 1]);
            printf("Voc� perdeu %d pontos.\n", perguntas[i].pontos);
        }
    }

    // ORDENAR
    printf("ORDENAR!! Colocar por ordem as 3 op��es apresentadas. Todas as perguntas t�m a mesma cota��o.\n");
    embaralharOrdem(perguntasOrdem, totalPerguntasOrdem);
    for (int i = 0; i < numPerguntas; i++) {
        printf("\nPergunta %d (%d pontos)\n", i + 1, perguntasOrdem[i].pontos);
        printf("%s\n", perguntasOrdem[i].pergunta);
        for (int j = 0; j < 3; j++) {
            printf("%d) %s\n", j + 1, perguntasOrdem[i].opcoes[j]);
        }
        printf("Digite a ordem correta das op��es (1, 2, 3): ");
        for (int j = 0; j < 3; j++) {
            scanf("%d", &respostas[j]);
        }

        int correto = 1;
        for (int j = 0; j < 3; j++) {
            if (respostas[j] != perguntasOrdem[i].respostaCorreta[j]) {
                correto = 0;
                break;
            }
        }

        if (correto) {
            pontuacao += perguntasOrdem[i].pontos;
            printf("Correto! Voc� ganhou %d pontos.\n", perguntasOrdem[i].pontos);
        } else {
            printf("Errado! A ordem correta �:");
            for (int j = 0; j < 3; j++) {
                printf(" %d) %s", perguntasOrdem[i].respostaCorreta[j], perguntasOrdem[i].opcoes[perguntasOrdem[i].respostaCorreta[j] - 1]);
            }
            printf("\n");
        }
    }

    printf("\nPontua��o final: %d\n", pontuacao);
    printf("Obrigado por jogar!\n");

    return 0;
}
