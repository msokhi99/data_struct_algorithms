# Another hashing technique (Open Addressing -> Quadratic Probing). This solves the issue of primary clustering that we would have encountered with 
# linear probing. 

# Time Complexity: 

# Avg. Successfull search: -log_e(1-lambda) / lambda.
# Avg. Unseccessfull search: 1 / (1 - lambda).

class hash_quad:
  def __init__ (self, size = 10):
    self.hash_table = [None] * size

  def __hash (self, key):
    index = key % 10
    return index 

  def __quad (self, key):
    prev_index = self.__hash(key)
    i = 0
    while self.hash_table[(index + (i * i)) % 10] is not None:
      i+=1
    new_index = (index + (i * i)) % 10
    return new_index 

  def insert_element (self, key):
    index = self.__hash(key)
    if self.hash_table[index] is not None:
      new_index = self.__quad(key)
      self.hash_table[new_index] = key

    self.hash_table[index] = key

  def search_element (self, key):
    index = self.__hash(key)
    i = 0

    while self.hash_table[(index + (i*i))%10] != key and self.hash_table[(index + (i*i))%10] is not None:
      i+=1
    if self.hash_table[(index + (i*i))%10] == key:
      return (index + (i*i))%10
    else:
      return False
