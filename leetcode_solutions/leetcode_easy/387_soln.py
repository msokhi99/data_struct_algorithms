# 387: 

# Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

# Solution: 

class Solution:
  def unique_char(self, s: str) -> int:
    # We cannot do the following as then we get a key error: 
    # new_dict={}.
    # Instead we need to do: 

    new_dict=defaultdict(int)

    for letter in s:
      new_dict[letter]+=1

    for index,letter in enumerate(s):
      if new_dict[letter]==1:
        return index

    return -1
