#include<iostream>
#include<cstdlib>
#include<time.h>

struct node;
void createDLL(int elements);
void dispDLL();
void reverseDLL(struct node * ptr);

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
    reverseDLL(ptrToFirstNode);
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
    struct node * dispPtr=ptrToFirstNode;
    std::cout<<"\n";
    std::cout<<"DOUBLY LINKED LIST\n";
    while(dispPtr!=nullptr){
        std::cout<<dispPtr->nodeData<<" ";
        dispPtr=dispPtr->ptrToNextNode;
    }
    std::cout<<"\n";
}

void reverseDLL(struct node * ptr){
    struct node * temp=nullptr;
    while(ptr!=nullptr){
        temp=ptr->ptrToNextNode;
        ptr->ptrToNextNode=ptr->ptrToPrevNode;
        ptr->ptrToPrevNode=temp;
        ptr=ptr->ptrToPrevNode;
        if(ptr!=nullptr && ptr->ptrToNextNode==nullptr){
            ptrToFirstNode=ptr;
        }
    }
}