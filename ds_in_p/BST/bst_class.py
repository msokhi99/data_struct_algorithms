from node_class import Node

class BinarySearchTree:
    def __init__(self):
        self.root=None
    
    def insert(self,value):
        new_node=Node(value=value)
        if self.root is None:
            self.root=new_node
            return True
        else:
            temp_ptr=self.root
            while True:
                if new_node.value==temp_ptr.value:
                    return False
                else:
                    if new_node.value<temp_ptr.value:
                        if temp_ptr.left is None:
                            temp_ptr.left=new_node
                            return True
                        else:
                            temp_ptr=temp_ptr.left
                    else:
                        if new_node.value>temp_ptr.value:
                            if temp_ptr.right is None:
                                temp_ptr.right=new_node
                                return True
                            else:
                                temp_ptr=temp_ptr.right
    
    def contains(self,value):
        if self.root is None:
            return False
        else:
            temp_ptr=self.root
            while temp_ptr:
                if value<temp_ptr.value:
                    temp_ptr=temp_ptr.left
                elif value>temp_ptr.value:
                    temp_ptr=temp_ptr.right
                elif value==temp_ptr.value:
                    return True
            
            return False


