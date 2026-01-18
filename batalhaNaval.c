#include <stdio.h>
#include <stdlib.h> // Necessário para usar a função abs()

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

    // Nível Mestre

    // MATRIZES DE HABILIDADES

    int matrizCone[5][5];
    int matrizCruz[5][5];
    int matrizOctaedro[5][5]; 

    // O centro da matriz 5x5 é a posição (2, 2)
    int centroMatriz = 2; 

    // Habilidade Cone

    // Lógica: Forma um triângulo apontando para cima
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            
            // A coluna deve estar dentro da abertura do triângulo baseada na linha
            if (i <= 2 && j >= (centroMatriz - i) && j <= (centroMatriz + i)) {
                matrizCone[i][j] = 1;
            } else {
                matrizCone[i][j] = 0;
            }
        }
    }

    // Habilidade Cruz

    // Lógica: Preenche se for a linha do meio ou a coluna do meio
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == centroMatriz || j == centroMatriz) {
                matrizCruz[i][j] = 1;
            } else {
                matrizCruz[i][j] = 0;
            }
        }
    }

    // Habilidade Octaedro

    // Lógica: Soma da distância horizontal + vertical <= raio
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // abs() pega o valor absoluto (tira o sinal negativo)
            if (abs(i - centroMatriz) + abs(j - centroMatriz) <= 2) {
                matrizOctaedro[i][j] = 1;
            } else {
                matrizOctaedro[i][j] = 0;
            }
        }
    }

    // APLICANDO AS HABILIDADES NO TABULEIRO

    // Variáveis para definir onde o centro da habilidade vai cair no tabuleiro grande
    int origemX, origemY;
    int tabuleiroX, tabuleiroY;

    // Aplicar Cone
    origemX = 1; // Linha 1 do tabuleiro
    origemY = 2; // Coluna 2 do tabuleiro
    
    // Loop para percorrer a matriz da habilidade (5x5)
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            
        
            // Se i=0 e centroMatriz=2, o deslocamento é -2.
            tabuleiroX = origemX + (i - centroMatriz);
            tabuleiroY = origemY + (j - centroMatriz);

            // VERIFICAÇÃO DE SEGURANÇA (Limites do Tabuleiro)
            // Só aplicamos se a coordenada calculada existir no tabuleiro 10x10
            if (tabuleiroX >= 0 && tabuleiroX < 10 && tabuleiroY >= 0 && tabuleiroY < 10) {
                // Se na máscara for 1, aplicamos o efeito no tabuleiro
                if (matrizCone[i][j] == 1) {
                    tabuleiro[tabuleiroX][tabuleiroY] = 5;
                }
            }
        }
    }

    // Aplicar Cruz no Centro
    origemX = 5; // Linha 5
    origemY = 5; // Coluna 5

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            tabuleiroX = origemX + (i - centroMatriz);
            tabuleiroY = origemY + (j - centroMatriz);

            if (tabuleiroX >= 0 && tabuleiroX < 10 && tabuleiroY >= 0 && tabuleiroY < 10) {
                if (matrizCruz[i][j] == 1) {
                    tabuleiro[tabuleiroX][tabuleiroY] = 5;
                }
            }
        }
    }

    // Aplicar Octaedro
    origemX = 8; // Linha 8
    origemY = 8; // Coluna 8

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            tabuleiroX = origemX + (i - centroMatriz);
            tabuleiroY = origemY + (j - centroMatriz);

            if (tabuleiroX >= 0 && tabuleiroX < 10 && tabuleiroY >= 0 && tabuleiroY < 10) {
                if (matrizOctaedro[i][j] == 1) {
                    tabuleiro[tabuleiroX][tabuleiroY] = 5;
                }
            }
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
        printf(" %d ", j); // Imprime o número da coluna
    }
    printf("\n");

    // Imprime o tabuleiro
    for (i = 0; i < 10; i++) {
        printf("%d | ", i); // Imprime o número da linha
        
        for (j = 0; j < 10; j++) {
            
            // Exibição condicional
            switch(tabuleiro[i][j]) {
                case 0:
                    printf(" 0 "); // Água
                    break;
                case 3:
                    printf(" 3 "); // Navio Intacto
                    break;
                case 5:
                    printf(" 5 "); // Área da Habilidade
                    break;
                default:
                    printf(" 0 ");
            }
        }
        printf("\n");
    } 

    printf("\nLegenda: 0 = Agua, 3 = Navio, 5 = Habilidade Especial\n");

    return 0;




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
} 


