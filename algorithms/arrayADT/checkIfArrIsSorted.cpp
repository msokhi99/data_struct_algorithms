#include<iostream> 

bool isSorted(int A[],int elements){
    for(int i=0; i<elements-1; i++){
        if(A[i]>A[i+1]){
            return false;
        }
    }
    return true;
}

// We can further use a sorting algorithm to sort this array based on our needs.

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    std::cout<<isSorted(arr,10)<<"\n";
    return 0;
}