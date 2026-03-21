

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
struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* createList(int arr[],int size){
    struct ListNode* head=NULL;
    struct ListNode* temp=NULL;
    for(int i=0;i<size;i++){
        struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=arr[i];
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    return head;
}
struct ListNode* detectCycle(struct ListNode* head){
    struct ListNode* visited[1000];
    int k=0;

    while(head){
        for(int i=0;i<k;i++){
        if(visited[i]==head) return head;
        }
        visited[k++]=head;
        head=head->next;
    }
    return NULL;
}

int main(){
    int arr[]={3,2,0,-4};
    int size=4;
    struct ListNode* head=createList(arr,size);
    struct ListNode* temp=head;
    struct ListNode* connect=NULL;
    int idx=0;

    while(temp->next){
        if(idx==1) connect=temp;
        temp=temp->next;
        idx++;
    }
    temp->next=connect;
    struct ListNode* ans=detectCycle(head);
    if(ans){
    printf("%d",ans->val);
    }else{
     printf("no cycle");
    }
    return 0;
}
