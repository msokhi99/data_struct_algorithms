class StackList:
    def __init__(self):
        self.stack_list=[]
        self.top_element=None
    
    def push(self,value):
        self.stack_list.append(value)
        self.top_element=value
    
    def pop(self):
        status=self.is_empty()
        if status==False:
            element_popped=self.stack_list[-1]
            self.stack_list.remove(self.stack_list[-1])
            if len(self.stack_list)==1:
                self.top_element=None
            else:
                self.top_element=self.stack_list[-1]
            return element_popped

    def is_empty(self):
        if len(self.stack_list)==0:
            return True
        else:
            return False
    
    def peek(self,index):
        status=self.is_empty()
        if status==False:
            if index>=0 and index<len(self.stack_list):
                return self.stack_list[index]
            else:
                return False
    
    def stack_top(self):
        return self.top_element
    
