#include<iostream>

void insert(int A[],int,int);

void insert(int A[], int size, int elements){
    int tempNum, tempIndex;
    if(elements<size){
        std::cout<<"Enter the number you want to insert into the array:\n";
        std::cin>>tempNum;
        std::cout<<"Enter the index where you want to add this number:\n";
        std::cin>>tempIndex;
        if(tempIndex<elements){
            for(int i=elements; i>tempIndex; i--){
                A[i]=A[i-1];
            }
            A[tempIndex]=tempNum;
            elements++;
        }
    }
    else{
        std::cout<<"The array is full.\n";
    }
}

int main(){
    int A[10]={1,2,3,4,5};
    std::cout<<"This is what the array looks like at the moment:\n";
    for(int i=0; i<5; i++){
        std::cout<<A[i]<<" ";
    }
    std::cout<<"\n";
    insert(A,10,5);
    std::cout<<"This is what the array looks like after inserting a number:\n";
    for(int i=0; i<6; i++){
        std::cout<<A[i]<<" ";
    }
    return 0;
}

/*
Time Complexity:

Best Case -> O(1)
Worst Case -> O(n)
*/