# Another hashing technique. The only thing we need to take care about here is that the second hash function we have should not return 0 and must return every other index.

class double_hashing:
    def __init__ (self, size=10):
        self.hash_table=size
    
    def __hash (self, key):
        return key % 10
    
    def __hashtwo (self, key):
        return 7 - (key % 7)
    
    def __double (self):
        hash_one = self.__hash
        hash_two = self.__hashtwo
        i = 0

        while self.hash_table[(hash_one + (i * hash_two)) % 10] is not None:
            i+=1
        
        new_index = (hash_one + (i * hash_two)) % 10
        return new_index
    
    def insert_element (self, key):
        index = self.__hash
        if self.hash_table[index] is not None:
            new_index = self.__double(key=key)
            self.hash_table[new_index]=key
        
        self.hash_table[index]=key
    
    def search_element (self, key):
        index = self.__double(key=key)
        i = 0

        while self.hash_table[(index)] != key and self.hash_table[(index)] is not None:
            i+=1
        if self.hash_table[(index)] == key:
            return index
        else:
            return False
