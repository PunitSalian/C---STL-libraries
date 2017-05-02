#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
	int value;
	struct node* left;
	struct node* right;
}Node;

void newnode(Node** node,int val) {
	(*node) = (Node*)malloc(sizeof(Node));
	(*node)->left = NULL;
	(*node)->right = NULL;
	(*node)->value = val;

}

void inorder(Node* head) {
	if (head == NULL) {
		return;
	}
	inorder(head->left);
	printf(" %d ",head->value);
	inorder(head->right);
}


void build_bst() {
	vector<Node*> arr;

	inorder();





}


void main() {
	Node* root = NULL;
	newnode(&root,10);
	newnode(&(root->left),8);
	newnode(&(root->left->left), 7);
	newnode(&(root->left->left->left), 5);
	inorder(root);
}
