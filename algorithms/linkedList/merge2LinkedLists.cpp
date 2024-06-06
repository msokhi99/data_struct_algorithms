#include<iostream> 

struct node;

void firstLinkedList(int arr[], int elements);
void secondLinkedList(int arr[], int elements);
void dispLL(struct node * ptr);
struct node * mergeTwoLinkedLists(struct node * &ptrOne, struct node * &ptrTwo);

struct node{
    int data;
    struct node * ptrToNextNode;
};

void dispLL(struct node * ptr){
    std::cout<<"LINKED LIST\n";
    while(ptr!=NULL){
        std::cout<<ptr->data<<" ";
        ptr=ptr->ptrToNextNode;
    }
    std::cout<<"\n";
}

struct node * ptrToFirstNode=NULL;
struct node * ptrToLastNode=NULL;
struct node * ptrToFirstNodeTwo=NULL;
struct node * ptrToLastNodeTwo=NULL;

void firstLinkedList(int arr[], int elements){
    ptrToFirstNode=new node;
    ptrToFirstNode->data=arr[0];
    ptrToFirstNode->ptrToNextNode=NULL;
    ptrToLastNode=ptrToFirstNode;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->data=arr[i];
        nn->ptrToNextNode=NULL;
        ptrToLastNode->ptrToNextNode=nn;
        ptrToLastNode=nn;
    }
}

void secondLinkedList(int arr[], int elements){
    ptrToFirstNodeTwo=new node;
    ptrToFirstNodeTwo->data=arr[0];
    ptrToFirstNodeTwo->ptrToNextNode=NULL;
    ptrToLastNodeTwo=ptrToFirstNodeTwo;

    for(int i=1; i<elements; i++){
        struct node * nn=new node;
        nn->data=arr[i];
        nn->ptrToNextNode=NULL;
        ptrToLastNodeTwo->ptrToNextNode=nn;
        ptrToLastNodeTwo=nn;
    }
}

struct node * mergeTwoLinkedLists(struct node * &ptrOne, struct node * &ptrTwo){
    struct node * thirdPtr=NULL;
    struct node * newLast=NULL;

    if(ptrOne->data<ptrTwo->data){
        thirdPtr=ptrOne;
        newLast=ptrOne;
        ptrOne=ptrOne->ptrToNextNode;
        newLast->ptrToNextNode=NULL;
    }
    else if(ptrTwo->data>ptrOne->data){
        thirdPtr=ptrTwo;
        newLast=ptrTwo;
        ptrTwo=ptrTwo->ptrToNextNode;
        newLast->ptrToNextNode=NULL;
    }

    while(ptrOne!=NULL && ptrTwo!=NULL){
        if(ptrOne->data<ptrTwo->data){
            newLast->ptrToNextNode=ptrOne;
            newLast=ptrOne;
            ptrOne=ptrOne->ptrToNextNode;
            newLast->ptrToNextNode=NULL;
        }
        else{
            newLast->ptrToNextNode=ptrTwo;
            newLast=ptrTwo;
            ptrTwo=ptrTwo->ptrToNextNode;
            newLast->ptrToNextNode=NULL;
        }
    }
    if(ptrOne!=NULL){
        newLast->ptrToNextNode=ptrOne;
    }
    else
    {
        newLast->ptrToNextNode=ptrTwo;
    }
    ptrOne=NULL;
    ptrTwo=NULL;
    return thirdPtr;
}


int main(){
    int arrOne[]={2,8,10,15};
    firstLinkedList(arrOne,4);
    dispLL(ptrToFirstNode);
    int arrTwo[]={4,7,12,14};
    secondLinkedList(arrTwo,4);
    dispLL(ptrToFirstNodeTwo);
    struct node * mergedLists=mergeTwoLinkedLists(ptrToFirstNode, ptrToFirstNodeTwo);
    dispLL(mergedLists);
    return 0;
}