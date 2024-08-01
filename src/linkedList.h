#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
	char *data;
	struct NODE *next;
	struct NODE *prev;
}node;

typedef struct LIST{
	node *head;
	node *tail;
	int count;
}list;

list* createList(){
	list *myList = (list*)malloc(sizeof(list));
	return myList;
}

void addNode(list* myList, char* data){
	if(myList== NULL)
		printf("list doesn't exist.\n");
	node *myNode = (node*)malloc(sizeof(node));
	if(myNode==NULL){
		printf("no space for new node.\n");
		return;
	}
	myNode->data = data;
	myNode->next= NULL;
	myNode->prev = NULL;
	if(myList->count==0){
		myList->head = myNode;
		myList->tail = myNode;
	}
	else{
		myNode->prev = myList->tail;
		myList->tail->next = myNode;
		myList->tail = myNode;
	}
	myList->count++;
}

void removeRandomNode(list* myList, char* dataOut){
	int index=0;
	node *current= NULL, *prev= NULL, *next=NULL;
	if(myList==NULL || myList->count==0){
		printf("List is empty or doesn't exist");
		return;
	}
	index = rand()% ((myList->count)+1)+1;
	if(index <= myList->count){
		current = myList->head;
	for(int i=1; i<index; i++){
		current = current->next;
		}
	}
	else{
		current = myList->tail;
		for(int i=myList->count; i>index; i--){
			current = current->prev;
		}
	}
	strcpy(dataOut, current->data);
	prev= current->prev;
	next=current->next;

	if(prev==NULL){
		myList->head=next;
	}
	else if(next==NULL){
		myList->tail= prev;
	}
	else{
		prev->next = next;
		next->prev = prev;
	}

	free(current);
	myList->count--;
}
