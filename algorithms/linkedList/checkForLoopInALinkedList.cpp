#include<iostream> 

struct node;

void createLL(int elements);
void dispLL(struct node * ptr);
bool containsLoop(struct node * ptr);

struct node{
    int data;
    struct node * ptrToNextNode;
};

struct node * ptrToLLFirstNode=NULL;
struct node * ptrToLLLastNode=NULL;

void createLL(int elements){
    ptrToLLFirstNode=new node;
    ptrToLLFirstNode->data=1;
    ptrToLLFirstNode->ptrToNextNode=NULL;
    ptrToLLLastNode=ptrToLLFirstNode;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->data=i+1;
        nn->ptrToNextNode=NULL;
        ptrToLLLastNode->ptrToNextNode=nn;
        ptrToLLLastNode=nn;
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

bool containsLoop(struct node * ptr){
    struct node * p=ptr;
    struct node * q=ptr;

    do{
        p=p->ptrToNextNode;
        q=q->ptrToNextNode;
        if(q!=NULL){
            q=q->ptrToNextNode;
        }
    }
    while(p!=NULL && q!=NULL && p!=q);

    if(p==q){
        return true;
    }
    return false;
}

int main(){
    createLL(10);
    struct node * t1=ptrToLLFirstNode->ptrToNextNode->ptrToNextNode->ptrToNextNode;
    struct node * t2=ptrToLLFirstNode->ptrToNextNode->ptrToNextNode->ptrToNextNode->ptrToNextNode->ptrToNextNode;
    t2->ptrToNextNode=t1;
    std::cout<<containsLoop(ptrToLLFirstNode);
    return 0;
}