
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/


#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node* next;
};

struct Node* create(int arr[],int n){
    struct Node* head=NULL;
    struct Node* temp=NULL;
    for(int i=0;i<n;i++){
        struct Node* node=(struct Node*)malloc(sizeof(struct Node));
        node->val=arr[i];
        node->next=NULL;

        if(head==NULL){
            head=node;
            temp=node;
        }else{
            temp->next=node;
            temp=node;
        }
    }
    return head;
}

struct Node* addTwoNumbers(struct Node* l1,struct Node* l2){
    struct Node* head=NULL;
    struct Node* temp=NULL;
    int carry=0;
    while(l1 || l2 || carry){
        int sum=carry;
        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }
        struct Node* node=(struct Node*)malloc(sizeof(struct Node));
        node->val=sum%10;
        node->next=NULL;
        if(head==NULL){
            head=node;
            temp=node;
        }else{
            temp->next=node;
            temp=node;
        }
        carry=sum/10;
    }
    return head;
}

int main(){
    int a[]={2,4,3};
    int b[]={5,6,4};
    struct Node* l1=create(a,3);
    struct Node* l2=create(b,3);
    struct Node* res=addTwoNumbers(l1,l2);
    while(res){
        printf("%d ",res->val);
        res=res->next;
    }
    return 0;
}
