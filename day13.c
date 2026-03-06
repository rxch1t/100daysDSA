

/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/


#include <stdio.h>
void spiral(int matrix[][4],int rows,int cols){
    int top=0,bottom=rows-1,left=0,right=cols-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++) 
        printf("%d ",matrix[top][i]);
        top++;

        for(int i=top;i<=bottom;i++) 
        printf("%d ",matrix[i][right]);
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--) 
            printf("%d ",matrix[bottom][i]);
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--) 
            printf("%d ",matrix[i][left]);
            left++;
        }
    }
}

int main(){
    int matrix[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    spiral(matrix,3,4);
    return 0;
}
