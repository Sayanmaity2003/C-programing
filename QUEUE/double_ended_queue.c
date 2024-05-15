#include<stdio.h>
#define N 5
int arr[N];
int f = -1;
int r = -1;

void insert_At_Front();
void delete_At_Front();
void insert_At_Rear();
void delete_At_Rear();
int isFull();
int isEmpty();
void getFront();
void getRear();
void display();

void display(){
    if(isEmpty()){
        printf("Can't print empty D-Queue\n");
    }else{
        int i;
        i = f;
        printf("Front-> ");
        while(i!=r){
            printf("%d ",arr[i]);
            i = (i+1)%N;
        }
        printf("%d ",arr[r]);
        printf("<-Rear\n");
    }
}
int isFull(){
    if((f==0 && r==N-1) || (f==r+1))
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(f==-1 && r==-1)
        return 1;
    else
        return 0;
}
void insert_At_Front(){
    if(isFull()){
        printf("D-Queue is Full\n");
    }else if(f==0){
        f = N-1;
        printf("Enter val: ");
        scanf("%d",&arr[f]);
    }else if(isEmpty()){
        f = r = 0;
        printf("Enter val: ");
        scanf("%d",&arr[f]);
    }else{
        f--;
        printf("Enter val: ");
        scanf("%d",&arr[f]);
    }
}
void delete_At_Front(){
    if(isEmpty()){
        printf("D-Queue is Empty\n");
    }else if(f==r){
        printf("%d is delted\n",arr[f]);
        f = r = -1;
    }else if(f==N-1){
        printf("%d is delted\n",arr[f]);
        f = 0;
    }else{
        printf("%d is delted\n",arr[f]);
        f++;
    }
    }
void insert_At_Rear(){
    if(isFull()){
        printf("D-Queue is Full\n");
    }else if(isEmpty()){
        f = r = 0;
        printf("Enter val: ");
        scanf("%d",&arr[r]);
    }else if(r==N-1){
        r = 0;
        printf("Enter val: ");
        scanf("%d",&arr[r]);
    }else{
        r++;
        printf("Enter val: ");
        scanf("%d",&arr[r]);
    }
}
void delete_At_Rear(){
    if(isEmpty()){
        printf("D-Queue is Empty\n");
    }else if(f==r){
        printf("%d is delted\n",arr[r]);
        f = r = -1;
    }else if(r==0){
        printf("%d is delted\n",arr[r]);
        r = N-1;
    }else{
        printf("%d is delted\n",arr[r]);
        r--;
    }
}
void getFront(){
    if(isEmpty()){
        printf("D-Queue is Empty\n");
    }else{
        printf("Front element is: %d\n",arr[f]);
    }
}
void getRear(){
    if(isEmpty()){
        printf("D-Queue is Empty\n");
    }else{
        printf("Rear element is: %d\n",arr[r]);
    }
}
void main(){
    int choice;
    do{
        display();
        printf("1.insert_At_Front\n");
        printf("2.delete_At_Front\n");
        printf("3.insert_At_Rear\n");
        printf("4.delete_At_Rear\n");
        printf("5.isFull\n");
        printf("6.isEmpty\n");
        printf("7.getFront\n");
        printf("8.getRear\n");
        printf("9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_At_Front();
                    break;
            case 2: delete_At_Front();
                    break;
            case 3: insert_At_Rear();
                    break;
            case 4: delete_At_Rear();
                    break;
            case 5: if(isFull())
                        printf("D-Queue is Full\n");
                    else
                        printf("D-Queue is not Full\n");
                    break;
            case 6: if(isEmpty())
                        printf("D-Queue is Empty\n");
                    else    
                        printf("D-Queue is not Empty\n");
                    break;
            case 7: getFront();
                    break;
            case 8: getRear();
        }

    }while(choice!=9);
}