#include<iostream> 

void append(int [],int,int);

void append(int A[], int elements, int size){
    int tempNum;
    std::cout<<"Enter the number you want to add: \n";
    std::cin>>tempNum;
    if(elements<size){
        A[elements]=tempNum;
        elements++;
    }
    else{
        std::cout<<"The array is full.\n";
    }
}

int main(){
    int A[5]={1,2,3,4};
    /*
    Suppose, I want to add an element to the above array. Notice, the 
    array is of size 5 and also has 5 elements. So, before adding an 
    element, I will need to delete an element (a different case). Let's assume 
    the array is of size 5 but only has 4 elements. Now, we can add another 
    element to it.
    */
    std::cout<<"This is what the array looks like at the moment:"<<"\n";
    for(int i=0; i<4; i++){
        std::cout<<A[i]<<" ";
    }
    std::cout<<"\n";
    append(A,4,5);
    std::cout<<"This is what the array looks like after adding the number 5:\n";
    for(int i=0; i<5; i++){
        std::cout<<A[i]<<" ";
    }
    return 0;
}

/*
Append adds the element to the end of an array.
Time Complexity -> O(n).
*/
