#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<time.h>
#include<cmath>

class arr;
class hash;

class arr{
    private:
    int sizeOfArr;
    int numElementsArr;
    int* ptrToArr;

    public:
    //Default Constructor
    arr();
    //Parameterized Constructor
    arr(int size, int elements);
    //Copy Constructor
    arr(const arr& other);
    //Copy Assignment Operator
    arr& operator=(const arr& other){
        if(this==&other){
            return *this;
        }
        delete[] ptrToArr;
        sizeOfArr=other.sizeOfArr;
        numElementsArr=other.numElementsArr;
        ptrToArr=new int[sizeOfArr];
        std::copy(other.ptrToArr,other.ptrToArr+numElementsArr,ptrToArr);
        return *this;
    }
    //Setters:
    void setSizeArr();
    void setNumElementsArr();
    //Getters:
    int getSizeArr() const;
    int getNumElements() const;
    int getArrElement(int index);
    //Functions:
    void createArr();
    void dispArr() const;
    ~arr();
};

arr::arr():sizeOfArr(1),numElementsArr(1),ptrToArr(new int[sizeOfArr]){}
arr::arr(int size, int elements):sizeOfArr(size),numElementsArr(elements),ptrToArr(new int[numElementsArr]){}
arr::arr(const arr& other):sizeOfArr(other.sizeOfArr),numElementsArr(other.numElementsArr),ptrToArr(new int[sizeOfArr]){
    std::copy(other.ptrToArr,other.ptrToArr+numElementsArr,ptrToArr);
}
void arr::setSizeArr(){
    int tempSize;
    std::cout<<"Enter the size of the arr: ";
    std::cin>>tempSize;
    while(true){
        try{
            if(tempSize>=1){
                sizeOfArr=tempSize;
                break;
            }
            else{
                throw 100;
            }
        }
        catch(int errorCode){
            std::cout<<"ERROR: "<<errorCode<<" Arr. size must be (+).\n";
            std::cout<<"Please try again: ";
            std::cin>>tempSize;
        }
    }
}
int arr::getSizeArr() const{return sizeOfArr;}
void arr::setNumElementsArr(){
    int tempElements;
    std::cout<<"Enter the number of elements: ";
    std::cin>>tempElements;
    while(true){
        try{
            if(tempElements>=1){
                try{
                    if(tempElements<=getSizeArr()){
                        numElementsArr=tempElements;
                        break;
                    }
                    else{
                        throw 100;
                    }
                }
                catch(int errorCode){
                    std::cout<<"ERROR: "<<errorCode<<" Num. elements must be (<=) arr. size.\n";
                    std::cout<<"Please try again: ";
                    std::cin>>tempElements;
                }
            }
        }
        catch(int errorCode){
            std::cout<<"ERROR: "<<errorCode<<" Num. elements must be positive.\n";
            std::cout<<"Please try again: ";
            std::cin>>tempElements;
        }
    }
}
int arr::getNumElements() const{return numElementsArr;}
int arr::getArrElement(int index){return ptrToArr[index];}
void arr::createArr(){
    ptrToArr=new int[getSizeArr()];
    for(int i=0; i<getNumElements(); i++){
        ptrToArr[i]=rand()%100+1;
    }
}
void arr::dispArr() const{
    std::cout<<"\n:::: DISPLAYING ARR. ::::\n";
    for(int i=0; i<getNumElements(); i++){
        std::cout<<ptrToArr[i]<<" ";
    }
    std::cout<<"\n\n";
}

arr::~arr(){
    delete[] ptrToArr;
}

class hash{
    private:
    int sizeHashTable;
    int numElementsHashTable;
    int* ptrToHashTable;

    public:
    //Dafault Constructor
    hash();
    //Parameterized Constructor
    hash(int size, int elements);
    //Deep Copy Constructor
    hash(const hash &other);
    //Copy Assignment Operator
    hash& operator=(const hash &other){
        if(this==&other){
            return *this;
        }
        delete[] ptrToHashTable;
        sizeHashTable=other.sizeHashTable;
        numElementsHashTable=other.numElementsHashTable;
        ptrToHashTable=new int[sizeHashTable]{0};
        std::copy(other.ptrToHashTable, other.ptrToHashTable+numElementsHashTable, ptrToHashTable);
        return *this;
    }

    //Functions:
    void dispHashTable() const;
    int hashFunction(int val) const;
    int quadraticProbing(int val);
    void insertElement(arr &obj);
    void searchElement(arr &obj);
    ~hash();
};

hash::hash():sizeHashTable(50),numElementsHashTable(50),ptrToHashTable(new int[sizeHashTable]{0}){}
hash::hash(int size, int elements):sizeHashTable(size),numElementsHashTable(elements),ptrToHashTable(new int[sizeHashTable]{0}){}
hash::hash(const hash &other):sizeHashTable(other.sizeHashTable),numElementsHashTable(other.numElementsHashTable){
    ptrToHashTable=new int[sizeHashTable]{0};
    std::copy(other.ptrToHashTable,other.ptrToHashTable+numElementsHashTable,ptrToHashTable);
}
void hash::dispHashTable() const{
    std::cout<<"\n:::: DISPLAYING HASH TABLE ::::\n";
    for(int i=0; i<numElementsHashTable; i++){
        std::cout<<ptrToHashTable[i]<<" ";
    }
    std::cout<<"\n";
}
int hash::hashFunction(int val) const{return val%sizeHashTable;}
int hash::quadraticProbing(int val){
    int newIndex=hashFunction(val);
    int i=0; 
    while(ptrToHashTable[newIndex+(i*i)]%sizeHashTable !=0){
        i++;
    }
    return (newIndex+(i*i))%sizeHashTable;
}
void hash::insertElement(arr &obj){
    for (int i=0; i<obj.getNumElements(); i++){
        int hashTableIndex=hashFunction(obj.getArrElement(i));
        if(ptrToHashTable[hashTableIndex]!=0){
           hashTableIndex=quadraticProbing(obj.getArrElement(i));
        }
        else{
            ptrToHashTable[hashTableIndex]=obj.getArrElement(i);
        }
    }
}
void hash::searchElement(arr &obj){
    for(int i=0; i<obj.getNumElements(); i++){
        int hashTableIndex=hashFunction(obj.getArrElement(i));
        bool found=false;
        int j=0;
        while(ptrToHashTable[(hashTableIndex+(j*j))%sizeHashTable]!=0){
            if(ptrToHashTable[(hashTableIndex+(j*j))%sizeHashTable]==obj.getArrElement(i)){
                std::cout<<obj.getArrElement(i)<<": Search SUCCESFULL.\n";
                found=true;
                break;
            }
            j++;
            if(j>=sizeHashTable){
                break;
            }
        }

        if(!found){
            std::cout<<obj.getArrElement(i)<<": Search UNSUCCESFULL.\n";
        }
    }
}
hash::~hash(){
    delete[] ptrToHashTable;
}

int main(){
    arr arrOne;
    arrOne.setSizeArr();
    arrOne.setNumElementsArr();
    arrOne.createArr();
    arrOne.dispArr();
    hash hashTableOne;
    hashTableOne.insertElement(arrOne);
    hashTableOne.dispHashTable();
    arr arrKeys;
    arrKeys.setSizeArr();
    arrKeys.setNumElementsArr();
    arrKeys.createArr();
    arrKeys.dispArr();
    hashTableOne.searchElement(arrKeys);
    
    return 0;
}