//Circular Queue
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *insertAtBeg(struct node *);
struct node *insertAtEnd(struct node *);
struct node *insertAtloc(struct node *);
struct node *deleteAtBeg(struct node *);
struct node *deleteAtEnd(struct node *);
struct node *deleteAtloc(struct node *);
void display(struct node *);
int count_nodes(struct node *);

struct node *insertAtBeg(struct node *tail){
	struct node *nnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&nnode->data);
	if(tail==NULL){
		tail = nnode;
		tail->next = tail;
	}else{
		nnode->next = tail->next;
		tail->next = nnode;
	}
	return tail;
}
struct node *insertAtEnd(struct node *tail){
	struct node *nnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&nnode->data);
	if(tail==NULL){
		tail = nnode;
		tail->next = tail;
	}else{
		nnode->next = tail->next;
		tail->next = nnode;
		tail = nnode;
	}
	return tail;
}
struct node *insertAtloc(struct node *tail){
	int loc, len;
	len = count_nodes(tail); 
	printf("Enter the location: ");
	scanf("%d",&loc);
	if(loc>=1 && loc<=len+1){
		if(loc==1){
			tail = insertAtBeg(tail);
			return tail;
		}else if(loc==len+1){
			tail = insertAtEnd(tail);
			return tail;
		}else{
			struct node *nnode = (struct node *)malloc(sizeof(struct node));
			printf("Enter the data: ");
			scanf("%d",&nnode->data);
			int i=1; 
			struct node *temp = tail->next;
			while(i<loc-1){
				temp = temp->next;
				i++;
			}
			nnode->next = temp->next;
			temp->next = nnode;
		}
		return tail;
	}else{
		printf("Enter valid location!!!\n");
	}
}
struct node *deleteAtBeg(struct node *tail){
	if(tail==NULL){
		printf("Can't delete, Circular List is empty\n");
	}else if(tail->next==tail){
		printf("%d is deleted\n",tail->data);
		free(tail);
		return NULL;
	}else{
		struct node *head = tail->next;
		tail->next = tail->next->next;
		printf("%d is deleted\n",head->data);
		free(head);
		return tail;
	}
}
struct node *deleteAtEnd(struct node *tail){
	if(tail==NULL){
		printf("Can't delete, Circular List is empty\n");
	}else if(tail->next==tail){
		printf("%d is deleted\n",tail->data);
		free(tail);
		return NULL;
	}else{
		struct node *temp = tail->next;
		while(temp->next!=tail){
			temp = temp->next;
		}
		temp->next = tail->next;
		printf("%d is deleted\n",tail->data);
		free(tail);
		tail = temp;
		return tail;
	}
}
struct node *deleteAtloc(struct node *tail){
	int loc;
	printf("Enter the location: ");
	scanf("%d",&loc);
	int len = count_nodes(tail);
	if(loc>=1 && loc<=len){
		if(loc==1){
			tail = deleteAtBeg(tail);
			return tail;
		}else if(loc==len){
			tail = deleteAtEnd(tail);
			return tail;
		}else{
			struct node *temp1 = tail->next;
			struct node *temp2 = tail->next->next;
			int i = 1;
			while(i<loc-1){
				temp1 = temp2;
				temp2 = temp2->next;
				i++;
			}
			temp1->next = temp2->next;
			printf("%d is deleted\n",temp2->data);
			free(temp2);
			return tail;
		}
	}
}
void display(struct node *tail){
	if(tail==NULL){
		printf("Circular list is empty\n");
	}else{
		struct node *temp = tail;
		do{
			printf("%d ",temp->next->data);
			temp = temp->next;
		}while(temp!=tail);
		printf("\n");
	}
}
int count_nodes(struct node *tail){
	struct node *temp = tail;
	int count = 0;
	do{
		count++;
		temp = temp->next;
	}while(temp!=tail);
	return count;
}
int main(){
	int choice;
	struct node *tail = NULL;
	do{
	display(tail);
	printf("--------Insertion--------\n");
	printf("1.insertAtBeg()\n");
	printf("2.insertAtEnd()\n");
	printf("3.insertAtLoc()\n");
	printf("--------Deletion----------\n");
	printf("4.deleteAtBeg()\n");
	printf("5.deleteAtEnd()\n");
	printf("6.deleteAtLoc()\n");
	printf("---------Others------------\n");
	printf("7.count_nodes\n");
	printf("8.Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: tail = insertAtBeg(tail);
				break;
		case 2: tail = insertAtEnd(tail);
				break;
		case 3: tail = insertAtloc(tail);
				break;
		case 4: tail = deleteAtBeg(tail);
				break;
		case 5: tail = deleteAtEnd(tail);
				break;
		case 6: tail = deleteAtloc(tail);
				break;
		case 7: printf("No of nodes is: %d\n",count_nodes(tail));
	}
	}while(choice!=8);
	return 0;
}