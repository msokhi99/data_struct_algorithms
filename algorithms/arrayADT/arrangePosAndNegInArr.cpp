#include<iostream>

/*
We have two index pointers. 'i' starts from 0 and if A[i]>0 (if it is a positive number),
we increment i. Similarly, for 'j', if A[j]<0 (if it is a negative number) we decrement j.
The loop carries on until i>j which would mean that we have scanned all of the elements in
the given array.
*/

void swap(int &, int &);
void rearrangeArr(int A[], int elements){
    int i=0, j=elements-1;
    while(i<j){
        while(A[i]>0){
            i++;
        }
        while(A[j]<0){
            j--;
        }
        if(i<j){
            swap(A[i],A[j]);
        }
    }
}

void swap(int &x, int &y){
    int tempValue;
    tempValue=x;
    x=y;
    y=tempValue;
}

int main(){
    int arr[10]={-1,2,4,-7,-15,10,19,-4,-10,5};
    rearrangeArr(arr,10);
    for(int i=0; i<10; i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}