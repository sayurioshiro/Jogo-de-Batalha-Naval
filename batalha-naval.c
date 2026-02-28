#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define HAB_TAM 5

int main() {

    int tabuleiro[TAM][TAM];

    // Inicializa tabuleiro com água
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // Coloca um navio exemplo
    tabuleiro[4][4] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[4][6] = 3;

    // Matrizes de habilidade
    int cone[HAB_TAM][HAB_TAM];
    int cruz[HAB_TAM][HAB_TAM];
    int octaedro[HAB_TAM][HAB_TAM];

    int centro = HAB_TAM / 2;

    // Construção dinâmica do CONE
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Construção dinâmica da CRUZ
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Construção dinâmica do OCTAEDRO (losango)
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Origem da habilidade no tabuleiro
    int origemLinha = 5;
    int origemColuna = 5;

    // Sobreposição do OCTAEDRO no tabuleiro
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {

            int linhaTab = origemLinha - centro + i;
            int colunaTab = origemColuna - centro + j;

            if (linhaTab >= 0 && linhaTab < TAM &&
                colunaTab >= 0 && colunaTab < TAM) {

                if (octaedro[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }

    // Exibição com símbolos
    printf("TABULEIRO - NIVEL MESTRE\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0)
                printf("~ ");   // Água
            else if (tabuleiro[i][j] == 3)
                printf("N ");   // Navio
            else if (tabuleiro[i][j] == 5)
                printf("* ");   // Área da habilidade
        }
        printf("\n");
    }

    return 0;
}