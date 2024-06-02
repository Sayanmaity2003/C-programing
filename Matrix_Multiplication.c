//Matrix Multiplication
#include<stdio.h>
void matmul(int r1, int c1, int r2, int c2){
void matmul(int r1, int c1, int r2, int c2);
    int a[r1][c1];
    int b[r2][c2];
    int c[r1][c2];
    int mul = 0;
    printf("Enter the elements of matrix-1:\n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of matrix-2:\n");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            scanf("%d",&b[i][j]);
        }
    }

    if(c1==r2){
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                mul = 0;
                for(int k=0; k<c1; k++){
                    mul += (a[i][k]*b[k][j]);
                }
                c[i][j] = mul;
            }
        }
    }else{
        printf("Multiplication not possible!!!");
    }
    printf("Matrix-1:\n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix-2:\n");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    printf("Resultant Matrix is:\n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int r1, c1, r2, c2;
    printf("Enter the rows and colums of matrix-1\n");
    printf("Row: ");
    scanf("%d",&r1);
    printf("Column: ");
    scanf("%d",&c1);

    printf("Enter the rows and colums of matrix-2\n");
    printf("Row: ");
    scanf("%d",&r2);
    printf("Column: ");
    scanf("%d",&c2);

    matmul(r1, c1, r2, c2);
    return 0;
}
