

/*
ou are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
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
long long getNumber(struct Node* head){
    long long num=0;
    while(head){
        num=num*10+head->val;
        head=head->next;
    }
    return num;
}
struct Node* build(long long num){
    if(num==0){
        struct Node* node=(struct Node*)malloc(sizeof(struct Node));
        node->val=0;
        node->next=NULL;
        return node;
    }
    int arr[1000],k=0;
    while(num){
        arr[k++]=num%10;
        num/=10;
    }
    struct Node* head=NULL;
    for(int i=k-1;i>=0;i--){
        struct Node* node=(struct Node*)malloc(sizeof(struct Node));
        node->val=arr[i];
        node->next=head;
        head=node;
    }
    return head;
}

struct Node* addTwoNumbers(struct Node* l1,struct Node* l2){
    long long n1=getNumber(l1);
    long long n2=getNumber(l2);
    long long sum=n1+n2;
    return build(sum);
}

int main(){
    int a[]={7,2,4,3};
    int b[]={5,6,4};
    struct Node* l1=create(a,4);
    struct Node* l2=create(b,3);
    struct Node* res=addTwoNumbers(l1,l2);
    while(res){
        printf("%d ",res->val);
        res=res->next;
    }
    return 0;
}
