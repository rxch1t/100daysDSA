

/*
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
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
int sumLeftLeaves(struct Node* root,int isLeft){
    if(!root){
    return 0;
    } 
    if(!root->left&&!root->right){
    return isLeft?root->val:0;
    }
    return sumLeftLeaves(root->left,1)+sumLeftLeaves(root->right,0);
}
int main(){
    struct Node* root=newNode(3);
    root->left=newNode(9);
    root->right=newNode(20);
    root->right->left=newNode(15);
    root->right->right=newNode(7);
    printf("%d",sumLeftLeaves(root,0));
    return 0;
}
