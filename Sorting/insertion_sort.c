#include<stdio.h>
void insertionSort(int *, int);
void printArray(int *, int);
void insertionSort(int *x, int y){
    int temp, j;
    for(int i=1; i<y; i++){ //loop for un-sorted part...
    temp = x[i];
    j = i-1;
    while(j>=0 && x[j]>temp){ //insertion-comparison part
        x[j+1] = x[j];
        j--;
    }
        x[j+1] = temp;
    }
}
void printArray(int *a, int b){
    for(int i=0; i<b; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){ 
//0 1 2 3 4 5
//4 5 6 7 3 2
int a[] = {12, 54, 65, 7, 9};
int n = 5;
printArray(a, n);
insertionSort(a, n);    
printArray(a, n);
return 0;
}