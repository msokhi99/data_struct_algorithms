#include<iostream>
#include<cstdlib>
#include<time.h> 

struct node;
void createCircularLL(int elements);
void dispCircularLL();
void insertElement(int index, int val);
void insertElementFull(int index, int val);
void deleteElement(int index);
int countNodes(struct node * ptr);

struct node{
    int nodeData;
    struct node * ptrToNextNode;
};

struct node * ptrToHeadNode=nullptr;
struct node * ptrToLastNode=nullptr;

void createCircularLL(int elements){
    ptrToHeadNode=new node;
    ptrToHeadNode->nodeData=rand()%100+1;
    ptrToHeadNode->ptrToNextNode=ptrToHeadNode;
    ptrToLastNode=ptrToHeadNode;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->nodeData=rand()%100+1;
        nn->ptrToNextNode=ptrToHeadNode;
        ptrToLastNode->ptrToNextNode=nn;
        ptrToLastNode=nn;
    }
}

void dispCircularLL(){
    std::cout<<"CIRCULAR LINKED LIST\n";
    struct node * tempPtr=ptrToHeadNode;
    do{
        std::cout<<tempPtr->nodeData<<" ";
        tempPtr=tempPtr->ptrToNextNode;
    }while(tempPtr!=ptrToHeadNode);
    std::cout<<"\n";
}

void insertElement(int index, int val){
    struct node * tempPtr=ptrToHeadNode;

    // Inserting after any index > 0. If inserting right after head node, then O(1).
    if(index>0){
        struct node * newNode=new node;
        struct node * followPtr=new node;
        followPtr=ptrToHeadNode;
        newNode->nodeData=val;
        for(int i=0; i<index-1; i++){
            followPtr=followPtr->ptrToNextNode;
        }
        newNode->ptrToNextNode=followPtr->ptrToNextNode;
        followPtr->ptrToNextNode=newNode;
    }
    if(index==0){
        struct node * newNode=new node;
        struct node * getLastNode=new node;
        getLastNode=ptrToHeadNode;
        newNode->nodeData=val;
        newNode->ptrToNextNode=ptrToHeadNode;
        while(getLastNode->ptrToNextNode!=ptrToHeadNode){
            getLastNode=getLastNode->ptrToNextNode;
        }
        getLastNode->ptrToNextNode=newNode;
        ptrToHeadNode=newNode;
        ptrToLastNode=getLastNode;
    }
}

void insertElementFull(int index, int val){
    struct node * newNode=new node;
    struct node * getLastNode=ptrToHeadNode;
    struct node * followPtr=ptrToHeadNode;
    newNode->nodeData=val;
    if(index==0){
        if(ptrToHeadNode==nullptr){
            ptrToHeadNode=newNode;
            ptrToHeadNode=ptrToHeadNode;
            ptrToLastNode=ptrToHeadNode;
        }
        else{
            newNode->ptrToNextNode=ptrToHeadNode;
            while(getLastNode->ptrToNextNode!=ptrToHeadNode){
                getLastNode=getLastNode->ptrToNextNode;
            }
            getLastNode->ptrToNextNode=newNode;
            ptrToHeadNode=newNode;
            ptrToLastNode=getLastNode;
        }
    }
    else{
        if(index>countNodes(ptrToHeadNode) || index<0){
            std::cout<<"Index out of bounds\n";
            return;
        }
        for(int i=0; i<index-1; i++){
            followPtr=followPtr->ptrToNextNode;
        }
        newNode->ptrToNextNode=followPtr->ptrToNextNode;
        followPtr->ptrToNextNode=newNode;
    }
}

int countNodes(struct node * ptr){
    struct node * tempPtr=ptr;
    int count=0;
    do{
        tempPtr=tempPtr->ptrToNextNode;
        count++;
    }while(tempPtr!=ptrToHeadNode);
    return count;
}

void deleteElement(int index){
    if(index==0){
        if(ptrToHeadNode==nullptr){
            std::cout<<"Cannot delete an empty linked list.\n";
            return;
        }
        else{
            struct node * tempPtr=ptrToHeadNode;
            while(tempPtr->ptrToNextNode!=ptrToHeadNode){
                tempPtr=tempPtr->ptrToNextNode;
            }
            tempPtr->ptrToNextNode=ptrToHeadNode->ptrToNextNode;
            delete ptrToHeadNode;
            ptrToHeadNode=tempPtr->ptrToNextNode;
        }
    }
    else{
        if(index<0 || index>countNodes(ptrToHeadNode)){
            std::cout<<"Index out of bounds\n";
            return;
        }
        else{
            struct node * tempPtr=ptrToHeadNode;
            for(int i=0; i<index-2; i++){
                tempPtr=tempPtr->ptrToNextNode;
            }
            struct node * ptrAheadOfTemp=tempPtr->ptrToNextNode;
            tempPtr->ptrToNextNode=ptrAheadOfTemp->ptrToNextNode;
            delete ptrAheadOfTemp;
        }
    }
}

int main(){
    srand(time(NULL));
    createCircularLL(20);
    dispCircularLL();
    insertElementFull(20,1000);
    dispCircularLL();
    deleteElement(21);
    dispCircularLL();
    deleteElement(0);
    dispCircularLL();
    return 0;
}