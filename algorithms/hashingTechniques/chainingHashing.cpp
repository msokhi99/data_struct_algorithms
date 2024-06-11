/*
Implementation of hashing using chaining for searching a list of keys from a list of integers.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>

class arr;
class node;
class hash;

class arr{
    private:
    int sizeOfArr;
    int numElementsOfArr;
    int *ptrToArr;
    
    public: 
    //Default Constructor:
    arr();
    //Parameterized Constructor:
    arr(int size, int elements);
    //Deep Copy Constructor:
    arr(const arr& other);
    //Copy Assignment Operator:
    arr& operator=(const arr& other){
        if(this==&other){
            return *this;
        }
        delete[] ptrToArr;
        sizeOfArr=other.sizeOfArr;
        numElementsOfArr=other.numElementsOfArr;
        ptrToArr=new int[numElementsOfArr];
        std::copy(other.ptrToArr,other.ptrToArr+numElementsOfArr,ptrToArr);
        return *this;
    }
    //Setter Methods:
    void setSizeOfArr();
    int getSizeOfArr() const;
    void setNumElementsArr();
    int getNumElementsArr() const;
    void createArrAndPopulate();
    void dispArr() const;
    int getArrElement(int index) const;
    ~arr();
};

arr::arr():sizeOfArr(1), numElementsOfArr(1), ptrToArr(new int[numElementsOfArr]){}

arr::arr(int size, int elements):sizeOfArr(size),numElementsOfArr(elements),ptrToArr(new int[numElementsOfArr]){};

arr::arr(const arr& other):sizeOfArr(other.sizeOfArr),numElementsOfArr(other.numElementsOfArr),ptrToArr(new int[numElementsOfArr]){
    std::copy(other.ptrToArr, other.ptrToArr+numElementsOfArr,ptrToArr);
}

void arr::setSizeOfArr(){
    int tempSize;
    std::cout<<"Enter the size of the array: ";
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
            std::cout<<"Error Code: "<<errorCode<<"\n";
            std::cout<<"Array size must be > 0\n\n";
            std::cout<<"Please enter the size again: ";
            std::cin>>tempSize;
        }
    }
}

int arr::getSizeOfArr() const{
    return sizeOfArr;
}

void arr::setNumElementsArr(){
    int tempElements;
    std::cout<<"Enter the number of elements: ";
    std::cin>>tempElements;
    while(true){
        try{
            if(tempElements>=1){
                try{
                    if(tempElements<=getSizeOfArr()){
                        numElementsOfArr=tempElements;
                        break;
                    }
                    else{
                        throw 100;
                    }
                }
                catch(int errorCode){
                    std::cout<<"Error Code: "<<errorCode<<"\n";
                    std::cout<<"Number of elements must be <= Array Size.\n\n";
                    std::cout<<"Please enter the number of elements again: ";
                    std::cin>>tempElements;
                }     
            }
            else{
                throw 100;
            }
        }
        catch(int errorCode){
            std::cout<<"Error Code: "<<errorCode<<"\n";
            std::cout<<"Number of elements must be >= 1.\n\n";
            std::cout<<"Please enter the number of elements again: ";
            std::cin>>tempElements;
        }
    }
}

int arr::getNumElementsArr() const{
    return numElementsOfArr;
}

void arr::createArrAndPopulate(){
    ptrToArr=new int[getSizeOfArr()];
    for(int i=0;i<getNumElementsArr();i++){
        ptrToArr[i]=rand()%10000+1;
    }
}

void arr::dispArr() const{
    std::cout<<"\n::: DISPLAYING ARR :::\n";
    for(int i=0;i<getNumElementsArr();i++){
        std::cout<<ptrToArr[i]<<" ";
    }
    std::cout<<"\n\n";
}

int arr::getArrElement(int index) const{
    return ptrToArr[index];
}

arr::~arr(){
    delete[] ptrToArr;
}

class node{
    private:
    int nodeData;
    node* ptrToNextNode;

    public:
    node();
    //Setters and Getters
    void setNodeData(int data);
    int getNodeData() const;
    void setPtrToNextNode(node* ptr);
    node* getPtrToNextNode() const;
};

node::node():nodeData(10),ptrToNextNode(nullptr){};

void node::setNodeData(int data){
    nodeData=data;
}

int node::getNodeData() const{
    return nodeData;
}

void node::setPtrToNextNode(node* ptr){
    ptrToNextNode=ptr;
}

node* node::getPtrToNextNode() const{return ptrToNextNode;}

class hash{
    private:
    int sizeOfHashTable;
    node** hashTable;

    public:
    //Default constructor.
    hash();
    //Parameterized constructor.
    hash(int size);
    //Deep Copy Constructor.
    hash(const hash& other);
    //Copy Assignment Operaot.
    hash& operator=(const hash& other){
        if(this==&other){
            return *this;
        }
        for(int i=0; i<sizeOfHashTable; i++){
            node*p = hashTable[i];
            while(hashTable[i]!=nullptr){
                hashTable[i]=hashTable[i]->getPtrToNextNode();
                delete p;
                p=hashTable[i];
            }
        }
        delete[] hashTable;

        hashTable=new node*[10];
    for(int i=0;i<10;i++){
        if(other.hashTable[i]!=nullptr){
            node* current=nullptr;
            node* tail=nullptr;
            node* otherCurrent=other.hashTable[i];

            while(otherCurrent!=nullptr){
                node* nn=new node;
                nn->setNodeData(otherCurrent->getNodeData());
                nn->setPtrToNextNode(nullptr);

                if(current->getPtrToNextNode()==nullptr){
                    hashTable[i]=nn;
                    current=nn;
                }
                else{
                    tail->setPtrToNextNode(nn);
                }

                tail=nn;
                otherCurrent=otherCurrent->getPtrToNextNode();
            }
        }
        else{
            hashTable[i]=nullptr;
        }
    }
    return *this;
    }
    int getSizeOfHashTable() const;
    int hashFunction(int val);
    void insertElement(arr& obj);
    void searchElement(arr& obj);
    ~hash();
};

int hash::getSizeOfHashTable() const {return sizeOfHashTable;}

hash::hash():sizeOfHashTable(10),hashTable(new node*[sizeOfHashTable]){
        for(int i=0; i<sizeOfHashTable; i++){
            hashTable[i]=nullptr;
        }
    };

hash::hash(int size):sizeOfHashTable(size){}

hash::hash(const hash& other){
    hashTable=new node*[10];
     for(int i=0;i<10;i++){
        if(other.hashTable[i]!=nullptr){
            node* current=nullptr;
            node* tail=nullptr;
            node* otherCurrent=other.hashTable[i];

            while(otherCurrent!=nullptr){
                node* nn=new node;
                nn->setNodeData(otherCurrent->getNodeData());
                nn->setPtrToNextNode(nullptr);

                if(current->getPtrToNextNode()==nullptr){
                    hashTable[i]=nn;
                    current=nn;
                }
                else{
                    tail->setPtrToNextNode(nn);
                }

                tail=nn;
                otherCurrent=otherCurrent->getPtrToNextNode();
            }
        }
        else{
            hashTable[i]=nullptr;
        }
    }
}

int hash::hashFunction(int val){return val%10;}

void hash::insertElement(arr& obj){
    for(int i=0; i<obj.getNumElementsArr(); i++){
        int hashTableIndex=hashFunction(obj.getArrElement(i));
        node* nn=new node;
        nn->setNodeData(obj.getArrElement(i));
        nn->setPtrToNextNode(nullptr);
        if(hashTable[hashTableIndex]==nullptr){
            hashTable[hashTableIndex]=nn;
        }
        else{
            node* current=hashTable[hashTableIndex];
            node* trailing_current=hashTable[hashTableIndex];
            while(current!=nullptr and current->getNodeData()<obj.getArrElement(i)){
                trailing_current=current;
                current=current->getPtrToNextNode();
            }
            if(trailing_current==hashTable[hashTableIndex]){
                nn->setPtrToNextNode(hashTable[hashTableIndex]);
                hashTable[hashTableIndex]=nn;
            }
            else{
                nn->setPtrToNextNode(trailing_current->getPtrToNextNode());
                trailing_current->setPtrToNextNode(nn);
            }
        }
    }
}

void hash::searchElement(arr& obj){
    for(int i=0; i<obj.getNumElementsArr(); i++){
        int hashTableIndex=hashFunction(obj.getArrElement(i));
        node* tempNode=hashTable[hashTableIndex];
        bool elementFound=false;
        while(tempNode!=nullptr){
            if(tempNode->getNodeData()==obj.getArrElement(i)){
                std::cout<<"Search for: "<<obj.getArrElement(i)<<" is succesfull.\n"; 
                elementFound=true;
                break;
            }
            else{
                tempNode=tempNode->getPtrToNextNode();
            }
        }

        if(!elementFound){
            std::cout<<"Search for: "<<obj.getArrElement(i)<<" is unsuccesfull.\n";
        }
    }
}

hash::~hash(){
    for(int i=0; i<sizeOfHashTable; i++){
        node*p = hashTable[i];
        while(hashTable[i]!=nullptr){
            hashTable[i]=hashTable[i]->getPtrToNextNode();
            delete p;
            p=hashTable[i];
        }
    }
    delete[] hashTable;
}

int main(){
    srand(time(NULL));
    arr arrOne, arrTwo;
    arrOne.setSizeOfArr();
    arrOne.setNumElementsArr();
    arrOne.createArrAndPopulate();
    arrOne.dispArr();
    arrTwo.setSizeOfArr();
    arrTwo.setNumElementsArr();
    arrTwo.createArrAndPopulate();
    arrTwo.dispArr();
    hash hashTable;
    hashTable.insertElement(arrOne);  
    hashTable.searchElement(arrTwo);
    return 0;
}
