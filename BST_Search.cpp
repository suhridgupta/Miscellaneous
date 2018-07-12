//Program to check if the BST contains a certain key
#include <iostream>

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

bool searchBST(tree *root,int key){
    if(root == nullptr)
        return false;
    if(root->data == key)
        return true;
    //recursively check condition on its children if either of them have the key
    if(searchBST(root->left,key) || searchBST(root->right,key))
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

    cout<<searchBST(node,6)<<endl;
    return 0;
}