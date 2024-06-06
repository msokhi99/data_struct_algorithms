#include<iostream> 

float sumOfNatNums(int);
float getSumArr(int[]);

float sumOfNatNums(int n){
    float result=(float(n*(n+1)))/2;
    return result;
}

float getSumArr(int A[]){
    int sum=0;
    for(int i=0; i<11; i++){
        sum=sum+A[i];
    }
    return sum;
}

/*
For this method, A[0] must be 1.
*/

int main(){
    int A[]={1,2,3,4,5,6,8,9,10,11,12};
    // Suppose the array does not start with 1:
    int B[]={6,7,8,9,10,11,13,14,15,16,17};
    int low=6;
    int high=17;
    int numElements=11;
    int diff=low-0;
    for(int i=0; i<numElements; i++){
        if(B[i]-i != diff){
            std::cout<<i+diff<<" ";
            diff++;
        }
    }
    float totalSum=sumOfNatNums(12);
    float arrSum=getSumArr(A);
    float missingElement=totalSum-arrSum;
    std::cout<<"Missing element is: "<<missingElement<<"\n";

    // Multiple elements missing:

    int C[]={10,14,17,18,19,23,45,46};
    int newLow=10;
    int newHigh=46;
    int newDiff=10;
    for(int i=0; i<8; i++){
        if(C[i]-i!=newDiff){
            while(newDiff < C[i]-i){
                std::cout<<i+newDiff<<" ";
                newDiff++;
            }
        }
    }

    /*
    Time Complexity -> O(n^2);
    */

    // A faster method (Using a basic hash table):
    std::cout<<"\n";
    int D[10]={3,7,4,9,12,6,1,11,2,10};
    int E[12]={0};

    for(int i=0; i<10; i++){
        E[D[i]]=1;
    }
    for(int i=0; i<12; i++){
        std::cout<<E[i]<<" ";
    }
    std::cout<<"\n";
    for(int i=1; i<12; i++){
        if(E[i]==0){
            std::cout<<i<<" ";
        }
    }

    /*
    Time Complexity -> O(n).
    */
    return 0;
}