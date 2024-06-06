#include<iostream>

/*
To merge two arrays, both the arrays should be already sorted. The merged array should also 
be sorted. Alternatively, we can use bubble sort on all three arrays.
*/

int main(){
    int arrOne[5]={1,2,3,4,5};
    int arrTwo[3]={6,7,8};
    int mergedArr[8]={0};
    int i=0, j=0, k=0;

    while(i<5 && j<3){
        if(arrOne[i]<arrTwo[j]){
            mergedArr[k]=arrOne[i];
            i++, k++;
        }
        else if(arrOne[i]>arrTwo[j]){
            mergedArr[k]=arrTwo[j];
            j++, k++;
        }
    }

    for(; i<5; i++){
        mergedArr[k]=arrOne[i];
        k++;
    }
    for(; j<3; j++){
        mergedArr[k]=arrTwo[j];
        k++;
    }

    for(int i=0; i<8; i++){
        std::cout<<mergedArr[i]<<" ";
    }
    return 0;
}

/*
Time Complexity -> Theta(m+n). Here, we are more interested in the copying of the elements rather than 
comparisons.
*/