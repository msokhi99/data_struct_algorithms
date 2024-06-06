#include<iostream>

/*
For set intersection we also make use of the merge algorithm.
If two elements are same then we copy it, otherwise we increment 
the index pointers of both the arrays by +1.
*/

int main(){
    int A[5]={3,4,5,6,10};
    int B[5]={2,3,4,5,12};
    int C[10]={0};

    int i=0,j=0,k=0;

    while(i<5 && j<5){
        if(A[i]>B[j]){
            j++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else if(A[i]==B[j]){
            C[k]=A[i];
            k++,i++,j++;
        }
    }

    for(int i=0; i<10; i++){
        std::cout<<C[i]<<" ";
    }
    return 0;
}

/*
Time Complexity -> Theta(m+n) -> Theta(n).
*/