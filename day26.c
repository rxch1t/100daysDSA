

/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
*/




#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node* head=NULL;

int get(int index){
    struct Node* temp=head;
    for(int i=0;temp;i++){
        if(i==index) return temp->val;
        temp=temp->next;
    }
    return -1;
}

void addAtHead(int val){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->val=val;
    node->next=head;
    head=node;
}

void addAtTail(int val){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->val=val;
    node->next=NULL;
    if(head==NULL){
        head=node;
        return;
    }
    struct Node* temp=head;
    while(temp->next) temp=temp->next;
    temp->next=node;
}
void addAtIndex(int index,int val){
    if(index==0){
        addAtHead(val);
        return;
    }
    struct Node* temp=head;
    for(int i=0;i<index-1 && temp;i++) temp=temp->next;
    if(temp==NULL) return;
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->val=val;
    node->next=temp->next;
    temp->next=node;
}

void deleteAtIndex(int index){
    if(head==NULL) return;
    if(index==0){
        head=head->next;
        return;
    }
    struct Node* temp=head;
    for(int i=0;i<index-1 && temp->next;i++){
        temp=temp->next;
    }
    if(temp->next){
        temp->next=temp->next->next;
    }
}

int main(){
    addAtHead(1);
    addAtTail(3);
    addAtIndex(1,2);
    printf("%d\n",get(1));
    deleteAtIndex(1);
    printf("%d\n",get(1));
    return 0;
}
