


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
#include <stdbool.h>

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

bool hasCycle(struct ListNode* head){
    struct ListNode* visited[1000];
    int k=0;
    while(head){
        for(int i=0;i<k;i++){
        if(visited[i]==head) 
        return true;
        }
        visited[k++]=head;
        head=head->next;
    }
    return false;
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
    if(hasCycle(head)) printf("true");
    else printf("false");

    return 0;
}
