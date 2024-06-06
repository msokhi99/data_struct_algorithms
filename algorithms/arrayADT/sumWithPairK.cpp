#include<iostream> 

/*void findSum(int A[], int elements, int sum){
    int C[16]={0};
    for(int i=0; i<elements; i++){
        if(C[sum-A[i]]!=0 && sum-A[i]>0){
            std::cout<<A[i]<<" "<<sum-A[i]<<" ";
        }
        else{
            C[A[i]]++;
        }
    }
}*/

void findSumSorted(int B[], int elements, int sum){
    int i=0;
    int j=elements-1;
    while(i!=j){
        if(B[i]+B[j]>sum){
            j--;
        }
        else if(B[i]+B[j]<sum){
            i++;
        }
        else if(B[i]+B[j]==sum){
            std::cout<<B[i]<<" "<<B[j]<<" "<<"\n";
            i++,j--;
        }
    }
}

int main(){
    // Unsorted Array (No duplicates): 
    //int A[]={6,3,8,10,16,7,5,2,9,14};
    int sum=10;
    //findSum(A,10,sum);

    //Sorted Array (No Duplicates):
    int B[]={1,3,4,5,6,8,9,10,12,14};
    findSumSorted(B,10,sum);
    return 0;
}