/*Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.

Examples:

Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 

The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 

A loop is present in the list, and it is removed.



Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.
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

bool removeCycle(struct Node* head){
    struct Node* visited[1000];
    int k=0;

    struct Node* prev=NULL;

    while(head){
        for(int i=0;i<k;i++){
            if(visited[i]==head){
                if(prev) prev->next=NULL;
                return true;
            }
        }
        visited[k++]=head;
        prev=head;
        head=head->next;
    }
    return false;
}

int main(){
    printf("Problem: Level Order\\n");
    return 0;
}
