/*
 * subtreemain.cpp
 *
 *  Created on: Jun 3, 2016
 *      Author: punit
 */



#include<iostream>
#include<string.h>


using namespace std;

class Node
{
Node *left;
Node *right;
int data;
Node(int temdata)
{
this->data=temdata;
this->left=0;
this->right=0;
}
void preorder(Node* t1,Node* t2);
void Inorder(Node* t1,Node* t2);
void Match(String t1,String t2);

};
