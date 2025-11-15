#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Con esto limitamos el tama�o de la matriz  10x10
#define MAX 10

//Usamos void para que no devuelva nada y solo accione
void mostrarMatriz(int n, int matriz[MAX][MAX]){
    for(int=0; i<n; i++){
        for(int j=0; j<n; j++){
                printf("%3d", matriz[i][j]);
    }
    printf("\n");
    }
}

//Esta será otra matriz
void transpuesta(int n, int matriz[MAX][MAX]){
int i, j;
printf("matriz transpuesta: \n");
    for(i=0; i<n, i++){
        for (j=0; j<n; j++){
            printf("%d", matriz[j][i]);
        }
    printf("\n");
    }
}

//Diagonal Principal
void diagonalPrincipal(int n, int matriz[MAX][MAX]){
    int i;
    printf("Diagonal principal: \n);
        for(i=0; i<n; i++){
            printf("%d", matriz[i][i]);
        }
        printf("\n");
    }

//Diagonal Secundaria
void diagonalSecundaria(int n, int matriz[MAX][MAX]){
    int i;
    printf("Diagonal secundaria:\n"]);
        for(i=0; i<n; i++){
            printf("%d", matriz[i][n-1-i]);
        }
         printf("\n");
    }

//SumaDiagonalPrincipal
int sumaDiagonalPrincipal(int n, int matriz[MAX][MAX]){
    int i, suma = 0;
        for(i=0; i<n; i++){
            suma += matriz[i][i];
        }
        return suma;
        }

}


}
