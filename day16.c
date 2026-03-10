
/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/


#include <stdio.h>
void reverse(int nums[],int start,int end){
    while(start<end){
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
}

void rotate(int nums[],int size,int k){
    k=k%size;
    reverse(nums,0,size-1);
    reverse(nums,0,k-1);
    reverse(nums,k,size-1);
}

int main(){
    int nums[]={1,2,3,4,5,6,7};
    int size=sizeof(nums)/sizeof(nums[0]);
    int k=3;
    rotate(nums,size,k);
    for(int i=0;i<size;i++) printf("%d ",nums[i]);
    return 0;
}
