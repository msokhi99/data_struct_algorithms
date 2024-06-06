#include<iostream> 

struct node;

void createCircularLL(int elements);
void dispCircularLL(struct node * ptr);

struct node{
    int data;
    struct node * ptrToNextNode;
};

struct node * ptrToFirstNodeLL=NULL;
struct node * ptrToLastNodeLL=NULL;

void createCircularLL(int elements){
    ptrToFirstNodeLL=new node;
    ptrToFirstNodeLL->data=1;
    ptrToFirstNodeLL->ptrToNextNode=ptrToFirstNodeLL;
    ptrToLastNodeLL=ptrToFirstNodeLL;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->data=i+1;
        nn->ptrToNextNode=ptrToLastNodeLL->ptrToNextNode;
        ptrToLastNodeLL->ptrToNextNode=nn;
        ptrToLastNodeLL=nn;
    }
}

void dispCircularLL(struct node * ptr){
    std::cout<<"LINKED LIST\n";
    do{
        std::cout<<ptr->data<<" ";
        ptr=ptr->ptrToNextNode;
    }while(ptr!=ptrToFirstNodeLL);
    std::cout<<"\n";
}

int main(){
    createCircularLL(50);
    dispCircularLL(ptrToFirstNodeLL);
    return 0;
}