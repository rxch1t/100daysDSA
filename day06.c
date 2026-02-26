#include <stdio.h>
void moveZero(int nums[],int size){
    int k=0;
    for(int i=0;i<size;i++){
        if (nums[i]!=0){
        nums[k]=nums[i];
        k++;
        }
    }
    while(k<size){
    nums[k]=0;
    k++;
    }
}

int main(){
    int nums[]={0,1,0,3,12};
    int size=sizeof(nums)/sizeof(nums[0]);
    moveZero(nums,size);
    for(int i=0;i<size;i++){
       printf("%d ",nums[i]); 
    }
    return 0;
}
