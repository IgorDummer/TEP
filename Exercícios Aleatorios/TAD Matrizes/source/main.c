/*
A implementação básica de matriz por alocação dinâmica
(que cria uma matriz de floats usando memoria descontinua e linhas de mesmo tamanho)
Disponível em: http://mtm.ufsc.br/~azeredo/cursoC/aulas/ca70.html

1) Alterem esta implementação, criando outras novas que:
    a) faz a mesma coisa, só que criando uma matriz CONTÍNUA
    b) faz a mesma coisa que a implementação original, só que com linhas de TAMANHOS DIFERENTES
    C) faz a mesma coisa que a implementação original, só que para uma matriz de strings (char *)
    d) faz a mesma coisa que a implementação original, só que para uma matriz de double
    e) faz a mesma coisa que a implementação original para uma matriz de int
    Agora, faça a mesma coisa dos exercícios (a) e (b), só que para os tipos char*, double e int
//Veja que uma matriz de strings é, na verdade, um ponteiro de ponteiro de ponteiro para char .... não é legal?
//Quantas implementações você tem até agora?
//Elas estão, cada uma em um programa diferente?
//Ahhhh.... então tente reunir todas elas em um único programa!!!!
//E aí, vamos conversar sobre a proposta empregada em https://rebelsky.cs.grinnell.edu/musings/cnix-macros-generics
 */
#include <stdio.h>
#include "matriz.h"

int main(){
    int linhas, colunas;
    printf("Diga a quantidade de linhas e colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);

    float **matFloat1, *matFloat2;
    matFloat1 = Alocar_matriz_real(linhas, colunas);
    matFloat2 = MatrizRealCont(linhas, colunas);
    leMatrizFloat(matFloat1, matFloat2, linhas, colunas);
    liberaMatrizesFloat(matFloat1, matFloat2, linhas);

    char ***matString1, **matString2;
    matString1 = Alocar_matriz_string(linhas, colunas);
    matString2 = MatrizStringCont(linhas, colunas);
    leMatrizString(matString1, matString2, linhas, colunas);
    liberaMatrizesString(matString1, matString2, linhas);

    double **matDouble1, *matDouble2;
    matDouble1 = Alocar_matriz_double(linhas, colunas);
    matDouble2 = MatrizDoubleCont(linhas, colunas);
    leMatrizDouble(matDouble1, matDouble2, linhas, colunas);
    liberaMatrizesDouble(matDouble1, matDouble2, linhas);

    int **matInt1, *matInt2;
    matInt1 = Alocar_matriz_inteiro(linhas, colunas);
    matInt2 = MatrizIntCont(linhas, colunas);
    leMatrizInt(matInt1, matInt2, linhas, colunas);
    liberaMatrizesInt(matInt1, matInt2, linhas);

    return 0;
}