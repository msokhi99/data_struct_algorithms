#include<iostream>

int linearSearch(int [],int,int);

int linearSearch(int A[], int elements,int key){
    for(int i=0; i<elements; i++){
        if(A[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int key;
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    std::cout<<"Enter a key:\n";
    std::cin>>key;
    int result=linearSearch(A,10,key);
    if(result==-1){
        std::cout<<"Search was unsuccesfull.\n";
    }
    else{
        std::cout<<"Search was succesfull. The key has been found at index: "<<result<<"\n";
    }
    return 0;
}

/*
Time Complexity:

Best case scenario -> O(1),
worst case scenario -> O(n).
*/