#include<stdio.h>
void floydWar(int size);
void floydWar(int size){
    int arr[size][size];
    printf("Enter the array elements: ");
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int k=0; k<size; k++){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(arr[i][j]>(arr[i][k]+arr[k][j])){
                       arr[i][j] =  arr[i][k]+arr[k][j];
                }
            }
        }
    }
    printf("Resultant array: \n");
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
           printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int size;
    printf("Enter the size of the matrix: ");
    scanf("%d",&size);
    floydWar(size);
    return 0;
}
