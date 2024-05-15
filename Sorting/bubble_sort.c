#include<stdio.h>
void printArray(int *, int);
void bubbleSort(int *, int);
void printArray(int *a, int b){
    for(int i=0; i<b; i++){
        printf("%d ",a[i]);
    }
}
void bubbleSort(int *x, int y){
    int isSorted;
    for(int i=0; i<y-1; i++){//for number of pases
    printf("\nSorted array found in pass %d",i+1);
    isSorted = 1;
        for(int j=0; j<y-1-i; j++){ // for comparison in each pass
            if(x[j]>x[j+1]){
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}
int main(){
    int a[] = {12, 54, 65, 7, 23, 9};
    // int a[] = {1,2,6,8,9,10};
    int n = 6;
    printf("printing array before sorting\n");
    printArray(a, n);
    bubbleSort(a, n);
    printf("\nprinting array after sorting\n");
    printArray(a, n);
return 0;
}