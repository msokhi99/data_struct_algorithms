#include<iostream> 
#include<cstdlib>
#include<time.h>

struct node;

void createFirstLinkedList(int elements);
void createSecondLinkedList(int elements);
void dispLL(struct node * ptr);
void concatLL(struct node * ptrOne, struct node * &ptrTwo);

struct node{
    int data;
    struct node * ptrToNextNode;
};

struct node * ptrToFirstNodeOfLL=NULL;
struct node * ptrToLastNodeOfLL=NULL;
struct node * ptrToFirstNodeOfLL2=NULL;
struct node * ptrToLastNodeOfLL2=NULL;

void createFirstLinkedList(int elements){
    ptrToFirstNodeOfLL=new node;
    ptrToFirstNodeOfLL->data=rand()%100+1;
    ptrToFirstNodeOfLL->ptrToNextNode=NULL;
    ptrToLastNodeOfLL=ptrToFirstNodeOfLL;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->data=rand()%100+1;
        nn->ptrToNextNode=NULL;
        ptrToLastNodeOfLL->ptrToNextNode=nn;
        ptrToLastNodeOfLL=nn;
    }
}

void createSecondLinkedList(int elements){
    ptrToFirstNodeOfLL2=new node;
    ptrToFirstNodeOfLL2->data=rand()%100+1;
    ptrToFirstNodeOfLL2->ptrToNextNode=NULL;
    ptrToLastNodeOfLL2=ptrToFirstNodeOfLL2;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->data=rand()%100+1;
        nn->ptrToNextNode=NULL;
        ptrToLastNodeOfLL2->ptrToNextNode=nn;
        ptrToLastNodeOfLL2=nn;
    }
}

void dispLL(struct node * ptr){
    std::cout<<"LINKED LIST\n";
    while(ptr!=NULL){
        std::cout<<ptr->data<<" ";
        ptr=ptr->ptrToNextNode;
    }
    std::cout<<"\n";
}

void concatLL(struct node * ptrOne, struct node *&ptrTwo){
    while(ptrOne->ptrToNextNode!=NULL){
        ptrOne=ptrOne->ptrToNextNode;
    }
    ptrOne->ptrToNextNode=ptrTwo;
    ptrTwo=NULL;
}

int main(){
    srand(time(NULL));
    createFirstLinkedList(20);
    dispLL(ptrToFirstNodeOfLL);
    createSecondLinkedList(10);
    dispLL(ptrToFirstNodeOfLL2);
    concatLL(ptrToFirstNodeOfLL, ptrToFirstNodeOfLL2);
    dispLL(ptrToFirstNodeOfLL);
    return 0;
}
