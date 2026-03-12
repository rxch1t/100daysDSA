

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/




#include <stdio.h>
#include <stdlib.h>
int* productExceptSelf(int nums[],int size){
    int* res=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++) 
    res[i]=1;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
        if(i!=j) 
        res[i]*=nums[j];
        }
    }
    return res;
}
int main(){
    int nums[]={1,2,3,4};
    int size=sizeof(nums)/sizeof(nums[0]);
    int* ans=productExceptSelf(nums,size);
    for(int i=0;i<size;i++) 
    printf("%d ",ans[i]);
    free(ans);
    return 0;
}
