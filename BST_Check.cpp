#include <iostream>

#define INF 9999

using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

node *createNode(int data){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

bool isBST(node *root,int l,int r){
	if(root == nullptr)
		return true;
	if(root->data < l || root->data > r)
		return false;
	if(isBST(root->left,l,root->data-1) && isBST(root->right,root->data+1,r))
		return true;
	return false;
	
}

int main() {
	// your code goes here
	node *root = createNode(5);
	root->left = createNode(3);
	root->left->left = createNode(2);
	root->left->right = createNode(4);
	root->right = createNode(7);
	root->right->left = createNode(8); //error case
	cout<<isBST(root,-INF,INF)<<endl;
	return 0;
}