#include<stdio.h>
#include<stdlib.h>
int a[20],c;

int place(int row, int col){
    int i;
    for(int i=1; i<=row-1; i++){
        if(a[i]==col){
            return 0;
        }else if(abs(a[i]-col)==abs(i-row)){
            return 0;
        }
    }
    return 1;
}

void display(int n){
    int i, j;
    printf("\n Solution %d :",c++);
        for(int i=1; i<=n; i++){
            printf("\n%d",i);
            for(int j=1; j<=n; j++){
                if(a[i]==j){
                    printf("\tQ");
                }else{
                    printf("\t-");
                }
            }
        }
}

void nqueen(int row, int n){
    int col;
    for(col=1; col<=n; col++){
        if(place(row,col)){
            a[row] = col;
            if(row==n){
                display(n);
            }else{
                nqueen(row+1,n);
            }
        }
    }
}
int main(){
    int q;
    printf("Enter the number of queens: ");
    scanf("%d",&q);
    nqueen(1, q);
}