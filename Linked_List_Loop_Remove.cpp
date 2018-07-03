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

void detectAndRemoveLoop(node *head){
    node *slow = head,*fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    //loop condition, set slow to head and incrememnt slow and fast equally until they meet
    if(slow == fast){ 
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        cout<<"Loop Beginning At "<<fast->data<<endl;
        fast->next = nullptr;
    }
    else
        cout<<"No Loop Detected\n";
}

int main(){
    node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head->next; //1->2->3->4->2 (loop)
    detectAndRemoveLoop(head);
}