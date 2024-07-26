# Hashing Technique (Open Addressing -> Linear Probing). This does not consume any extra space. However, we need to make sure that the loading factor (lambda)
# is <= 0.5. Because of this the drawback is that half of the hash table is left vacant. Also, deleting in a hash table using linear probing is extremely 
# difficult and not efficient. If you really want to delete, we can set a flag or use the rehashing technique (However, not recommended). Another drawback is that
# this problem may cause clustering of elements (primary clustering) which will be inefficient for searching.

# Time Complexities: 

# Avg. Successfull search: 1/lambda ln(1 - /(1 - lambda)).
# Avg. Unsuccessfull search: 1/(1 - lambda).

class hash_table_linear_probing:
  def __init__ (self, size = 10):
    self.hash_table = [None] * size

  def __hash (self, key):
    index = key % 10
    return index 

  def __linear (self, key):
    prev_index = self.__hash(key)
    i = 0
    while self.hash_table[(prev_index + i) % 10] is not None:
      i+=1
    new_index = (prev_index + i) % 10
    return new_index 

  def insert_element (self, key):
    index = self.__hash(key)
    if self.hash_table[index] is not None:
      new_index = self.__linear(key)
      self.hash_table[new_index] = key

    self.hash_table[index] = key

  def search_element (self, key):
    index = self.__hash(key)
    i = 0

    while self.hash_table[(index+i) % 10] != key and self.hash_table[(index+i) % 10] is not None:
      i+=1
    if self.hash_table[(index+i) % 10] == key:
      return (index + i) % 10
    else:
      return False
