

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]
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
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
int main(){
    struct Node* root=newNode(1);
    root->right=newNode(2);
    root->right->left=newNode(3);
    inorder(root);
    return 0;
}

