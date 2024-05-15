#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
void display(struct node *);
int len(struct node *);
struct node *insertAtbeg(struct node *);
struct node *insertAtend(struct node *);
struct node *insertAtloc(struct node *);
struct node *deleteAtbeg(struct node *);
struct node *deleteAtend(struct node *);
struct node *deleteAtloc(struct node *);
void display(struct node *head){
    if(head==NULL){
        printf("Can't display list is empty\n");
    }else{
        struct node *temp=head;
        printf("NULL<- ");
        while(temp->next!=NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
            printf("%d",temp->data);
            printf(" <-NULL\n");
    }
}
int len(struct node *head){
    struct node *temp = head;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
struct node *insertAtbeg(struct node *head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head==NULL){
        head = newnode;
    }else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
struct node *insertAtend(struct node *head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if(head==NULL){
        head = newnode;
    }else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    return head;
}
struct node *insertAtloc(struct node *head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int loc, ln;
    printf("Enter location: ");
    scanf("%d",&loc);
    ln = len(head);
    if(head==NULL){
        printf("Enter the value: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        return head;
    }else if(loc>=1 && loc<=ln+1){
        if(loc==1){
            head = insertAtbeg(head);
        }else if(loc==ln+1){
            head = insertAtend(head);
        }else{
            printf("Enter the value: ");
            scanf("%d",&newnode->data);
            newnode->next = NULL;
            newnode->prev = NULL;
            struct node* temp = head;
            int i = 1;
            while(i<loc-1){
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
            newnode->next->prev = newnode;
        }
    }
    return head;
}
struct node *deleteAtbeg(struct node *head){
    if(head==NULL){
        printf("Can't delete list is empty\n");
    }else{
        struct node *temp = head;
        head = head->next;
        printf("%d is deleted\n",temp->data);
        free(temp);
        return head;
    }
}
struct node *deleteAtend(struct node *head){
    if(head==NULL){
        printf("Can't delete list is empty\n");
    }else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        printf("%d is deleted\n",temp->data);
        free(temp);
        return head;
    }
}
struct node *deleteAtloc(struct node *head){
    if(head==NULL){
        printf("Can't delete list is empty\n");
    }else{
        int ln = len(head), loc;
        printf("Enter location: ");
        scanf("%d",&loc);
        if(loc>=1 && loc<=ln){
        if(loc==1){
            head = deleteAtbeg(head);
        }else if(loc==ln){
            head = deleteAtend(head);
        }else{
            struct node* temp = head;
            int i = 1;
            while(i<loc){
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
    return head;
    }
}
int main(){
    int choice, l;
    struct node *head = NULL;
    do{
        display(head);
        printf("------Operations-----\n");
        printf("1.insertAtbeg\n");
        printf("2.insertAtend\n");
        printf("3.insertAtloc\n");
        printf("4.deleteAtbeg\n");
        printf("5.deleteAtend\n");
        printf("6.deleteAtloc\n");
        printf("7.length of the list\n");
        printf("8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: head = insertAtbeg(head);
                    break;
            case 2: head = insertAtend(head);
                    break;
            case 3: head = insertAtloc(head);
                    break;
            case 4: head = deleteAtbeg(head);
                    break;
            case 5: head = deleteAtend(head);
                    break;
            case 6: head = deleteAtloc(head);
                    break;
            case 7: l = len(head);
                    printf("Length of the list is: %d\n",l);
                    break;
        }
    }while(choice!=8);
    printf("Program exited successfully\n");
    return 0;
}