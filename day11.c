/*
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.



 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
*/



#include <stdio.h>
void transpose(int matrix[][3],int rows,int cols,int result[][3]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
        result[j][i]=matrix[i][j];
        }
    }
}

int main(){
    int matrix[2][3]={{1,2,3},{4,5,6}};
    int result[3][2];
    transpose(matrix,2,3,result);
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++) 
        printf("%d ",result[i][j]);
        printf("\n");
    }
    return 0;
}
