#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.


    
    // DECLARAÇÃO E INICIALIZAÇÃO DO TABULEIRO
    
    
    // Matriz 10 x 10 simulando um tabuleiro
    int tabuleiro[10][10];

    // Variáveis para controlar os loops
    int i, j;

    // O primeiro 'for' passa por cada linha.
    for (i = 0; i < 10; i++) {
        // O segundo 'for' passa por cada coluna daquela linha.
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }


    // DEFINIÇÃO DOS NAVIOS (VETORES)
    
    // Número 3 para simular os návios

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};


    // POSICIONANDO O NAVIO HORIZONTAL
    
    
    // Definicição do primeiro návio no tabuleiro
    int linhaH = 2;
    int colunaH = 4;

    // Loop para colocar as partes do navio no tabuleiro
    for (i = 0; i < 3; i++) {

        // Verifica se a posição para não sair do tabuleiro
        if (colunaH + i < 10) {
            // Copia o valor do vetor (simulando o návio) para o tabuleiro
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }

    // POSICIONANDO O NAVIO VERTICAL

    // Definição do segundo návio no tabuleiro
    int linhaV = 5;
    int colunaV = 8;

    // Loop para colocar o navio vertical
    for (i = 0; i < 3; i++) {
    
        // Loop para colocar as partes do navio no tabuleiro
        if (linhaV + i < 10) {
            // Checagem simples de sobreposição
            // Só colocamos se o local for 0, simulando a água, se já tiver navio, ele não coloca em cima
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                 tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // POSICIONANDO O NAVIO DIAGONAL (\)
    
    // Começa no topo esquerdo (0,0) e desce para a direita (9,9)
    // Ex: (0,0) -> (1,1) -> (2,2)
    int linD1 = 0, colD1 = 0;
    for (i = 0; i < 3; i++) {
        // Valida se a linha e coluna estão dentro do limite
        if (linD1 + i < 10 && colD1 + i < 10) {
            tabuleiro[linD1 + i][colD1 + i] = 3;
        }
    }


    // POSICIONANDO O NAVIO NA DIAGONAL SECUNDÁRIA (/)

    // Começa na linha 7, coluna 9 e sobe para a esquerda (ou desce invertido).
    // Ex: Linha 7, Coluna 9 -> (7,9) -> (8,8) -> (9,7)
    int linD2 = 7, colD2 = 9;
    for (i = 0; i < 3; i++) {
        // Valida se a linha e coluna estão dentro do limite
        if (linD2 + i < 10 && colD2 - i >= 0) {
            
            // Checagem simples de sobreposição
            // Só coloca se for ÁGUA. Se já tiver navio (3), não faz nada
            if (tabuleiro[linD2 + i][colD2 - i] == 0) {
                tabuleiro[linD2 + i][colD2 - i] = 3;
            }
        }
    }

    // EXIBINDO O TABULEIRO

    printf("\n   --- BATALHA NAVAL ---\n\n");

    printf("    "); // Espaço inicial para alinhar
    for(j = 0; j < 10; j++){
        printf("%d ", j); // Imprime o número da coluna
    }
    printf("\n");


    // Imprime o tabuleiro
    for (i = 0; i < 10; i++) {
        printf("%d | ", i);
        
        for (j = 0; j < 10; j++) {
            // Imprime o valor da célula (0 ou 3) seguido de um espaço
            if(tabuleiro[i][j] == 0) {
                printf(" 0 "); // Agua!
            } else {
                printf(" 3 "); // Navio!
            }
        }
        printf("\n");
    }



    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
