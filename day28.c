

/*

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
*/




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isPalindrome(struct Node* head){
    int arr[1000];
    int k=0;
    while(head){
        arr[k++]=head->val;
        head=head->next;
    }

    for(int i=0;i<k/2;i++){
        if(arr[i]!=arr[k-1-i]) return false;
    }
    return true;
}

int main(){
    int arr[]={1,2,2,1};
    int n=4;
    struct Node* head=create(arr,n);
    if(isPalindrome(head)) printf("true");
    else printf("false");
    return 0;
}
