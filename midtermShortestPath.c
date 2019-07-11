#include <stdio.h>
#include <stdio.h>
#define M 5
#define N 8
void printMatrix(int A[M][N]){
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%d - ", A[i][j]);
            printf("\n");
    }
}

int findShortest(int x , int y, int visited[M][N], int mat[M][N]){
    if((x == M - 1) && (y == N - 1)){
        visited[x][y] = 1;
        return 1;
    }
    if(x >= 0 && x < M && y >= 0 && y <= N && visited[x][y] == 0 && mat[x][y] == 1 ){
        visited[x][y] = 1;
        if(findShortest(x+1, y, visited,mat) == 1){
            printf("Assagı gidildi\n" );
            return 1;
        }
        if(findShortest(x,y+1, visited,mat) == 1){
            printf("Saga gidildi\n" );
            return 1;
        }
        if(findShortest(x-1, y, visited,mat) == 1) {
            printf("Yukarı gidildi\n");
            return 1;
        }
        if(findShortest(x, y - 1, visited,mat) == 1) {
            printf("Sola gidildi\n" );
            return 1;
        }
        visited[x][y] = 0;
        return 0;
    }
    return 0;
}
int main(){
    int mat[M][N] =
    {
        {1,0,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,1},
        {1,0,1,1,1,0,1,1},
        {1,0,0,0,1,0,1,0},
        {1,1,1,1,1,0,1,1},
    };

    int visited[M][N] =
    {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
    };

    if(findShortest(0,0,visited,mat) == 1){
        printMatrix(visited);
    }
    else
        printf("En kısa yol bulunamadı.\n");
    return 0;
}
