//Matrix Chain Multiplication
#include<stdio.h>
#include<limits.h>

int matChain(int a[], int n);
int matChain(int a[], int n){
    int m[n][n], j, min;
    for(int i=0; i<n; i++){
        m[i][i] = 0;
    }

    for(int d=1; d<n-1; d++){
        for(int i=1; i<n-d; i++){
            j = i + d;
            min = INT_MAX;
            for(int k=i; k<j; k++){
                int q = m[i][k] + m[k+1][j] + (a[i-1]*a[k]*a[j]); //Main formula
                if(min>q){
                    min = q;
                }
            }
            m[i][j] = min;
        }
    }

    return m[1][n-1];
}
int main(){
    int size;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    int a[size];
    printf("Enter the elemets: \n");
    for(int i=0; i<size; i++){
        scanf("%d",&a[i]);
    }
    int x = matChain(a, size);
    printf("%d",x);
    return 0;
}