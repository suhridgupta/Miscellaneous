#include <iostream>
#include <map>
#include <algorithm>
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

void checkIntersection(node *head1,node *head2){
    map<int*,int>values;
    while(head1 != nullptr){
        values[(int*)&(head1->data)] = head1->data;
        head1 = head1->next;
    }
    while(head2 != nullptr){
        if(values.find((int*)&(head2->data)) != values.end()){
            cout<<"Intersection At "<<head2->data<<endl;
            return;
        }
        head2 = head2->next;
    }
    cout<<"No Intersection"<<endl;
}

int main(){
    node *head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);
    node *head2 = createNode(6);
    head2->next = head1->next->next; //Intersection
    checkIntersection(head1,head2);
    return 0;
}