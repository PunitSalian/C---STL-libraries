#include<iostream>
using namespace std;




typedef struct node {
	int value;
	struct node* next;
    struct node* prev;
}Listnode;

typedef struct  {

	Listnode* head;
	Listnode* tail;

}FIFO;


void push(FIFO* q,int val) {
	static char headflag = 0;
	Listnode* temp;
	temp=(Listnode*)malloc(sizeof(Listnode));
	temp->next = NULL;
	temp->prev = NULL;
	temp->value = val;
	if (headflag == 0) {
		q->head = temp;
		headflag = 1;
	}
	temp->next = q->tail;
	if(q->tail!=NULL){
		q->tail->prev = temp;
	}	
	q->tail = temp;

}

void pop(FIFO* q) {

	q->head->prev->next = NULL;

	Listnode* temp=q->head;
	
	q->head = q->head->prev;

	free(temp);
}


int front(FIFO* q) {
	return q->head->value;

}


int back(FIFO* q) {
	return q->tail->value;
}

void main() {
	//Stk* s = NULL;
	FIFO q = {NULL,NULL};

	push(&q, 5);

	push(&q, 6);

	push(&q,8);

	push(&q, 7);

	pop(&q);
	
	pop(&q);

	printf("%d \n",back(&q));

	printf("%d \n", front(&q));

}
