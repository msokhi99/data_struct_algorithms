# Question: 

# Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

# Solution: 

class Solution:
  def duplicate_num(self, nums: List[int]) -> bool:
    hash_table={}

    for num in nums:
      if num not in hash_table:
        hash_table[num]=True
      else:
        return True

    return False 

# Time Complexity: 

# O(n + 1) -> O(n).

# Space Complexity: 

# O(n).
