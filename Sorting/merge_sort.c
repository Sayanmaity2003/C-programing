#include<stdio.h>
void mergeSort(int [], int, int);
void merge(int [], int, int, int);
void mergeSort(int a[], int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid+1, ub);
        merge(a, lb, mid, ub);
    }
}
void merge(int a[], int lb, int mid, int ub){
    int i, j, k;
    i = lb;
    j = mid+1;
    k = lb;
    int r[ub+1];
    while(i<=mid && j<=ub){
        if(a[i]<a[j]){
            r[k] = a[i];
            k++;
            i++;
        }else{
            r[k] = a[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=ub){
            r[k] = a[j];
            k++;
            j++;
        }
    }else{
        while(i<=mid){
            r[k] = a[i];
            i++;
            k++;
        }
    }
    for(k=lb; k<=ub; k++){
        a[k] = r[k];
    }
}
int main(){
    int size, lb, ub;
    printf("Enter the array size: ");
    scanf("%d",&size);
    int a[size];
    lb = 0;
    ub = size-1;
    for(int i=0; i<size; i++){
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    mergeSort(a, lb, ub);
    printf("After Sorting:\n");
    for(int i=0; i<size; i++){
        printf("a[%d] = %d\n",i,a[i]);
    }
    return 0;
}