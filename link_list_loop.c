//Program to find a loop in a given linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *createNode(int data){
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

NODE *insertNode(NODE *h,int data){
	NODE *temp = h,*newNode=createNode(data);
	if(h == NULL){
		h = newNode;
		return h;
	}
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
	return h;
}

int checkLoop(NODE *h){
	NODE *one_step = h,*two_step = h;
	while(one_step != NULL && two_step != NULL && two_step->next != NULL){
		one_step = one_step->next;
		two_step = two_step->next->next;
		if(one_step == two_step)
			return 1;
	}
	return 0;
}

int main(){
	NODE *head = NULL;
	head = insertNode(head,1);
	head = insertNode(head,2);
	head = insertNode(head,3);
	head->next->next->next = head->next; //Creating a loop
	int status = checkLoop(head) == 1?printf("Loop Exists\n"):printf("No Loop Exists\n");
	return 0;
}