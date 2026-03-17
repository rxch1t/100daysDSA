

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
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

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev=NULL;
    struct ListNode* curr=head;
    while(curr){
        struct ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    struct ListNode* head=createList(arr,size);
    head=reverseList(head);
    struct ListNode* temp=head;
    while(temp){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    return 0;
}
