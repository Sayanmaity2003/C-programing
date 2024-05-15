#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
int len(struct node *);
struct node *initll();
void display(struct node *);
struct node *insertAtFirst(struct node *);
struct node *insertAtEnd(struct node *);
struct node *insertAtLoc(struct node *);
struct node *deleteAtFirst(struct node *);
struct node *deleteAtEnd(struct node *);
struct node *deleteAtLoc(struct node *);
struct node *initll(){
    return NULL;
}
int len(struct node *head){
    struct node *temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->link;
    }
    return count;
}
void display(struct node *head){
    if(head == NULL){
        printf("List is Empty\n");
    }else{
        struct node *temp = head;
        printf("Head-> ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("<-NULL\n");
        printf("\n");
    }
}
struct node *insertAtFirst(struct node *head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(0);
    }else{
        printf("Enter val: ");
        scanf("%d",&newnode->data);
        newnode->link = head;
        head = newnode;
        return head;
    }
}
struct node *insertAtEnd(struct node *head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(0);
    }else{
        printf("Enter val: ");
        scanf("%d",&newnode->data);
        newnode->link = NULL;
        struct node *temp = head;
        while(temp->link!=NULL){
            temp = temp->link;
        }
        temp->link = newnode;
        return head;
    }
}
struct node *insertAtLoc(struct node *head){
    int loc, ln, i;
    ln = len(head);
    printf("Enter the location: ");
    scanf("%d",&loc);
    if(loc>=1 && loc<=ln+1){
        if(loc==1){
            head = insertAtFirst(head);
        }else if(loc==(ln+1)){
            head = insertAtEnd(head);
        }else{
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter val: ");
            scanf("%d",&newnode->data);
            struct node *temp = head;
            int i = 1;
            while(i<loc-1){
                temp = temp->link;
                i++;
            }
            newnode->link = temp->link;
            temp->link = newnode;
        }
    }else{
        printf("Invalid Location!!!\n");
        exit(0);
    }
    return head;
}
struct node *deleteAtFirst(struct node *head){
    if(head==NULL){
        printf("List is empty\n");
    }else{
        struct node *temp = head;
        head = head->link;
        printf("%d is deleted\n",temp->data);
        free(temp);
        return head;
    }
}
struct node *deleteAtEnd(struct node *head){
    if(head==NULL){
        printf("List is empty\n");
    }else{
        struct node *temp1 = head;
        struct node *temp2 = head->link;
        while(temp2->link!=NULL){
            temp1 = temp2;
            temp2 = temp2->link;
        }
        temp1->link = NULL;
        printf("%d is deleted\n",temp2->data);
        free(temp2);
        return head;
    }
}
struct node *deleteAtLoc(struct node *head){
    if(head==NULL){
        printf("List is empty\n");
    }else{
        int loc, l;
        l = len(head);
        printf("Enter location to delete: ");
        scanf("%d",&loc);
        if(loc>=1 && loc<=l){
            if(loc==1){
                head = deleteAtFirst(head);
                return head;
            }else if(loc==l){
                head = deleteAtEnd(head);
                return head;
            }else{
                struct node *temp = head;
                struct node *temp1 = head->link;
                for(int i=1; i<loc-1; i++){
                    temp = temp1;
                    temp1 = temp1->link;
                }
                temp->link = temp1->link;
                printf("%d is deleted\n",temp1->data);
                free(temp1);
                return head;
            }
        }
    }
}
int main(){
    int choice, l;
    struct node *head = initll(); //initialising linked-list
    do{
        l = len(head);
        printf("Length: %d\n",l);
        display(head);
        printf("-------Insertion------\n");
        printf("1.Insert At First\n");
        printf("2.Insert At End\n");
        printf("3.Insert At Location\n");
        printf("-------Deletion------\n");
        printf("4.Delete At First\n");
        printf("5.Delete At End\n");
        printf("6.Delete At Location\n");
        printf("7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: head = insertAtFirst(head);
                    break;
            case 2: head = insertAtEnd(head);
                    break;
            case 3: head = insertAtLoc(head);
                    break;
            case 4: head = deleteAtFirst(head);
                    break;
            case 5: head = deleteAtEnd(head);
                    break;
            case 6: head = deleteAtLoc(head);

        }
    }while(choice!=7);
    return 0;
}