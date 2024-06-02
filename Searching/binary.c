//Binary Search
#include<stdio.h>
void recbinary(int a[], int key, int lb, int ub);//Using recursion
void recbinary(int a[], int key, int lb, int ub){
    int mid = (lb+ub)/2;
    if(lb>ub){
        printf("Key not found\n");
    }else if(key==a[mid]){
        printf("Key element is found at index: %d",mid);
    }else if(key<a[mid]){
        recbinary(a, key, lb, mid-1);
    }else{
        recbinary(a, key, mid+1, ub);
    }
}
void binary(int a[], int key, int lb, int ub);//Using normal function
void binary(int a[], int key, int lb, int ub){
    int flag = 0;
    while(lb<=ub){
        int mid = (lb+ub)/2;
        if(a[mid]==key){
            printf("Element found at index: %d",mid);
            flag = 1;
            break;
        }else if(key<a[mid]){
            ub = mid - 1;
        }else{
            lb = mid + 1;
        }
    }
    if(flag==0){
        printf("Element not found...");
    }
}
int main(){
    int n, key;
    printf("Enter the number: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements: \n");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the key  element: ");
    scanf("%d",&key);
    int lb = 0, ub = n-1;
    recbinary(a, key, 0, n-1);
    return 0;
}
