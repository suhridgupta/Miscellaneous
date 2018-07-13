//Program to find the lowest common ancestor of two nodes in a binary tree
//Uses no extra space. Alternative is to store paths in two vectors and compare

#include <iostream>

using namespace std;

#define INF 9999

struct tree{
    int data;
    struct tree *left,*right;
};

tree *createNode(int data){
    tree *node = (tree*)malloc(sizeof(tree));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int lowestAncestor(tree *root,int a, int b){
    //if node doesnt exit, return NULL (-INF)
    if(root == nullptr)
        return -INF;
    //if one of the keys are satisfied by the value, return the root value
    if(root->data == a || root->data == b)
        return root->data;
    //recursively find the ancestor value for left tree and right tree
    int left = lowestAncestor(root->left,a,b);
    int right = lowestAncestor(root->right,a,b);
    //if both values arent NULL, then this root is the lowest ancestor
    if(left != -INF && right != -INF)
        return root->data;
    //otherwise, return the one non-NULL value
    if(left != -INF)
        return left;
    if(right != -INF)
        return right;
    //if both are none, return NULL
    return -INF;
}

int main(){
    tree *node = createNode(5);
    node->left = createNode(3);
    node->right = createNode(7);
    node->left->left = createNode(2);
    node->left->right = createNode(4);
    node->right->left = createNode(6);
    
    cout<<lowestAncestor(node,7,6)<<endl;
    return 0;
}