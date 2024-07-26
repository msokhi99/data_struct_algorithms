# A hashing technique (Chaining: using Linked Lists) to avoid collisions. This is categorized under open hashing as we are using extra space due to the linked lists.

# Analysis: 

# Suppose we have n keys (let's say 100) and the size of the hash table is 10. Then, the loading factor (lambda) is n/size = 100/10 = 10.
# This means, that we are assuming all of our 100 keys are uniformly going to be distributed across all the indices (so each index will have 10 keys).
# Hence, for an avg. successful search: T = 1 + lambda/2 and for an avg. unsuccessfull search: T = 1 + lambda.

# However, if we have keys that are (5,15,25,30,35) then all of them are going to be mapped at the same index and this is a problem. Therefore, we should 
# choose a hash function such that we dont have any of these problems.

from node_class import Node

class Hash_Table:
  def __init__ (self, size = 10):
    self.hash_table = [None] * size

  def __hash (self, key):
    returned_index = key % 10
    return returned_index

  def insert_element (self, key):
    index = self.__hash(key)
    if self.hash_table[index] is None:
      self.hash_table[index] = key
    else:
      new_node = Node(key)
      curr_ptr = self.hash_table[index]
      prev_ptr = None

      while curr_ptr and curr_ptr.key < key:
        prev_ptr = curr_ptr
        curr_ptr = curr_ptr.next

      if prev_ptr is None:
        new_node.next = self.hash_table[index]
        self.hash_table[index] = new_node
      else:
        new_node.next = curr_ptr
        prev_ptr.next = new_node

  def search_element (self, key):
    index = self.__hash(key)

    temp_ptr = self.hash_table[index]
    while temp_ptr:
      if temp_ptr.key == key:
        return True

    return False

  def delete_element (self, key):
    index = self.__hash(key)

    key_found = self.search_element(key)
    if key_found is False:
      return None
    else:
      temp_ptr = self.hash_table[index]
      if temp_ptr.next is None:
        deleted_node = temp_ptr.key
        self.hash_table[index] = None
        return deleted_node 
      else:
        prev_ptr = None
        while temp_ptr:
          if temp_ptr.key == key:
            deleted_node = temp_ptr.key
            prev_ptr.next = temp_ptr.next
            temp_ptr.next = None
            return deleted_node

          prev_ptr = temp_ptr
          temp_ptr = temp_ptr.next

  def print_elements (self, index):
    if index<0 or index>9:
      return False 
    else:
      temp_ptr = self.hash_table[index]
      while temp_ptr.next:
        print(temp_ptr.key)
        temp_ptr=temp_ptr.next
