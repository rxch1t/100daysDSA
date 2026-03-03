/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
*/


#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){
    return (*(int*)a-*(int*)b);
}
int* intersect(int nums1[],int size1,int nums2[],int size2,int* returnSize){
    qsort(nums1,size1,sizeof(int),cmp);
    qsort(nums2,size2,sizeof(int),cmp);

    int i=0,j=0,k=0;
    int* res=(int*)malloc(sizeof(int)*(size1<size2?size1:size2));

    while(i<size1 && j<size2){
        if(nums1[i]<nums2[j]) i++;
        else if(nums1[i]>nums2[j]) j++;
        else{
        res[k]=nums1[i];
        k++;
        i++;
        j++;
        }
    }
    *returnSize=k;
    return res;
}

int main(){
    int nums1[]={1,2,2,1};
    int nums2[]={2,2};
    int size1=sizeof(nums1)/sizeof(nums1[0]);
    int size2=sizeof(nums2)/sizeof(nums2[0]);
    int returnSize;
    int* ans=intersect(nums1,size1,nums2,size2,&returnSize);
    for (int i=0;i<returnSize;i++) printf("%d ",ans[i]);
    free(ans);
    return 0;
}
