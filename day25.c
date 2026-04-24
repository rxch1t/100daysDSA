

/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
*/


#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
struct Node* detectCycle(struct Node* head){
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
            return slow;
        }
    }
    return NULL;
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
    struct Node* res=detectCycle(a);
    if(res) printf("%d",res->val);
    else printf("no cycle");
    return 0;
}
