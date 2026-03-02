/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/


#include <stdio.h>

void revString(char s[],int size){
    int i=0,j=size-1;
    while(i<j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
}

int main(){
    char s[]={'h','e','l','l','o'};
    int size=sizeof(s)/sizeof(s[0]);
    revString(s,size);
    for(int i=0;i<size;i++)
    printf("%c ",s[i]);
    return 0;
}
