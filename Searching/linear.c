//Linear Search
#include<stdio.h>
void reclinear(int a[], int n, int key); //Recursion function
void reclinear(int a[], int n, int key){
    if(n<0){
        printf("Element not found!!!");
    }else if(a[n]==key){
        printf("Element found at index: %d",n);
    }else{
        reclinear(a, n-1, key);
    }
}
void linear(int a[], int n, int key); //Normal Function
void linear(int a[], int n, int key){
    int flag = 0;
    for(int i=0; i<n; i++){
        if(a[i]==key){
            printf("Element found at index: %d",i);
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("Element not found");
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
    linear(a, n, key);

    return 0;
}

