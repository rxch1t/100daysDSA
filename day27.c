/*Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.

Examples:

Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 

The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 

A loop is present in the list, and it is removed.



Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.
*/


#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
int removeCycle(struct Node* head){
    struct Node* slow=head;
    struct Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            struct Node* temp=fast;
            while(temp->next!=fast){
                temp=temp->next;
            }
            temp->next=NULL;
            return 1;
        }
    }
    return 0;
}
int main(){
    struct Node* a=(struct Node*)malloc(sizeof(struct Node));
    struct Node* b=(struct Node*)malloc(sizeof(struct Node));
    struct Node* c=(struct Node*)malloc(sizeof(struct Node));
    struct Node* d=(struct Node*)malloc(sizeof(struct Node));
    a->val=1; b->val=2; c->val=3; d->val=4;
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=b;
    if(removeCycle(a)) printf("true");
    else printf("false");
    return 0;
}
