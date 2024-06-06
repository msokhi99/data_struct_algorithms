#include <iostream>

int * createArrEnterArrElements(int size, int elements){
    int *A;
    A=new int[size];
    for(int i=0; i<elements; i++){
        std::cin>>A[i];
    }
    return A;
}

int * reverseArrMethodOne(int *arr, int size, int elements){
    int *B;
    B=new int[size];
    for(int i=0, j=elements-1; i<elements; i++, j--){
        B[i]=arr[j];
    }
    for(int i=0; i<elements; i++){
        arr[i]=B[i];
    }
    return arr;
}

int * reverseArrMethodTwo(int *arr, int elements){
    for(int i=0,j=elements-1; i<j; i++,j--){
        int tempVar=arr[i];
        arr[i]=arr[j];
        arr[j]=tempVar;
    }
    return arr;
}

void displayArr(int *arr, int elements){
    std::cout<<"Array:\n";
    for(int i=0; i<elements; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

void delMem(int *arr){
    delete[] arr;
    arr=nullptr;
    std::cout<<"Memory succesfully deallocated.\n";
}

void leftShift(int *arr, int elements){
    for(int i=0; i<elements; i++){
        arr[i]=arr[i+1];
    }
}

void rightShift(int *arr, int elements){
    for(int i=elements-1; i>0; i--){
        arr[i]=arr[i-1];
    }
}

void rotateLeft(int *arr, int elements){
    int firstElement=arr[0];
    for(int i=0; i<elements; i++){
        arr[i]=arr[i+1];
    }
    arr[elements-1]=firstElement;
}

void rotateRight(int *arr, int elements){
    int firstElement=arr[elements-1];
    for(int i=elements-1; i>0; i--){
        arr[i]=arr[i-1];
    }
    arr[0]=firstElement;
}

int main()
{
    int arrSize, numOfElements;
    std::cout<<"Enter the size:\n";
    std::cin>>arrSize;
    std::cout<<"Enter the number of elements:\n";
    std::cin>>numOfElements;
    std::cout<<"Enter all the elements:\n";
    int *arrA=createArrEnterArrElements(arrSize,numOfElements);
    displayArr(arrA,numOfElements);
    // Method 1 of reversing an array:
    /*int *reversedArrA=reverseArrMethodOne(arrA,arrSize,numOfElements);
    displayArr(arrA,numOfElements);
    // Method 2 of reversing an array:
    int *reversedArrAMethodTwo=reverseArrMethodTwo(arrA,numOfElements);*/
    rotateRight(arrA,numOfElements);    
    displayArr(arrA,numOfElements);
    delMem(arrA);
    return 0;
}