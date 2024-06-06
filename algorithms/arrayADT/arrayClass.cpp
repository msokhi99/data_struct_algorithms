#include<iostream> 
#include<cstdlib>
#include<time.h>
#include<cmath>
#include<unordered_set>


/*
Things left to do: 
Rotate Array,
Merge Array,
Shift Array,
Set Ops on Array.
*/
class arr;

class arr{
    private:
    int arrSize;
    int numElements;
    int * ptrToArr;

    public:
    arr(int size=0, int elements=0);
    void populateArr();
    void dispArr();
    void addElement(int val); // Adds element in the end.
    int countElements(); // Counts number of elements.
    void insertElement(int val, int index); // Adds an element given an index.
    void delElement(int index); // Deletes an element given an index.
    void linearSearch(int key);
    void binarySearch(int key);
    bool isSorted();
    int minElement();
    int maxElement();
    bool containsDups();
    int countDups();
    void removeDups();
    void bubbleSort();
    void getElement(int index);
    void setElement(int index, int val);
    void reverseArr();
    arr mergeArr(arr arrToMerge);
    int totalSum();
    float avg();
    friend void swap(int &x, int &y);
};

void swap(int &x, int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}

int main(){
    arr arrOne(5,5);
    arrOne.populateArr();
    arrOne.dispArr();
    arr arrTwo(10,10);
    arrTwo.populateArr();
    arrTwo.dispArr();
    arr mergedArr=arrOne.mergeArr(arrTwo);
    mergedArr.dispArr();
    mergedArr.removeDups();
    mergedArr.dispArr();
    mergedArr.bubbleSort();
    mergedArr.dispArr();

    

    return 0;
}

arr::arr(int size, int elements){
    if(size>=0 && elements>=0){
        if(elements>size){
            std::cout<<"Number of elements cannot be greater than size of the arr.\n";
        }
        this->arrSize=size;
        this->numElements=elements;
        this->ptrToArr=new int[this->arrSize];
    }
    else{
        std::cout<<"Index out of bounds.\n";
        return;
    }
}

void arr::populateArr(){
    srand(time(NULL));
    this->ptrToArr=new int[this->arrSize];
    for(int i=0; i<this->numElements; i++){
        this->ptrToArr[i]=rand()%10+1;
    }
}

void arr::dispArr(){
    std::cout<<"\n";
    std::cout<<"DISPLAYING ARR:\n";
    for(int i=0; i<this->numElements; i++){
        std::cout<<this->ptrToArr[i]<<" ";
    }
    std::cout<<"\n";
}

void arr::addElement(int val){
    if(this->numElements==this->arrSize){
        std::cout<<"Array is full.\n";
    }
    else{
        this->ptrToArr[numElements]=val;
        this->numElements++;
    }
}

void arr::delElement(int index){
    int deletedElement=this->ptrToArr[index];
    if(this->numElements==0){
        std::cout<<"The array is empty. There is nothing to delete.\n";
        return;
    }
    else{
        if(index<this->numElements){
            for(int i=index; i<numElements; i++){
                this->ptrToArr[i]=this->ptrToArr[i+1];
            }
            std::cout<<"The element that will be deleted is: "<<deletedElement<<"\n";
            this->numElements--;
        }
        else{
            std::cout<<"Index is out of bounds.\n";
        }
    }
}

int arr::countElements(){
    int tempCount=0;
    for(int i=0; i<this->numElements; i++){
        tempCount++;
    }
    std::cout<<"Total number of elements in the arr: "<<tempCount<<"\n";
    return tempCount;
}

void arr::insertElement(int val, int index){
    if(this->numElements!=this->arrSize){
        if(index>this->numElements+1){
        std::cout<<"Index is out of bounds.\n";
        return;
        }
        else{
            for(int i=this->numElements; i>index; i--){
                this->ptrToArr[i]=this->ptrToArr[i-1];
            }
            this->ptrToArr[index]=val;
            this->numElements++;
        }
    }
    else{
        std::cout<<"Array is full. \n";
    }
}

void arr::linearSearch(int key){
    for(int i=0; i<this->numElements; i++){
        if(this->ptrToArr[i]==key){
            std::cout<<"Key found at index: "<<i<<"\n";
            swap(this->ptrToArr[0],this->ptrToArr[i]);
            return;
        }
    }
    std::cout<<"Key not found.\n";
}

void arr::binarySearch(int key){
    if(containsDups()==true){
        removeDups();
        dispArr();
    }
    if(isSorted()==false){
        bubbleSort();
        dispArr();
    }
    int low=0;
    int high=this->numElements-1;
    while(low<high){
        int mid=floor((high+low)/2);
        if(this->ptrToArr[mid]==key){
            std::cout<<"Key found at index: "<<mid<<"\n";
            return;
            }
        else if(ptrToArr[mid]>key){
            high=mid-1;
            }
        else{
            low=mid+1;
            }
        }
        std::cout<<"Key not found.\n";
}

bool arr::isSorted(){
    for(int i=0; i<this->numElements; i++){
        if(this->ptrToArr[i]>this->ptrToArr[i+1]){
            return false;
        }
    }
    return true;
}

