#include<iostream>

void duplicateSortedArr(int [],int);

void duplicateSortedArr(int A[], int elements){
    int tempDuplicate=0;
    for(int i=0; i<elements; i++){
        if(A[i]==A[i+1]){
            if(A[i]!=tempDuplicate){
                std::cout<<A[i]<<" ";
                tempDuplicate=A[i];
            }
        }
    }
    std::cout<<"\n";
}

void countDuplicatedSortedArr(int A[], int elements){
    int C[35]={0};
    for(int i=0; i<elements; i++){
        C[A[i]]++;
    }
    for(int i=0; i<20; i++){
        if(C[i]>1){
            std::cout<<i<<" has "<<C[i]<<" duplicates.\n";
        }
    }
}

/*
Removing Duplicates from a sorted or unsorted array: 
#include<unordered_set>
void deleteDupsTwo(int * ptr, int &elements) {
    std::unordered_set<int> seen;
    int uniqueIndex = 0;
    for (int i = 0; i < elements; ++i) {
        if (seen.find(ptr[i]) == seen.end()) {
            seen.insert(ptr[i]);
            ptr[uniqueIndex++] = ptr[i];
        }
    }
    elements = uniqueIndex;
}
*/

int main(){
    /*
    Finding Duplicates in a sorted array.
    */
    int A[]={3,6,8,8,10,12,15,15,15,20};
    duplicateSortedArr(A,10);
    /*
    Counting Duplicated in a sorted array.
    */
    countDuplicatedSortedArr(A,10);
    /*
    Counting duplicates in an unsorted array.
    Sorted and unsorted both use hashing.
    */
    int B[]={10,6,5,2,1,22,34,2,5};
    countDuplicatedSortedArr(B,9);
    return 0;

    /*
    Time complexity is O(n).
    */
}