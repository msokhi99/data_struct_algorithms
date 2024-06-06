#include<iostream>
#include<cmath>

// To use binary search the array must be sorted. Let us assume the 
// array has already been sorted.

int binarySearch(int [],int,int);

int binarySearch(int A[], int elements, int key){
    int low=0;
    int high=elements-1;
    while(low<high){
        int mid=floor((high+low)/2);
        if(A[mid]==key){
            return mid;
        }
        else if(A[mid]>key){
            high=mid-1;
        }
        else if(A[mid]<key){
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int key;
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    std::cout<<"Enter a key:\n";
    std::cin>>key;
    int result=binarySearch(A,10,key);
    if(result==-1){
        std::cout<<"Search has been unsuccessfull.\n";
    }
    else{
        std::cout<<"The key has been found at index: "<<result<<"\n";
    }
    return 0;
}

/*
Time Complexity:

Best Case -> O(1),
Worst Case -> O(log(n)).
*/