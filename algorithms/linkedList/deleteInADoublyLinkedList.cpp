#include<iostream>
#include<cstdlib>
#include<time.h>

struct node;
void createDLL(int elements);
void dispDLL();
void delElement(int index);

struct node{
    struct node * ptrToPrevNode;
    int nodeData;
    struct node * ptrToNextNode;
};

struct node * ptrToFirstNode=nullptr;
struct node * ptrToLastNode=nullptr;

int main(){
    srand(time(NULL));
    createDLL(50);
    dispDLL();
    delElement(50);
    dispDLL();
    return 0;
}

void createDLL(int elements){
    ptrToFirstNode=new node;
    ptrToFirstNode->ptrToPrevNode=nullptr;
    ptrToFirstNode->nodeData=rand()%100+1;
    ptrToFirstNode->ptrToNextNode=nullptr;
    ptrToLastNode=ptrToFirstNode;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->ptrToPrevNode=ptrToLastNode;
        nn->nodeData=rand()%100+1;
        nn->ptrToNextNode=nullptr;
        ptrToLastNode->ptrToNextNode=nn;
        ptrToLastNode=nn;
    }
}

void dispDLL(){
    std::cout<<"\n";
    std::cout<<"LINKED LIST\n";
    struct node * tempPtr=ptrToFirstNode;
    while(tempPtr!=nullptr){
        std::cout<<tempPtr->nodeData<<" ";
        tempPtr=tempPtr->ptrToNextNode;
    }
    std::cout<<"\n";
}

void delElement(int index){
    if(index==1){
        struct node * nodeOne=ptrToFirstNode;
        ptrToFirstNode=ptrToFirstNode->ptrToNextNode;
        if(ptrToFirstNode!=nullptr){
            ptrToFirstNode->ptrToPrevNode=nullptr;
        }
        delete nodeOne;
    }
    else{
        if(index<1 || index>50){
            std::cout<<"Index is out of bounds.\n";
            return;
        }
        else{
            struct node * tempPtr=ptrToFirstNode;
            for(int i=0; i<index-1; i++){
                tempPtr=tempPtr->ptrToNextNode;
            }
            tempPtr->ptrToPrevNode->ptrToNextNode=tempPtr->ptrToNextNode;
            if(tempPtr->ptrToNextNode=nullptr){
                tempPtr->ptrToNextNode->ptrToPrevNode=tempPtr->ptrToPrevNode;
            }
            delete tempPtr;
        }
    }
}