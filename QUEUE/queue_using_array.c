#include<stdio.h>
#define N 5
int q[5];
int f = -1;
int r = -1;
int isEmpty();
int isFull();
void enQueue();
void deQueue();
void Front_Rear();
void display();

void display(){
    if(isEmpty()){
        printf("Queue is empty, Can't display\n");
    }else{
        printf("Front-> ");
        for(int i=f; i<=r; i++){
            printf("%d ",q[i]);
        }
        printf("<-Rear");
        printf("\n");
    }
}
void Front_Rear(){
    if(isEmpty()){
        printf("Queue is Empty, hence no front and rear element\n");
    }else{
        printf("Front ELement is: %d\n",q[f]);
        printf("Rear Element is: %d\n",q[r]);
    }
}
void deQueue(){
    if(isEmpty()){
        printf("Can't Pop, qeueue is empty\n");
    }else if(f==r){
        int temp = q[f];
        f = r = -1;
    }else{
        int temp = q[f];
        f++;
    }
}
void enQueue(){
    if(isFull()){
        printf("Can't Push queue is full\n");
    }else if(isEmpty()){
        int val;
        printf("Enter the value: ");
        scanf("%d",&val);
        f = r = 1;
        q[r] = val;
    }else{
        int val;
        printf("Enter the value: ");
        scanf("%d",&val);
        r++;
        q[r] = val;
    }
}
int isEmpty(){
    if(f==-1 && r==-1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(){
    if(r==N-1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int choice;
    do{
        display();
        printf("Available Operations\n");
        printf("1.isEmpty\n");
        printf("2.isFull\n");
        printf("3.enqueue\n");
        printf("4.dequeue\n");
        printf("5.Front and Rear\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: if(isEmpty()){
                        printf("Queue is Empty\n");
                    }else{
                        printf("Queue is not Empty\n");
                    }
                    break;
            case 2: if(isFull()){
                        printf("Queue is Full\n");
                    }else{
                        printf("Queue is not Full\n");
                    }
                    break;
            case 3: enQueue();
                    break;
            case 4: deQueue();
                    break;
            case 5: Front_Rear();
                    break;
            // default: printf("Invalid Choice!!!\n");
        }

    }while(choice!=6);
    return 0;
}