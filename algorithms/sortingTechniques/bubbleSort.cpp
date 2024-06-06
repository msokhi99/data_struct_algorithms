#include <iostream> 

void adaptiveBubbleSort(int [], int);
void bubbleSort(int[],int);
void swap(int &, int &);

// Bubble Sort Algorithm. To make this algorithm adaptive we can set a flag
// that checks if the array passed is already sorted. 

void adaptiveBubbleSort(int A[], int numOfElements){
    int flag;
    for(int i=0; i<numOfElements; i++){
        flag=0;
        for(int j=0; j<numOfElements-i-1; j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            std::cout<<"The array is already sorted. \n";
            break;
        }
    }
}

void bubbleSort(int A[], int numOfElements){
    for(int i=0; i<numOfElements; i++){
        for(int j=0; j<numOfElements-i-1; j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
            }
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

    int A[]={5,3,2,8,7,1};
    bubbleSort(A,6);
    int B[]={1,2,3,4,5,6,7,8};
    adaptiveBubbleSort(B,8);

    // Displaying the array: 

    for(int i=0; i<6; i++){
        std::cout<<A[i]<<" ";
    }
    
    return 0;
}

/*
Time complexity: 

Best case scenario -> O(n).
Worst case scenario -> O(n^2).
*/
