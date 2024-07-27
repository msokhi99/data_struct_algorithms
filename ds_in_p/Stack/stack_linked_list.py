from node_class import Node

class StackLinkedList:
    def __init__(self):
        self.top_element=None
        self.len=0
    
    def push(self,value):
        new_node=Node(value=value)
        if self.len==0:
            self.top_element=new_node   
        else:
            new_node.next=self.top_element
            self.top_element=new_node

        self.len+=1
    
    def pop(self):
        status=self.is_empty()
        if status==False:
            element_popped=self.top_element.value
            if self.len==1:
                self.top_element=None
            else:
                self.top_element=self.top_element.next
            
            self.len-=1
            return element_popped
    
    def peek(self,index):
        status=self.is_empty()
        if status==False:
            if index>=0 and index<self.len:
                temp_ptr=self.top_element
                for _ in range(index):
                    temp_ptr=temp_ptr.next
                return temp_ptr.value
    
    def is_empty(self):
        if self.len==0:
            return True
        else:
            return False
    
    def print_stack(self):
        temp_ptr=self.top_element
        while temp_ptr:
            print(temp_ptr.value)
            temp_ptr=temp_ptr.next
