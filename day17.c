

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

#include <stdio.h>
int maxSubArray(int nums[],int size){
    int maxSum=nums[0];
    int curr=nums[0];
    for(int i=1;i<size;i++){
        if(curr<0) curr=nums[i];
        else curr+=nums[i];
        if(curr>maxSum) maxSum=curr;
    }
    return maxSum;
}

int main(){
    int nums[]={-2,1,-3,4,-1,2,1,-5,4};
    int size=sizeof(nums)/sizeof(nums[0]);
    printf("%d",maxSubArray(nums,size));
    return 0;
}
