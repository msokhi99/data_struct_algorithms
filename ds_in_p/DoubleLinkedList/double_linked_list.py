from node import Node

class Double_Linked_List:
    def __init__(self,value):
        new_node=Node(value=value)
        self.head=new_node
        self.tail=new_node
        self.length=1
    
    def print_list(self):
        ptr_to_head=self.head
        while ptr_to_head:
            print(ptr_to_head.value)
            ptr_to_head=ptr_to_head.next
    
    '''
    Big O for print_list is O(n).
    '''
    
    def append(self,value):
        new_node=Node(value=value)
        if self.length==0:
            self.head=new_node
            self.tail=new_node
            self.length+=1
            return True
        else:
            ptr_to_tail=self.tail
            ptr_to_tail.next=new_node
            new_node.prev=ptr_to_tail
            self.tail=new_node
            self.length+=1
            return True
    
    '''
    Big O for append is O(n).
    '''

    def pop(self):
        if self.length==0:
            return False
        elif self.length==1:
            self.head=None
            self.tail=None
            self.length-=1
            return True
        else:
            ptr_to_tail=self.tail
            self.tail=self.tail.prev
            self.tail.next=None
            ptr_to_tail.prev=None
            self.length-=1
            return True
    
    '''
    Big O for pop method is O(1).
    '''

    def prepend(self,value):
        new_node=Node(value=value)
        if self.length==0:
            self.head=new_node
            self.tail=new_node
            self.length+=1
            return True
        else:
            ptr_to_head=self.head
            self.head.prev=new_node
            self.head=self.head.prev
            self.head.next=ptr_to_head
            self.length+=1
            return True
    
    '''
    Big O for prepend method is O(1).
    '''

    def pop_first(self):
        if self.length==0:
            return None
        elif self.length==1:
            self.head=None
            self.tail=None
            self.length-=1
            return True
        else:
            ptr_to_head=self.head
            self.head=self.head.next
            self.head.prev=None
            ptr_to_head.next=None
            self.length-=1
            return True
    
    '''
    Big O for the pop_first method is O(1).
    '''

    def get(self,index):
        if index<0 or index>=self.length:
            return None
        if index<self.length/int(2):
            ptr_to_head=self.head
            for _ in range(index):
                ptr_to_head=ptr_to_head.next
            return ptr_to_head
        elif index>=self.length/int(2):
            ptr_to_tail=self.tail
            for _ in range(self.length-1,index,-1):
                ptr_to_tail=ptr_to_tail.prev
            return ptr_to_tail

    '''
    Big O for the get method is O(n).
    '''

    def set(self,index,value):
        ret_node=self.get(index=index)
        if ret_node is not None:
            ret_node.val=value
            return True
        else:
            return False
        
    '''
    Big O for the set method is O(n).
    '''

    def insert(self,index,value):
        new_node=Node(value=value)
        if index<0 or index>self.length:
            return None
        else:
            if index==0:
                return self.prepend(value=value)
            elif index==self.length:
                return self.append(value=value)
            else:
                new_node=Node(value=value)
                before=self.get(index=index-1)
                after=before.next
                new_node.prev=before
                new_node.next=after
                after.prev=new_node
                before.next=new_node
                self.length+=1
                return True

    '''
    Big O for insert method is O(n).
    '''

    def remove(self,index):
        if index<0 or index>=self.length:
            return False
        else:
            if index==0:
                return self.pop_first()
            elif index==self.length-1:
                return self.pop()
            else:
                rem_index_ptr=self.get(index=index)
                before=rem_index_ptr.prev
                after=rem_index_ptr.next
                before.next=rem_index_ptr.next
                after.prev=rem_index_ptr.prev
                rem_index_ptr.next=None
                rem_index_ptr.prev=None
                self.length-=1
                return True
    
    '''
    Big O for remove method is O(n).
    '''
