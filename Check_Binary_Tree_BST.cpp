//Program to check if a binary tree is a BST or not
#include <iostream>

#define INF 9999

using namespace std;

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

bool isBST(tree *root,int lower,int upper){
    if(root == nullptr)
        return true;
    //left bounds [lb,data], right bounds [data,rb]
    if(isBST(root->left,lower,root->data) && isBST(root->right,root->data,upper) && (root->data<upper && root->data>lower))
        return true;
    return false;
}

int main(){
    tree *node = createNode(5);
    node->left = createNode(3);
    node->right = createNode(7);
    node->left->left = createNode(2);
    node->left->right = createNode(4);
    node->right->left = createNode(6);
    //Each node must be of value between lower and upper bound
    cout<<isBST(node,-INF,INF)<<endl;
    return 0;
}