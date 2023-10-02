#include <stdio.h>
#include <stdlib.h>

int min(int i,int j){
    if(i <= j){
        return i;
    }
    else{
        return j;
    }
}

void Allpaths(int **cost,int **A,int n)

{
    /* cost [1:n,1:n] is the cost adjacency matrix of a graph with n vertices,
A[i,j] is the cost of a shortest path from vertex i to vertex j cost[i,i] = 0.0
for 1<=i<=n */
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            A[i][j] = cost[i][j];
        }
    }

    for(int k = 0;k < n;k++){
        for(int i = 0;i < n; i++){
            for(int j = 0;j < n;j++){
                A[i][j] = min(A[i][j],A[i][k] + A[k][j]);
            }
        }
    }
}


int main(){
    int n = 3; 
    int **cost = malloc(n * sizeof(int *));
    int **A = malloc(n * sizeof(int *));
    
    for (int i = 0; i < n; i++) {
        cost[i] = malloc(n * sizeof(int));
        A[i] = malloc(n * sizeof(int));
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Enter cost of vertex %d to %d",i,j);
            scanf("%d",&cost[i][j]);
        }
    }

    Allpaths(cost,A,3);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}