int arr::minElement(){
    int tempMin=this->ptrToArr[0];
    for(int i=1; i<this->numElements; i++){
        if(this->ptrToArr[i]<tempMin){
            tempMin=this->ptrToArr[i];
        }
    }
    std::cout<<"The minimum element in this array is: "<<tempMin<<"\n";
    return tempMin;
}

int arr::maxElement(){
    int tempMax=0;
    for(int i=0; i<this->numElements; i++){
        if(this->ptrToArr[i]>tempMax){
            tempMax=this->ptrToArr[i];
        }
    }
    std::cout<<"The maximum element in this array is: "<<tempMax<<"\n";
    return tempMax;
}

bool arr::containsDups(){
    int tempMax=maxElement();
    int * hashPtr=new int[tempMax+1]();
    for(int i=0; i<this->numElements; i++){
        hashPtr[this->ptrToArr[i]]++;
    }
    std::cout<<"\n";
    std::cout<<"HASH TABLE\n";
    for(int i=0; i<=tempMax; i++){
        std::cout<<hashPtr[i]<<" ";
    }
    std::cout<<"\n";

    for(int i=0; i<tempMax; i++){
        if(hashPtr[i]>1){
            return true;
        }
    }
    return false;
}

void arr::removeDups(){
    std::unordered_set<int> seenElements;
    int uniqueIndex=0;
    for(int i=0; i<this->numElements; i++){
        if(seenElements.find(this->ptrToArr[i])==seenElements.end()){
            seenElements.insert(this->ptrToArr[i]);
            this->ptrToArr[uniqueIndex++]=this->ptrToArr[i];
        }
    }
    this->numElements=uniqueIndex;
}

void arr::bubbleSort(){
    for(int i=0; i<this->numElements; i++){
        for(int j=0; j<this->numElements-i-1; j++){
            if(this->ptrToArr[j]>this->ptrToArr[j+1]){
                swap(this->ptrToArr[j],this->ptrToArr[j+1]);
            }
        }
    }
}

int arr::totalSum(){
    int tempSum=0;
    for(int i=0; i<this->numElements; i++){
        tempSum=tempSum+this->ptrToArr[i];
    }
    std::cout<<"The total sum is: "<<tempSum<<"\n";
    return tempSum;
}

float arr::avg(){
    float tempAvg;
    tempAvg=(float)totalSum()/countElements();
    std::cout<<"The average is: "<<tempAvg;
    return tempAvg;
}

void arr::getElement(int index){
    if(index>=0 && index<this->numElements){
        std::cout<<this->ptrToArr[index]<<"\n";
    }
    else{
        std::cout<<"Index is out of bounds.\n";
        return;
    }
}

void arr::setElement(int index, int val){
    if(index>=0 && index<this->numElements){
        this->ptrToArr[index]=val;
    }
    else{
        std::cout<<"Index is out of bounds.\n";
        return;
    }
}

void arr::reverseArr(){
    int i=0;
    int j=this->numElements-1;
    while(i<j){
        swap(this->ptrToArr[i],this->ptrToArr[j]);
        i++, j--;
    }
}

// Fix This
arr arr::mergeArr(arr arrToMerge){
    int totalDups(this->countDups()+arrToMerge.countDups());
    int arrSizeForFirstArr=this->arrSize;
    int arrSizeForSecondArr=arrToMerge.arrSize;
    int numElementsForFirstArr=this->numElements;
    int numElementsForSecondArr=arrToMerge.numElements;
    arr thirdArr(arrSizeForFirstArr+arrSizeForSecondArr-totalDups,numElementsForFirstArr+numElementsForSecondArr-totalDups);
    int i=0, j=0, k=0;
    while(i<numElementsForFirstArr && j<numElementsForSecondArr){
        if(this->ptrToArr[i]<arrToMerge.ptrToArr[j]){
            thirdArr.ptrToArr[k]=this->ptrToArr[i];
            i++,k++;
        }
        else if(this->ptrToArr[i]>arrToMerge.ptrToArr[j]){
            thirdArr.ptrToArr[k]=arrToMerge.ptrToArr[j];
            j++, k++;
        }
        else if(this->ptrToArr[i]==arrToMerge.ptrToArr[j]){
            thirdArr.ptrToArr[k]=arrToMerge.ptrToArr[j];
            i++, j++, k++;
        }
    }

    for(; i<this->numElements; i++){
        thirdArr.ptrToArr[k]=this->ptrToArr[i];
        k++;
    }
    for(; j<arrToMerge.numElements; j++){
        thirdArr.ptrToArr[k]=arrToMerge.ptrToArr[j];
        k++;
    }
    return thirdArr;   
}

int arr::countDups(){
    int tempMax=maxElement();
    int tempCount=0;
    int * hashPtr=new int[tempMax+1]();
    for(int i=0; i<this->numElements; i++){
        hashPtr[this->ptrToArr[i]]++;
    }
    std::cout<<"\n";
    std::cout<<"HASH TABLE\n";
    for(int i=0; i<=tempMax; i++){
        std::cout<<hashPtr[i]<<" ";
    }
    std::cout<<"\n";

    for(int i=0; i<tempMax; i++){
        if(hashPtr[i]>1){
            tempCount++;
        }
    }
    return tempCount;
}

