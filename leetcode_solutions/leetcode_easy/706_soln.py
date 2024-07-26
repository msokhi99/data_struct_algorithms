# 706:

# Design a HashMap without using any built-in hash table libraries.

# Implement the MyHashMap class:
# MyHashMap() initializes the object with an empty map.
# void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
# int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
# void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

# Solution: 

class hash_map:
  def __init__ (self, size=1000):
    self.hash_map=[[] for i in range(size)]

  def __hash (self, key):
    return key % 1000

  def put (self, key, value):
    index = self.__hash(key)

    for index, k in enumerate(self.hash_table[index]):
      if k[0]==key:
        self.hash_table[index][i][0]=value

    self.hash_table[index].append([key,value])

  def get (self, key):
    index = self.__hash(key)

    for k in self.hash_table[index]:
      if k[0]==key:
        return k[1]

    return -1

  def remove (self, key):
    index = self.__hash(key)

    for k in self.hash_table[index]:
      if k[0]==key:
        self.hash_table[index].remove(k)
