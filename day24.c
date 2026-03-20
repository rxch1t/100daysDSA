

/*

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
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
        if(idx==1){
            connect=temp;
        }
        temp=temp->next;
        idx++;
    }
    temp->next=connect;
    if(hasCycle(head)) printf("true");
    else printf("false");
    return 0;
}
