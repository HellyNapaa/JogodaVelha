#include <stdio.h>
#include <stdlib.h>

#define jogador_1 '1'
#define jogador_2 '2'

int linha, coluna;
int i, j;

int **preenche(int linha, int coluna)
{
    int **tabuleiro;
    tabuleiro = (int **)malloc(linha * sizeof(int *));

    for (i = 0; i < coluna; i++)
    {
        tabuleiro[i] = (int *)malloc(coluna * sizeof(int));
    }
    for (i = 0; i < coluna; i++)
    {
        for (j = 0; j < linha; j++)
        {
            tabuleiro[i][j] = '0';
        }
    }
    return (tabuleiro);
}
void mostratabuleiro(int **tabuleiro)
{
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            if (tabuleiro[i][j] == '0')
                printf("0 ");
            if (tabuleiro[i][j] == '1')
                printf("1 ");
            if (tabuleiro[i][j] == '2')
                printf("2 ");
        }
        putchar('\n');
    }
}

//  Verifica a horizontal e vertical
int verificahove(int **tabuleiro, int max)
{
    for (int i = 0; i < max; i++) //  horizontal
    {
        for (int j = 0; j < max; j++)
        {
            if (j > 0 && tabuleiro[i][j] != tabuleiro[i][j - 1])
            { //  Verifica se existe um caracter diferente
                break;
            }

            if (tabuleiro[i][j] == '0')
            { //   Verifica se existe um caracter não preenchido
                break;
            }

            if (j == max - 1 && tabuleiro[i][j] == tabuleiro[i][j - 1])
            { //  Verifica se é o ultimo elemento e se ele é igual ao anterior
                return 1;
            }
        }
    }

    for (int i = 0; i < max; i++) //  vertical
    {
        for (int j = 0; j < max; j++)
        {
            if (tabuleiro[j][i] == '0')
            {
                break;
            }

            if (j > 0 && tabuleiro[j - 1][i] != tabuleiro[j][i])
            {
                break;
            }

            if (j == max - 1 && tabuleiro[j - 1][i] == tabuleiro[j][i])
            {
                return 1;
            }
        }
    }

    return 0;
}

//  Verifica as diagonais da matriz
int verificadiagonais(int **tabuleiro, int max)
{
    /*
        diagonal assim

        [x][][]
        [][x][]
        [][][x]
    */
    for (int i = 0; i < max; i++)
    {
        if (tabuleiro[i][i] == '0')
        { //   Verifica se existe um caracter não preenchido
            break;
        }

        if (i > 0 && tabuleiro[i][i] != tabuleiro[i - 1][i - 1])
        { //  Verifica se existe um caracter diferente
            break;
        }

        if (i == max - 1 && tabuleiro[i][i] == tabuleiro[i - 1][i - 1])
        { //  Verifica se é o ultimo elemento e se ele é igual ao anterior
            return 1;
        }
    }

    /*
        diagonal assim

        [][][x]
        [][x][]
        [x][][]
    */
    for (int i = 0; i < max; i++)
    {
        if (tabuleiro[i][max - i - 1] == '0')
        {
            break;
        }

        if (i > 0 && tabuleiro[i][max - i - 1] != tabuleiro[i - 1][max - (i - 1) - 1])
        {
            break;
        }

        if (i == max - 1 && tabuleiro[i][max - i - 1] == tabuleiro[i - 1][max - (i - 1) - 1])
        {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    int posicaolinha, posicaocoluna;
    int quantidade;
    int **tabuleiro;
    scanf("%d", &linha);
    coluna = linha;
    quantidade = coluna * linha;
    tabuleiro = preenche(linha, coluna);

    int c = 0;
    int turnodojogador = 1;

    while (c < quantidade)
    {
        mostratabuleiro(tabuleiro);

        if (turnodojogador == 1)
        {
            printf("Coordenadas do jogador %c: \n", jogador_1);
            scanf("%d %d", &posicaocoluna, &posicaolinha );
            tabuleiro[posicaolinha][posicaocoluna] = jogador_1;

            if (verificahove(tabuleiro, linha) || verificadiagonais(tabuleiro, linha))
            {
                mostratabuleiro(tabuleiro);
                printf("Jogador %c ganhou!\n", jogador_1);
                return 0;
            }

            turnodojogador = 2;
        }
        else if (turnodojogador == 2)
        {
            printf("Coordenadas do jogador %c: \n", jogador_2);
            scanf("%d %d", &posicaocoluna, &posicaolinha);
            tabuleiro[posicaolinha][posicaocoluna] = jogador_2;

            if (verificahove(tabuleiro, linha) || verificadiagonais(tabuleiro, linha))
            {
                mostratabuleiro(tabuleiro);
                printf("Jogador %c ganhou!", jogador_2);
                return 0;
            }

            turnodojogador = 1;
        }
        c++;
    }
    mostratabuleiro(tabuleiro);
    printf("Empate!");
    return 0;
}