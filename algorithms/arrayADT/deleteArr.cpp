#include<iostream>

void deleteElement(int [],int);

void deleteElement(int A[], int elements){
    int tempIndex;
    std::cout<<"What index do you want to delete: \n";
    std::cin>>tempIndex;
    if(tempIndex<elements){
        int deletedIndexNumber=A[tempIndex];
        for(int i=tempIndex; i<elements-1; i++){
            A[i]=A[i+1];
        }
        elements--;
    }
}

int main(){
    int A[10]={1,2,3,4,5};
    std::cout<<"This is what the array looks like at the moment:\n";
    for(int i=0; i<5; i++){
        std::cout<<A[i]<<" ";
    }
    std::cout<<"\n";
    deleteElement(A,5);
    std::cout<<"This is what the array looks like after deletion:\n";
    for(int i=0; i<4; i++){
        std::cout<<A[i]<<" ";
    }
    return 0;
}

/*
Time Complexity:

Best case scenario -> O(1),
Worst case scenario -> O(n).
*/