

/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/


#include <stdio.h>
int arr[1000],size=0;
void sort(){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
            }
        }
    }
}

void addNum(int num){
    arr[size++]=num;
}

double findMedian(){
    sort();
    if(size%2==1){
        return arr[size/2];
    }else{
        return (arr[size/2]+arr[size/2-1])/2.0;
    }
}

int main(){
    addNum(1);
    addNum(2);
    printf("%.1f\n",findMedian());
    addNum(3);
    printf("%.1f\n",findMedian());
    return 0;
}
