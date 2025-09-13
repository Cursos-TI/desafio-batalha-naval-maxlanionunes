#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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

    char coluna_tabuleiro[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char tabuleiro[11][11] = {0}; // Tabuleiro 10x10 inicializado com 0

    #define NAVIO 3 // Valor para representar um navio no tabuleiro
    #define CONE 1 // Valor para representar habilidade em cone
    #define OCTAEDRO 8 // Valor para representar habilidade em octaedro
    #define CRUZ 4 // Valor para representar habilidade em cruz
    

    // Posicionar as colunas do tabuleiro
    printf("  ");
    for (int i = 0; i < 10; i++) {
        printf(" %c", coluna_tabuleiro[i]);
    }

    printf("\n");   
  
    // Posicionamento dos navios
    // Posiciona um navio na diagonal no tabuleiro usando repetições
    /*
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[i][i] = NAVIO; // Posiciona o navio na diagonal
    }       
 

    // Posiciona um navio na diagonal no tabuleiro usando repetições de trás para frente
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[i][9 - i] = NAVIO; // Posiciona o navio na diagonal
    }

    //Posiciona um navio na diagonal no tabuleiro usando repetições de trás para frente começando de baixo para cima
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[9 - i][9 - i] = NAVIO; // Posicion
    }
    //Posiciona um navio na diagonal no tabuleiro usando repetições começando de baixo para cima
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[9 - i][i] = NAVIO; // Posiciona o navio na diagonal
    }   
*/

    // Posiciona figura de cone no tabuleiro
    int centro_x = 0; // Centro do cone na linha 5 (índice 4)
    int centro_y = 2; // Centro do cone na coluna 5 (índice 4)
    int altura_cone = 3; // Altura do cone     
    for (int i = 0; i < altura_cone; i++) {
        for (int j = -i; j <= i; j++) {
            int x = centro_x + i;
            int y = centro_y + j;
            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                tabuleiro[x][y] = CONE; // Marca a área do cone
            }
          
        }
      
    }

// Posiciona figura de octaedro no tabuleiro
    centro_x = 5; // Centro do octaedro na linha 5 (índice 4)
    centro_y = 5; // Centro do octaedro na coluna 5 (índice 4)
    int altura_octaedro = 2; // Altura do octaedro
    for (int i = -altura_octaedro; i <= altura_octaedro; i++) {
        for (int j = -altura_octaedro; j <= altura_octaedro; j++) {
            if (abs(i) + abs(j) <= altura_octaedro) {
                int x = centro_x + i;
                int y = centro_y + j;
                if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                    tabuleiro[x][y] = OCTAEDRO; // Marca a área do octaedro
                }
            }
        }
    }   

    // Posiciona figura de cruz no tabuleiro
    centro_x = 8; // Centro da cruz na linha 8 (índice 7)
    centro_y = 2; // Centro da cruz na coluna 2 (índice 1)
    int tamanho_cruz = 1; // Tamanho da cruz
    for (int i = -tamanho_cruz; i <= tamanho_cruz; i++) {
        int x1 = centro_x + i;
        int y1 = centro_y;
        int x2 = centro_x;
        int y2 = centro_y + i;
        if (x1 >= 0 && x1 < 10 && y1 >= 0 && y1 < 10) {
            tabuleiro[x1][y1] = CRUZ; // Marca a área da cruz (linha)
        }
        if (x2 >= 0 && x2 < 10 && y2 >= 0 && y2 < 10) {
            tabuleiro[x2][y2] = CRUZ; // Marca a área da cruz (coluna)
        }
    }


    // Exibição do tabuleiro
    for (int i = 0; i < 10; i++) {
        
        if (i < 9) {
            printf(" %d ", i + 1); // Exibe o número da linha com espaço extra para alinhamento
        } else {

        printf("%d ", i + 1); // Exibe o número da linha
        }


        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }   

    return 0;
}
