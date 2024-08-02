# Question:

# Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

# Implement the TimeMap class:

# TimeMap() Initializes the object of the data structure.
# void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
# String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

# Solution: 
# Time Complexity: O(log(n)).
# Space Complexity: O(n).

class TimeMap:
  def __init__(self):
    self.store={}
  def set(self,key,value,timestamp):
    if key not in self.store:
      self.store[key]=[]
    self.store[key].append([value,timestamp])
  def get(self,key,timestamp):
    key_values=self.store.get(key,[])
    result=""
    left_in=0
    right_in=len(key_values)-1

    while left_in<=right_in:
      middle_in=(left_in+right_in)//2
      if self.store[key][middle_in][1]<=timestamp:
        result=self.store[key][middle_in][0]
        left_in=middle_in+1
      else:
        right_in=middle_in-1

    return result
