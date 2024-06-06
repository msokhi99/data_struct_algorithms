#include<iostream>
#include<cstdlib>
#include<time.h>

struct node;
void createDLL(int elements);
void dispDLL();
void insertElement(int index, int value);
int countElements();

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
    insertElement(0,1000);
    dispDLL();
    insertElement(50,1000);
    dispDLL();
    insertElement(52,1000);
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
    std::cout<<"DOUBLY LINKED LIST\n";
    struct node * traverseDLLPtr=ptrToFirstNode;
    while(traverseDLLPtr!=nullptr){
        std::cout<<traverseDLLPtr->nodeData<<" ";
        traverseDLLPtr=traverseDLLPtr->ptrToNextNode;
    }
    std::cout<<"\n";
}

void insertElement(int index, int value){
    if(index==0){
        struct node * nn=new node;
        nn->nodeData=value;
        if(ptrToFirstNode==nullptr){
            nn->ptrToPrevNode=ptrToLastNode;
            nn->ptrToNextNode=nullptr;
            ptrToLastNode->ptrToNextNode=nn;
            ptrToLastNode=nn;
        }
        else{
            nn->ptrToNextNode=ptrToFirstNode;
            ptrToFirstNode->ptrToPrevNode=nn;
            nn->ptrToPrevNode=nullptr;
            ptrToFirstNode=nn;
        }
    }
    else{
        if(index<0 || index>countElements()){
            std::cout<<"Index out of bounds.\n";
            return;
        }
        else{
            struct node * nn=new node;
            nn->nodeData=value;
            struct node * ptrOne=ptrToFirstNode;
            for(int i=0; i<index-1; i++){
                ptrOne=ptrOne->ptrToNextNode;
            }
            nn->ptrToNextNode=ptrOne->ptrToNextNode;
            nn->ptrToPrevNode=ptrOne;
            if(ptrOne->ptrToNextNode!=nullptr){
                ptrOne->ptrToNextNode->ptrToPrevNode=nn;
            }
            ptrOne->ptrToNextNode=nn;
        }
    }
}

int countElements(){
    struct node * traversePtr=ptrToFirstNode;
    int count=0;
    while(traversePtr!=nullptr){
        count++;
        traversePtr=traversePtr->ptrToNextNode;
    }
    return count;
}