/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
*/



#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->val=val;
    node->left=node->right=NULL;
    return node;
}
struct Node* q[100];
int front=0,rear=0;
void enqueue(struct Node* node){
    q[rear++]=node;
}
struct Node* dequeue(){
    return q[front++];
}
int isEmpty(){
    return front==rear;
}
void lvlOrder(struct Node*root){
    if(root==NULL){
    return;
    }
    enqueue(root);
    while(!isEmpty()){
        int size=rear-front;
        printf("[ ");
        for(int i=0;i<size;i++){
            struct Node* curr=dequeue();
            printf("%d ",curr->val);
            if(curr->left!=NULL){
            enqueue(curr->left);
            }
            if(curr->right!=NULL){
            enqueue(curr->right);
            }
        }
        printf("]\n");
    }
}

int main(){
    struct Node* root=newNode(3);
    root->left=newNode(9);
    root->right=newNode(20);
    root->right->left=newNode(15);
    root->right->right=newNode(7);
    lvlOrder(root);
    return 0;
}