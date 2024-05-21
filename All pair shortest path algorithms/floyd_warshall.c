#include<stdio.h>
# define N 9999
void floyd(int a[][3], int n);
void display(int a[][3], int n);

void floyd(int a[][3], int n){  //Main Function
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int t = a[i][k] + a[k][j];
                if(a[i][j]>t){
                    a[i][j] = t;
                }
            }
        }
    }
}
void display(int a[][3], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int size = 4;
    int a[3][3] = {{2, 3, 6}, 
                   {7, 8, 9},
                   {5, 1, 2}};
    printf("Given Matrix is:\n");
    display(a, 3);
    floyd(a, 3);
    printf("Given Matrix after applying floyd warshall algorithm is:\n");
    display(a, 3);

    return 0;
}