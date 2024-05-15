//Queue using array
#include<stdio.h>
#define N 5
int a[N];
int f = -1;
int r = -1;

int isEmpty();
int isFull();
void enqueue();
void dequeue();
void peek();
void display();

int isEmpty(){
    if(f==-1 && r==-1)
        return 1;
    else    
        return 0;
}
int isFull(){
    if((r+1)%N==f)
        return 1;
    else    
        return 0;
}
void enqueue(){
    if((r+1)%N == f){
        printf("Queue Overflow\n");
    }else if(isEmpty()){
        f = r = 0;
        printf("Enter val: ");
        scanf("%d",&a[r]);
    }else{
        r = (r+1)%N;
        printf("Enter val: ");
        scanf("%d",&a[r]);
    }
}
void dequeue(){
    if(isEmpty()){
        printf("Stack Underflow\n");
    }else if(f==r){
        printf("%d is deleted\n",a[f]);
        f = r = -1;
    }else{
        printf("%d is deleted\n",a[f]);
        f = (f+1)%N;
    }
}
void peek(){
    if(isEmpty()){
        printf("No peek element\n");
    }else{
        printf("Peek element is: %d",a[f]);
    }
}
void display(){
    if(isEmpty()){
        printf("Can't display queue is empty\n");
    }else{
        int i = f;
        printf("Front-> ");
        while(i!=r){
            printf("%d ",a[i]);
            i = (i+1)%N;
        }
            printf("%d ",a[r]);
        printf("<-Rear\n");
        printf("\n");
    }
}
int main(){
    int choice;
    do{
        display();
        printf("1.isEmpty\n");
        printf("2.isFull\n");
        printf("3.Enqueue\n");
        printf("4.Dequeue\n");
        printf("5.Peek\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: if(isEmpty())
                        printf("Queue is Empty\n");
                    else 
                        printf("Queue is not Empty\n");
                    break;
            case 2: if(isFull())
                        printf("Queue is Full\n");
                    else        
                        printf("Queue is not Full\n");
                    break;
            case 3: enqueue();
                    break;
            case 4: dequeue();
                    break;
            case 5: peek();

        }
    }while(choice!=6);
    return 0;
}






