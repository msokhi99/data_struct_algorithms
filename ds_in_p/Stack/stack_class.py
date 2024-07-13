from node_class import Node

class Stack:
    def __init__(self,value):
        new_node=Node(value=value)
        self.top=new_node
        self.height=1
    
    def print_stack_contents(self):
        ptr_to_top=self.top
        while ptr_to_top:
            print(ptr_to_top.value)
            ptr_to_top=ptr_to_top.next
    
    def push(self,value):
        new_node=Node(value=value)
        new_node.next=self.top
        self.top=new_node
        self.height+=1
        return True
    
    def pop(self):
        if self.height==0:
            return False 
        else:
            val_popped=self.top
            self.top=self.top.next
            self.height-=1
            return val_popped