/*
 * commonancestor.cpp
 *
 *  Created on: May 17, 2016
 *      Author: punit
 */
/*
                       |root|
                       /    \
                      /      \
                    |2|      |3|
                    / \      / \
                   /   \    /   \
                  |4|  |5| |6|  |7|
                         \
                          \
                          |8|
*/
#include<iostream>
#include<list>

using namespace std;

class Node
{
public:
	int key;
	Node* left;
	Node* right;
	Node(int temp)
	{
		this->key=temp;
		this->left=NULL;
		this->right=NULL;
	}
	bool static findpath(Node *, Node*,list<int> &temp);

};

/*
* Function name: findpath
* Description  : Takes the root node as input  and destination node as input finds the path puts in the list
*
*
*

* Arguments    : Node* and list
* Return value : none

*/

bool  Node::findpath(Node *root, Node* dest,list<int> &temp)// target)
{
	// base cases
	if (root == NULL)
		return false;


	//If target is present in either left or right subtree of this node,
     //then insert this node in the list as the path
	if ( (root == dest)||findpath(root->left, dest,temp) ||
			findpath(root->right, dest,temp) )
	{
		temp.push_back(root->key);

		return true;
	}

	/* Else return false */
	return false;
}


/*
* Function name: Lca
* Description  : Takes the input lists finds the lowest common ancestor
*
*
*

* Arguments    : list<int>
* Return value : none
*/
void Lca(list<int> &temp1,list<int> &temp2)
{   unsigned x;
temp1.reverse();
temp2.reverse();
unsigned int minlength = min(temp1.size(), temp2.size());

for (unsigned int i = 0; i < minlength ; i++)
{
	if(temp1.front()==temp2.front())
	{
		x=temp1.front();
		temp1.pop_front();
		temp2.pop_front();
	}
}
cout<<x;
}


/*
* Function name: check
* Description  : Takes the input string puts the character in stack to check whether parentheses is balanced or not
*
*
*

* Arguments    : string
* Return value : none
*/
int main()
{
	list<int> path1;
	list<int> path2;

	Node root=Node(1);
	Node b=Node(2);
	Node c= Node(3);
	Node d= Node(4);
	Node e=Node(5);
	Node f= Node(6);
	Node g=Node(7);
	Node h= Node(8);

	root.left=&b;
	root.right=&c;
	b.left=&d;
	b.right=&e;
	e.right=&h;
	c.left=&f;
	c.right=&g;

	Node::findpath(&root,&d, path1);
	Node::findpath(&root,&e, path2);




	Lca(path1,path2);

	return 0;
}

