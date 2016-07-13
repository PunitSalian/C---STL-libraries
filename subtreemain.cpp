/*
* subtree.cpp
*
*  Created on: June 12, 2016
*      Author: punit
*/
/*
 tree:
      |A|
			/  \
		 /    \
	 |B|     |E|
	 / \     / \
	/   \   /   \
|C|  |D| |F|  |G|
					   \
						\
						|H|
subtree:correct testcase
		 |E|
		 / \
		/   \
	 |F|  |G|
			    \
			     \
			     |H|

subtree:incorrect testcase
			  |E|
			  / \
			 /   \
			|F|  |G|



Running time:O(n)


Algo:
Inorder and postorder traversals of the big tree  are stored in inordertree and postordertree.

Inorder and postorder traversals of small tree or Tree1 are inordersubtree and postordersubtree

if inordersubtree and postordersubtree are substring of inordertree and postordertree then its a subtree else not


*/
#include <iostream>


using namespace std;

//global variables
string inordertree;
string postordertree;
string inordersubtree;
string postordersubtree;

class Node
{
public:
	Node *left;
	Node *right;
	char data;

	Node(char tempdata)
	{

		this->data = tempdata;
		this->left = NULL;
		this->right = NULL;
	}
	bool static	issubtree(Node*, Node*);
	void static getinorder(Node*, string&);
	void static getpostorder(Node*, string&);
	bool static match();
};



//function stores the path traversed using inorder fashion
void Node::getinorder(Node* temproot, string& temp)
{
	if (temproot == NULL)
	{

		return;
	}
	getinorder(temproot->left, temp);
	temp.push_back(temproot->data);
	getinorder(temproot->right, temp);

}

//function stores the path traversed using postorder fashion
void Node::getpostorder(Node* temproot, string& temp)
{

	if (temproot == NULL)
	{

		return;
	}
	getpostorder(temproot->left, temp);
	getpostorder(temproot->right, temp);
	temp.push_back(temproot->data);
}

//checks for subarray case 
bool Node::match()
{
	if ((inordertree.find(inordersubtree) != string::npos) && (postordertree.find(postordersubtree) != string::npos))
	{
		return true;
	}
	else
		return false;

}


//returns true if subtree else false
bool Node::issubtree(Node* temproot1, Node* temproot2)
{

	getinorder(temproot1, inordertree);
	getinorder(temproot2, inordersubtree);

	getpostorder(temproot1, postordertree);
	getpostorder(temproot2, postordersubtree);

	return match();


}


int main()
{
	//tree
	Node* root1 = new Node('A');
	Node* b = new Node('B');
	Node* c = new Node('E');
	Node* d = new Node('C');
	Node* e = new Node('D');
	Node* f = new Node('F');
	Node* g = new Node('G');
	Node* h = new Node('H');

	root1->left = b;
	root1->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	g->right = h;

	//subtree:correct testcase
	Node* root2 = new Node('E');
	Node* a2 = new Node('F');
	Node* b2 = new  Node('G');
	Node* c2 = new Node('H');

	root2->left = a2;
	root2->right = b2;
	b2->right = c2;

	/*
	//subtree:incorrect testcase
		Node* root2 = new Node('E');
		Node* a2 = new Node('F');
		Node* b2 = new  Node('G');
		Node* c2 = new Node('H');

		root2->left = a2;
		root2->right = b2;


	*/




	if (Node::issubtree(root1, root2))
		cout << "testcase is subtree of the main tree" << endl;
	else
		cout << "testcase is not subtree of the main tree" << endl;









}
