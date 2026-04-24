


/*

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
*/


#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
int hasCycle(struct Node* head){
    struct Node* slow=head;
    struct Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return 1;
    }
    return 0;
}
int main(){
    struct Node* a=(struct Node*)malloc(sizeof(struct Node));
    struct Node* b=(struct Node*)malloc(sizeof(struct Node));
    struct Node* c=(struct Node*)malloc(sizeof(struct Node));
    struct Node* d=(struct Node*)malloc(sizeof(struct Node));
    a->val=3; b->val=2; c->val=0; d->val=-4;
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=b;
    if(hasCycle(a)) printf("true");
    else printf("false");
    return 0;
}


    return 0;
}
