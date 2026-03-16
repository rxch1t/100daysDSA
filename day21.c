

/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
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
struct ListNode* middleNode(struct ListNode* head){
    int count=0;
    struct ListNode* temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    int mid=count/2;
    temp=head;
    for(int i=0;i<mid;i++){
        temp=temp->next;
    }
    return temp;
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    struct ListNode* head=createList(arr,size);
    struct ListNode* mid=middleNode(head);
    while(mid){
        printf("%d ",mid->val);
        mid=mid->next;
    }
    return 0;
}
