#include<iostream> 

struct node{
    int data;
    struct node *next;
}*first=NULL;

void create(int A[], int elements){
    struct node * t, * last; 
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1; i<elements; i++){
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct node *p){
    while(p!=NULL){
        std::cout<<p->data<<" ";
        p=p->next;
    }
    std::cout<<"\n";
}

/*
Displaying linked list using a recursive function:
The following function will print the elements in an 
ascending order. If we want the elements to be printed 
in a descending order we can call the function first and 
then print the data.

void displayRecursive(struct node *p){
    if(p!=NULL){
        displayRecursive(p->next);
        std::cout<<p->data<<" ";
    }
}

Everytime we are traversing a linked list "ONCE", it will 
take O(n) time and O(n) space. For n elements in a linked list
it will make (n+1) activation records. There is no difference 
between the while loop and calling it recursively.
*/
void displayRecursive(struct node *p){
    if(p!=NULL){
        std::cout<<p->data<<" ";
        displayRecursive(p->next);
    }
}

int countNodes(struct node * p){
    if(p!=NULL){
        return countNodes(p->next)+1;
    }
    else{
        return 0;
    }
}

/*
A while loop for counting. This is cheaper than counting it
recursively. 

int count=0;
while(p!=NULL){
    count++;
    p=p->next;
}
std::cout<<count<<"\n";

This takes O(1) space and recursion version takes O(n) space.
*/

