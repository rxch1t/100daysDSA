

/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.


Example 1:


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
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
struct Node* insertIntoBST(struct Node* root,int val){
    if(root==NULL) return newNode(val);
    if(val < root->val) root->left=insertIntoBST(root->left,val);
    else root->right=insertIntoBST(root->right,val);
    return root;
}
void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
int main(){
    struct Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(7);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root=insertIntoBST(root,5);
    inorder(root);
    return 0;
}
