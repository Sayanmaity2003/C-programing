#include<stdio.h>
void display(int [], int);
void insertionSort(int [], int);

void insertionSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min]){
                min = j;
            }
            if(min!=i){
                int temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }
        }
    }
}
void display(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int size;
    printf("Enter the array sieze: ");
    scanf("%d",&size);
    int a[size];
    for(int i=0; i<size; i++){
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    printf("Before Sorting...\n");
    display(a,size);
    insertionSort(a,size);
    printf("After Sorting...\n");
    display(a,size);
    return 0;
}