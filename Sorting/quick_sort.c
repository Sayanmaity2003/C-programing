#include<stdio.h>
void display(int [], int);
void quick_Sort(int [], int, int);
int partition(int [], int, int);

int partition(int a[], int lb, int up){
    int pivot = a[lb];
    int st = lb;
    int end = up;
    while(st<end){
        while(a[st]<=pivot){
            st++;
        }
        while(a[end]>pivot){
            end--;
        }
    if(st<end){
        int temp = a[st];
        a[st] = a[end];
        a[end] = temp;
    }

    }
        int temp1 = a[lb];
        a[lb] = a[end];
        a[end] = temp1;
        return end;
}
void quick_Sort(int a[], int lb, int ub){
    if(lb<ub){
        int loc = partition(a, lb, ub);
        quick_Sort(a,lb,loc-1);
        quick_Sort(a,loc+1,ub);
    }
}
// void display(int a[], int n){
//     for(int i=0; i<n; i++){
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }
int main(){
    int size, lb, ub;
    printf("Enter the array size: ");
    scanf("%d",&size);
    int a[size];
    for(int i=0; i<size; i++){
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    lb = 0;
    ub = size-1;
    printf("Before Sorting...\n");
    for(int i=0; i<size; i++){
        printf("%d ",a[i]);
    }
    quick_Sort(a, lb, ub);
    printf("\nAfter Sorting...\n");
    for(int i=0; i<size; i++){
        printf("%d ",a[i]);
    }
    return 0;
}