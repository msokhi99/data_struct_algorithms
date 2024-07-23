from node_class import Node

class Queue:
    def __init__(self,value):
        new_node=Node(value=value)
        self.first=new_node
        self.last=new_node
        self.length=1
    
    def print_queue(self):
        ptr_to_first=self.first
        while ptr_to_first:
            print(ptr_to_first.value)
            ptr_to_first=ptr_to_first.next
    
    '''
    Big O for print_queue method is O(n).
    '''

    def enqueue(self,value):
        new_node=Node(value=value)
        if self.length==0:
            self.first=new_node
            self.last=new_node
            self.length+=1
            return True
        else:
            ptr_to_last=self.last
            ptr_to_last.next=new_node
            self.last=new_node
            self.length+=1
            return True
    
    '''
    Big O for enqueue method is O(1).
    '''

    def dequeue(self):
        if self.length==0:
            return False
        elif self.length==1:
            ptr_to_first=self.first
            self.first=None
            self.last=None
            self.length-=1
            return ptr_to_first
        else:
            ptr_to_first=self.first
            self.first=self.first.next
            self.length-=1
            return ptr_to_first
    
    '''
    Big O for dequeue method is O(1).
    '''
