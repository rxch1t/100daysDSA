/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
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

struct Node* lca(struct Node* root,int p,int q){
    while(root){
        if(p<root->val && q<root->val){
        root=root->left;
        }else if(p>root->val && q>root->val){
        root=root->right;
        }else{
        return root;
        }
    }
    return NULL;
}

int main(){
    struct Node* root=newNode(6);
    root->left=newNode(2);
    root->right=newNode(8);
    root->left->left=newNode(0);
    root->left->right=newNode(4);

    struct Node* ans=lca(root,2,8);
    printf("%d",ans->val);
    return 0;
}