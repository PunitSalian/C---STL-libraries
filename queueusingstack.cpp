#include<iostream>
using namespace std;




typedef struct st {
	int value;
	struct st* next;
}Stk;



typedef struct queu {
	Stk* s1;
	Stk* s2;

}Queue;




void push(Stk** head, int val) {
	Stk* new_node = (Stk*)(malloc(sizeof(Stk)));
	new_node->value = val;
	new_node->next = (*head);
	(*head) = new_node;
}

void pop(Stk** head) {
	Stk* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

int top(Stk** s) {
	return (*s)->value;
}



void queue_push(Queue* q,int val) {
	push(&(q->s1), val);
}


void  queue_pop(Queue* q) {
	Stk* tem;
	while ((q->s1)!= NULL) {
		int temp = top(&(q->s1));
		push(&(q->s2), temp);
		pop(&(q->s1));
	}
	pop(&(q->s2));
}



int queue_back(Queue* q) {
	return top(&(q->s1));
}

int queue_front(Queue* q) {
	return top(&(q->s2));
}

void main() {
	//Stk* s = NULL;
	Queue s = {0};
	queue_push(&s, 5);
	queue_push(&s, 4);
	queue_push(&s, 3);
	queue_push(&s, 2);
	queue_push(&s, 1);
	queue_pop(&s);
	queue_push(&s, 7);
	queue_push(&s, 8);

	//pop(&s);
	printf("Back %d \n", queue_back(&s));

	printf("Front %d \n", queue_front(&s));
}
