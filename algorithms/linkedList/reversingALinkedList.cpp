#include<iostream>
#include<cstdlib>
#include<time.h>

struct node;

void randomLL(struct node * ptr, int elements);
void dispLL(struct node * ptr);
void reverseLL(struct node * ptr);
void reverseLLTwo(struct node * ptr, int elements);

struct node{
    int data;
    struct node * ptrToNextNode;
};

struct node * ptrToFirstNode=NULL;
struct node * ptrToLastNode=NULL;

void randomLL(struct node * ptr, int elements){
    srand(time(NULL));
    ptrToFirstNode=new node;
    ptrToFirstNode->data=rand()%100+1;
    ptrToFirstNode->ptrToNextNode=NULL;
    ptrToLastNode=ptrToFirstNode;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->data=rand()%100+1;
        nn->ptrToNextNode=NULL;
        ptrToLastNode->ptrToNextNode=nn;
        ptrToLastNode=nn;
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

/*
One way to do it, is by reversing the links. This is recommended. This 
method is also called reversing using sliding pointers.
*/

void reverseLL(struct node * ptr){
    struct node * q=NULL;
    struct node * r=NULL;
    while(ptr!=NULL){
        r=q;
        q=ptr;
        ptr=ptr->ptrToNextNode;
        q->ptrToNextNode=r;
    }
    ptrToFirstNode=q;
}

/*
Another method. This is not recommended. It takes up quite some space.
*/
void reverseLLTwo(struct node * ptr, int elements){
    int arr[elements]={0};
    int i=0;
    while(ptr!=NULL){
        arr[i]=ptr->data;
        i++;
        ptr=ptr->ptrToNextNode;
    }
    std::cout<<"ARR\n";
    for(int i=0; i<elements; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    ptr=ptrToFirstNode;
    i=elements-1;
    while(ptr!=NULL){
        ptr->data=arr[i];
        i--;
        ptr=ptr->ptrToNextNode;
    }
}

int main(){
    randomLL(ptrToFirstNode, 50);
    dispLL(ptrToFirstNode);
    /*reverseLL(ptrToFirstNode);
    dispLL(ptrToFirstNode);*/
    reverseLLTwo(ptrToFirstNode, 50);
    dispLL(ptrToFirstNode);
    return 0;
}