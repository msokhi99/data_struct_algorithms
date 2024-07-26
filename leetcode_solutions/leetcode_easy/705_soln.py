# 705: 

# Design a HashSet without using any built-in hash table libraries.

# Implement MyHashSet class:
# void add(key) Inserts the value key into the HashSet.
# bool contains(key) Returns whether the value key exists in the HashSet or not.
# void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

# Solution: (A very basic implementation).

class hash_set:
  def __init__ (self, size = 1000):
    self.size = [[] for i in range(size)]

  def __hash (self, key):
    return key % 1000

  def add_element (self, key):
    index = self.__hash(key)

    if key not in self.hash_table:
      self.hash_table[index].append(key)

  def remove_element (self, key):
    index = self.__hash(key)

    if key in self.hash_table[index]:
      self.hash_table[index].remove(key)
    else:
      pass

  def contains_element (self,key):
    index = self.__hash(key)

    if key in self.hash_table[index]:
      return True
    else:
      return False
