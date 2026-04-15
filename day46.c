
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
void levelOrder(struct Node* root){
    if(!root) return;
    struct Node* queue[100];
    int head=0,tail=0;
    queue[tail++]=root;
    while(head<tail){
        struct Node* curr=queue[head++];
        printf("%d ",curr->val);
        if(curr->left) queue[tail++]=curr->left;
        if(curr->right) queue[tail++]=curr->right;
    }
}
int main(){
    struct Node* root=newNode(3);
    root->left=newNode(9);
    root->right=newNode(20);
    root->right->left=newNode(15);
    root->right->right=newNode(7);
    levelOrder(root);
    return 0;
}

