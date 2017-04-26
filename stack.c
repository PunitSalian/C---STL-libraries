#include<iostream>
using namespace std;


typedef struct st {
	int value;
	struct st* next;
}Stk;


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


void main() {
	Stk* s = NULL;
	push(&s, 5);
	push(&s, 6);
	push(&s, 7);
	pop(&s);
	printf("Top %d /n", top(&s));
}
