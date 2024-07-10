from node_class import Node

class LinkedList:
    def __init__(self,value):
        new_node=Node(value=value)
        self.head=new_node
        self.tail=new_node
        self.length=1
    
    def print_list(self):
        if self.length==0:
            return print("LL is empty.")
        else:
            temp_ptr=self.head
            while temp_ptr is not None:
                print(temp_ptr.value, end=" ")
                temp_ptr=temp_ptr.next
    
    '''
    Big O for print_list method is O(n).
    '''
    
    def append(self,value):
        new_node=Node(value=value)
        if self.head is None:
            self.head=new_node
            self.tail=new_node
        else:
            self.tail.next=new_node
            self.tail=new_node
        self.length+=1
        return True
    
    '''
    Big O for append method is O(1).
    '''

    def pop(self):
        if self.length==0:
            return None
        elif self.length==1:
            removed_element=self.tail
            self.head=None
            self.tail=None
            self.length-=1
            return removed_element
        else:
            temp_ptr=self.head
            while temp_ptr is not None and temp_ptr.next != self.tail:
                temp_ptr=temp_ptr.next
            removed_element=self.tail
            self.tail=temp_ptr
            self.tail.next=None
            self.length-=1
            return removed_element
    '''
    Big O for pop method is O(n).
    '''

    def prepend(self,value):
        new_node=Node(value=value)
        if self.length==0:
            self.head=new_node
            self.tail=new_node
        else:
            new_node.next=self.head
            self.head=new_node
        self.length+=1
        return True
    
    '''
    Big O for prepend method is O(1).
    '''

    def pop_first(self):
        if self.length==0:
            return None
        elif self.length==1:
            removed_element=self.head
            self.head=None
            self.tail=None
            self.length-=1
            return removed_element
        else:
            removed_element=self.head
            temp_ptr=self.head
            self.head=self.head.next
            temp_ptr.next=None
            self.length-=1
            return removed_element
    
    '''
    Big O for pop_first method is O(1).
    '''

    def get(self,index):
        if self.length==0:
            return None
        elif index>self.length-1 or index<0:
            return None
        else:
            temp_ptr=self.head
            for _ in range(index):
                temp_ptr=temp_ptr.next
            return temp_ptr
    
    '''
    Big O for get method is O(n).
    '''

    def set_value(self,index,value):
        node_at_index=self.get(index=index)
        if node_at_index is not None:
            node_at_index.value=value
            return True
        else:
            return False
    
    '''
    Big O for set_value method is O(n).
    '''

    def insert(self,index,value):
        if index<0 or index>self.length:
            return False
        elif index==0:
            self.prepend(value=value)
        elif index==self.length:
            self.append(value=value)
        else:
            new_node=Node(value=value)
            temp_ptr=self.get(index=index-1)
            new_node.next=temp_ptr.next
            temp_ptr.next=new_node
            self.length+=1
            return True

    '''
    Big O for the insert_method is O(n).
    '''

    def remove(self,index):
        if index<0 or index>self.length-1:
            return None
        elif index==0:
            removed_node=self.pop_first()
            return removed_node
        elif index==self.length-1:
            removed_node=self.pop()
            return removed_node
        else:
            removed_node=self.get(index=index)
            node_before_removed_node=self.get(index=index-1)
            node_before_removed_node.next=removed_node.next
            removed_node.next=None
            self.length-=1
            return removed_node
        
    '''
    Big O for remove method is O(n).
    '''

    def reverse(self):
        if self.length==0 or self.length==1:
            return None
        else:
            temp_ptr=self.head
            self.head=self.tail
            self.tail=temp_ptr
            ptr_before_temp=None
            ptr_after_temp=temp_ptr.next
            for _ in range(self.length):
                ptr_after_temp=temp_ptr.next
                temp_ptr.next=ptr_before_temp
                ptr_before_temp=temp_ptr
                temp_ptr=ptr_after_temp
            return True
    
    '''
    Big O for reverse method id O(n).
    '''

