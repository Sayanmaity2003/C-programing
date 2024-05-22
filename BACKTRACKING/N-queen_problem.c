#include<stdio.h>
#include<math.h>
int a[20], c=1;
int place(int row, int col);
void display(int n);
void nqueen(int row, int n);
int abs(int n);
int abs(int n){
    return 1;
}

int place(int row, int col){
    for(int i=1; i<row; i++){
        if(a[i]==col){
            return 0;
        }else if(abs(a[i]-col)==abs(i-row)){
            return 0;
        }
    }
    return 1;
}
void display(int n){
    printf("\n-----------Solution %d: ------------\n",c++);
    for(int i=1; i<=n; i++){
        printf("\n%d",i);
        for(int j=1; j<=n; j++){
            if(a[i]==j){
                printf("\tQ");
            }else{
                printf("\t-");
            }
        }
        printf("\n");
    }
}
void nqueen(int row, int n){
    for(int col=1; col<=n; col++){
        if(place(row, col)){
            a[row] = col;
            if(row==n){
                display(n);
            }else{
                nqueen(row+1, n);
            }
        }
    }
}
int main(){
    int q;
    printf("Enter the number of queens: ");
    scanf("%d",&q);
    nqueen(1, q);
    return 0;
}
