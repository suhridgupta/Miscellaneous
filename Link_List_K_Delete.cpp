//Program to delete Kth node in a linked list
#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

node *createNode(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

node *insertNode(node *root,int data){
    if(root == nullptr){
        root = createNode(data);
        return root;
    }
    node *temp = root;
    while(temp->next!=nullptr)
        temp = temp->next;
    temp->next = createNode(data);
    return root;
}

node *deleteKNode(node *root,int K){
    int count = 1;
    node *temp = root;
    while(temp != nullptr){
        if((count+1)%K == 0){
            temp->next = temp->next->next;
            count++;
        }
        count++;
        temp = temp->next;
    }
    return root;
}

void display(node *root){
    node *temp = root;
    while(temp!=nullptr){
        cout<<temp->data<<'\t';
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    node *root = nullptr;
    for(int i=1;i<=10;i++){
        root = insertNode(root,i);
    }
    deleteKNode(root,3);
    display(root);
    return 0;
}