

/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/


#include <stdio.h>

void setZeroes(int matrix[][4],int rows,int cols){
    int frow=0,fcol=0;

    for(int i=0;i<rows;i++){
        if(matrix[i][0]==0) fcol=1;
    }

    for(int j=0;j<cols;j++){
        if(matrix[0][j]==0) frow=1;
    }

    for(int i=1;i<rows;i++){
        for(int j=1;j<cols;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }

    for(int i=1;i<rows;i++){
        for(int j=1;j<cols;j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }
    if(fcol){
        for(int i=0;i<rows;i++) matrix[i][0]=0;
    }

    if(frow){
        for(int j=0;j<cols;j++) matrix[0][j]=0;
    }
}
int main(){
    int matrix[3][4]={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix,3,4);
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++) 
        printf("%d ",matrix[i][j]);
        printf("\n");
    }
    return 0;
}
