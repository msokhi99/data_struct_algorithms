#include<iostream> 

int main(){

    int A[5]={1,2,3,4,5};
    int B[5]={1,2,6,7,8};
    int C[10]={0};

    int i=0,j=0,k=0;

    while(i<5 && j<5){
        if(A[i]>B[j]){
            C[k]=B[j];
            k++,j++;
        }
        else if(A[i]<B[j]){
            C[k]=A[i];
            k++,i++;
        }
    }

    for(; i<5; i++){
        C[k]=A[i];
        k++;
    }
    for(; j<5; j++){
        C[k]=B[j];
        k++;
    }

    for(int i=0; i<10; i++){
        std::cout<<C[i]<<" ";
    }
    return 0;
}

/*
Time Complexity -> O(m+n) -> O(n).
*/