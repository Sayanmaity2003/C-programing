#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *f = NULL;
struct node *r = NULL;
void display();
void enqueue();
void dequeue();
void peek();

void display(){
    if(f==NULL && r==NULL){
        printf("Can't print queue is empty\n");
    }else{
        struct node *temp = f;
        printf("Front-> ");
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->link;
        }
            printf("<-Rear");
            printf("\n");
    }
}
void enqueue(){
    if(f==NULL && r==NULL){
        struct node *nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter val: ");
        scanf("%d",&nnode->data);
        nnode->link = NULL;
        f = r = nnode;
        // return r;
    }else{
        struct node *nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter val: ");
        scanf("%d",&nnode->data);
        nnode->link = NULL;
        r->link = nnode;
        r = nnode;
        // return r;
    }
}
void dequeue(){
    if(f==NULL && r==NULL){
        printf("Queue underflow\n");
    }else if(f==r){
        f = r = NULL;
        // return f;
    }else{
        struct node *temp = f;
        f = f->link;
        free(temp);
        // return f;
    }
}
void peek(){
    if(f==NULL && r==NULL){
        printf("No peek element queue is empty\n");
    }else{
        printf("Peek element is: %d\n",f->data);
    }
}
int main(){
    int choice;
    do{
        display();
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.peek\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();
                        break;
            case 2: dequeue();
                        break;
            case 3: peek();
        }
    }while(choice!=4);
}