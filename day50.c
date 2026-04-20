


/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
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
struct Node* searchBST(struct Node* root,int val){
    if(root==NULL||root->val==val) return root;
    if(val<root->val) return searchBST(root->left,val);
    return searchBST(root->right,val);
}
int main(){
    struct Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(7);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    struct Node* result=searchBST(root,2);
    if(result) printf("Found node with val: %d",result->val);
    else printf("Not Found");
    return 0;
}
