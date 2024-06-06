#include<iostream> 
#include<cstdlib>
#include<time.h>

struct node;
void createDoubleLinkedList(int elements);
void dispDLL();
void dispDLLFromEnd();

struct node{
    struct node * ptrToPreNode;
    int nodeData;
    struct node * ptrToNextNode;
};

struct node * ptrToHeadNode=nullptr;
struct node * ptrToLastNode=nullptr;

void createDoubleLinkedList(int elements){
    ptrToHeadNode=new node;
    ptrToHeadNode->nodeData=rand()%100+1;
    ptrToHeadNode->ptrToPreNode=nullptr;
    ptrToHeadNode->ptrToNextNode=nullptr;
    ptrToLastNode=ptrToHeadNode;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->nodeData=rand()%100+1;
        ptrToLastNode->ptrToNextNode=nn;
        nn->ptrToPreNode=ptrToLastNode;
        nn->ptrToNextNode=nullptr;
        ptrToLastNode=nn;
    }
}

void dispDLL(){
    std::cout<<"DOUBLY LINKED LIST\n";
    struct node * traversePtr=ptrToHeadNode;
    while(traversePtr!=nullptr){
        std::cout<<traversePtr->nodeData<<" ";
        traversePtr=traversePtr->ptrToNextNode;
    }
    std::cout<<"\n";
}

void dispDLLFromEnd(){
    std::cout<<"DOUBLY LINKED LIST FROM END\n";
    struct node * traverseLastNode=ptrToLastNode;
    while(traverseLastNode!=nullptr){
        std::cout<<traverseLastNode->nodeData<<" ";
        traverseLastNode=traverseLastNode->ptrToPreNode;
    }
    std::cout<<"\n";
}

int main(){
    srand(time(NULL));
    createDoubleLinkedList(50);
    dispDLL();
    dispDLLFromEnd();
    return 0;
}