int addElements(struct node * p){
    int sum=0;
    while(p!=NULL){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int addElementsR(struct node * p){
    if(p!=NULL){
        return addElementsR(p->next)+p->data;
    }
    else{
        return 0;
    }
}

int maxElement(struct node * p){
    int max=0;
    while(p!=NULL){
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int minElement(struct node * p){
    int min=p->data;
    p=p->next;
    while(p!=NULL){
        if(p->data<min){
            min=p->data;
        }
        p=p->next;
    }
    return min;
}

/*
We cannot perform binary search on linked list. We can only 
perform linear search.
*/

node * linearSearchLL(struct node * p, int key){
    while(p!=NULL){
        if(p->data==key){
            return p;
        }
        else{
            p=p->next;
        }
    }
    return NULL;
}

node * fasterLinearSearch(struct node * p, int key){
    node * q = NULL;
    while(p!=NULL){
        if(p->data==key){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        else{
            q=p;
            p=p->next;
        }
    }
    return NULL;
}

void insertNodeBeforeFirstNode(struct node * p){
    node * t = new node;
    t->data=50;
    t->next=first;
    first=t;
}

void insertNodeAfter(struct node * p, int position){
    node * t=new node;
    t->data=60;
    node * a=new node;
    a=first;
    for(int i=0; i<position-1; i++){
        a=a->next;
    }
    t->next=a->next;
    a=t;
}

int main()
{   
    int A[]={5,4,3,9,2};
    int key;
    create(A, 5);
    display(first);
    displayRecursive(first);
    std::cout<<"\n";
    int totalNodes=countNodes(first);
    std::cout<<totalNodes<<"\n";
    int totalSum=addElements(first);
    std::cout<<totalSum<<"\n";
    int totalSumR=addElementsR(first);
    std::cout<<totalSumR<<"\n";
    int maxNode=maxElement(first);
    std::cout<<maxNode<<"\n";
    int minNode=minElement(first);
    std::cout<<minNode<<"\n";
    /*std::cout<<linearSearchLL(first,key)<<"\n";
    std::cout<<fasterLinearSearch(first, key)<<"\n";*/
    insertNodeBeforeFirstNode(first);
    display(first);
    return 0;
}


#include<iostream>

struct node;
void insert(struct node * ptr, int val);
void indexInsert(struct node * ptr, int val, int index);
void sortedInsert(struct node * ptr, int val);
void deleteNode(struct node * ptr);
void deleteNodeIndex(struct node * ptr, int index);
bool isSorted(struct node * ptr);
int countNodes(struct node * ptr);
void dispLL(struct node * ptr);

struct node{
	int data;
	struct node * ptrToNextNode;
}*ptrToFirstNode=NULL, *ptrToLastNode=NULL;

void insert(struct node * ptr, int val){
	struct node * nn=new node;
	nn->data=val;
	nn->ptrToNextNode=NULL;

	if(ptrToFirstNode==NULL){
		nn->ptrToNextNode=ptrToFirstNode;
		ptrToFirstNode=nn;
		ptrToLastNode=nn;
	}
	else{
		ptrToLastNode->ptrToNextNode=nn;
		ptrToLastNode=nn;
	}
}

int countNodes(struct node * ptr){
	int count=0;
	while(ptr!=NULL){
		count++;
		ptr=ptr->ptrToNextNode;
	}
	return count;
}

void dispLL(struct node * ptr){
	std::cout<<"LINKED LIST\n";
	while(ptr!=NULL){
		std::cout<<ptr->data<<" ";
		ptr=ptr->ptrToNextNode;
	}
	std::cout<<"\n";
}

void indexInsert(struct node * ptr, int val, int index){
	struct node * nn=new node;
	nn->data=val;
	nn->ptrToNextNode=NULL;

	if(index==0){
		nn->ptrToNextNode=ptrToFirstNode;
		ptrToFirstNode=nn;
	}
	else{
		for(int i=0; i<index-1; i++){
			ptr=ptr->ptrToNextNode;
		}
		nn->ptrToNextNode=ptr->ptrToNextNode;
		ptr->ptrToNextNode=nn;
	}
}

void sortedInsert(struct node * ptr, int val){
	struct node * nn=new node;
	struct node * qq=NULL;
	nn->data=val;
	nn->ptrToNextNode=NULL;
	if(ptrToFirstNode==NULL){
		nn->ptrToNextNode=ptrToFirstNode;
		ptrToFirstNode=nn;
	}
	else{
		while(ptr->data<val){
		qq=ptr;
		ptr=ptr->ptrToNextNode;
	}
	if(ptr==ptrToFirstNode){
		nn->ptrToNextNode=ptrToFirstNode;
		ptrToFirstNode=nn;
	}
	else{
		nn->ptrToNextNode=qq->ptrToNextNode;
		qq->ptrToNextNode=nn;
	}
	}
}

void deleteNode(struct node * ptr){
	ptr=ptrToFirstNode;
	ptrToFirstNode=ptrToFirstNode->ptrToNextNode;
	delete[] ptr;
}

void deleteNodeIndex(struct node * ptr, int index){
	struct node * q=NULL;
	for(int i=0; i<index-1; i++){
		q=ptr;
		ptr=ptr->ptrToNextNode;
	}
	q->ptrToNextNode=ptr->ptrToNextNode;
	delete ptr;
}

bool isSorted(struct node * ptr){ 
	int min=INT_MIN;
	while(ptr!=NULL){
		if(ptr->data<min){
			return false;
		}
		min=ptr->data;
		ptr=ptr->ptrToNextNode;
	}
	return true;
}

int main(){
	insert(ptrToFirstNode,10);
	dispLL(ptrToFirstNode);
	insert(ptrToFirstNode,20);
	dispLL(ptrToFirstNode);
	insert(ptrToFirstNode,30);
	dispLL(ptrToFirstNode);
	insert(ptrToFirstNode,40);
	dispLL(ptrToFirstNode);
	indexInsert(ptrToFirstNode, 25, 2);
	dispLL(ptrToFirstNode);
	indexInsert(ptrToFirstNode, 5, 0);
	dispLL(ptrToFirstNode);
	sortedInsert(ptrToFirstNode,35);
	dispLL(ptrToFirstNode);
	sortedInsert(ptrToFirstNode,0);
	dispLL(ptrToFirstNode);
	insert(ptrToFirstNode,50);
	dispLL(ptrToFirstNode);
	deleteNode(ptrToFirstNode);
	dispLL(ptrToFirstNode);
	deleteNodeIndex(ptrToFirstNode,5);
	dispLL(ptrToFirstNode);
	indexInsert(ptrToFirstNode,8,0);
	dispLL(ptrToFirstNode);
	std::cout<<isSorted(ptrToFirstNode)<<"\n";
	return 0;
}