#include<iostream>
#include<array>
using namespace std;


#define IS_LEAF true
#define MAX_LEN 26
#define GET_INDEX(x)   ((int)x-(int)'a')


class Node
{
public:
	bool Leaf;
	array<Node*, MAX_LEN> children;
	Node()
	{
		Leaf = !IS_LEAF;
		children.fill(NULL);
	}
};



void insert(Node*root, string x)
{
	//extract single character
	//attach to tree
	for (char ele : x)
	{
		int index = GET_INDEX(ele);
		if (root->children[index] == NULL)
		{
			root->children[index] = new Node();
		}
		root = root->children[index];

	}

	root->Leaf = IS_LEAF;
}



int search(string data, Node *root)
{

	//trverse the tree for the given data if leaf node is found give word found
	for (char ele : data)
	{
		int index = GET_INDEX(ele);

		root = root->children[index];
		if (root == NULL)
			return 0;
	}
	if (root->Leaf == IS_LEAF)
		return 1;
	else
		return 0;
}
int deletenode(string data, Node *root)
{

	//trverse the tree for the given data if leaf node is found make it false so the word is not traced
	for (char ele : data)
	{
		int index = GET_INDEX(ele);

		root = root->children[index];
		if (root == NULL)
			return 0;
	}
	if (root->Leaf == IS_LEAF)
	{
		root->Leaf = !IS_LEAF;
		return 1;
	}
	else
		return 0;
}

int main()
{
	array<string, 3> dataset = { "dogee","doll","cat" };

	Node root = Node();

	for (int i = 0; i < dataset.size(); i++)
	{
		insert(&root, dataset[i]);
	}

	int result1 = deletenode("dog", &root);
	if (result1 == 1)
		cout << "delete successful" << endl;
	else
		cout << "delete not succesful" << endl;


	int result = search("dogee", &root);

	if (result == 1)
		cout << "found" << endl;
	else
		cout << "not found" << endl;

	return 1;

}
