

/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
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
int maxDepth(struct Node* root){
    if(root==NULL) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return (lh>rh?lh:rh)+1;
}
int main(){
    struct Node* root=newNode(3);
    root->left=newNode(9);
    root->right=newNode(20);
    root->right->left=newNode(15);
    root->right->right=newNode(7);
    printf("%d",maxDepth(root));
    return 0;
}

