#include<iostream> 

int main(){
    int A[5]={3,4,5,6,10};
    int B[5]={2,4,5,7,12};
    int C[10]={0};

    int i=0,j=0,k=0; 

    while(i<5 && j<5){
        if(A[i]>B[j]){
            j++;
        }
        else if(A[i]<B[j]){
            C[k]=A[i];
            k++,i++;
        }
        else if(A[i]==B[j]){
            i++,j++;
        }
    }
    for(int i=0; i<10; i++){
        std::cout<<C[i]<<" ";
    }
    return 0;
}

/*
Time Complexity -> O(m+n) -> O(n).
*/