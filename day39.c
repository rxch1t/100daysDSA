

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]
*/


#include <stdio.h>
void topK(int nums[],int n,int k){
    int freq[1000]={0};
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }

    for(int i=0;i<k;i++){
        int max=0,idx=0;

        for(int j=0;j<1000;j++){
            if(freq[j]>max){
            max=freq[j];
            idx=j;
            }
        }
        printf("%d ",idx);
        freq[idx]=0;
    }
}

int main(){
    int nums[]={1,1,1,2,2,3};
    int n=6,k=2;
    topK(nums,n,k);
    return 0;
}
