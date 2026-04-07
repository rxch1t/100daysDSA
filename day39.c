

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
    for(int i=0;i<1000;i++){
        for(int j=i+1;j<1000;j++){
            if(freq[i]<freq[j]){
                int t=freq[i];
                freq[i]=freq[j];
                freq[j]=t;
                int x=i,y=j;
                int tmp=x;
                x=y;
                y=tmp;
            }
        }
    }
    int count=0;
    for(int i=0;i<1000 && count<k;i++){
        if(freq[i]>0){
            printf("%d ",i);
            count++;
        }
    }
}
int main(){
    int nums[]={1,1,1,2,2,3};
    int n=6,k=2;
    topK(nums,n,k);
    return 0;
}
