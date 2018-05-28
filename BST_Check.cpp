#include <iostream>

using namespace std;

struct tree{
    int data;
    struct tree *left,*right;
};

tree *newNode(int data){
    tree *node = (tree*)malloc(sizeof(tree));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool isBST(tree *root){
    if(root == nullptr)
        return true;
    static tree *prev = nullptr;
    if(!isBST(root->left))
        return false;
    if(prev && prev->data>=root->data){
        prev = nullptr;
        return false;
    }
    prev = root;
    return isBST(root->right);
}

int main(){
    tree *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->right = newNode(4);
    root->right->right = newNode(6); //Error Case
    cout<<isBST(root)<<endl;
    return 0;
}