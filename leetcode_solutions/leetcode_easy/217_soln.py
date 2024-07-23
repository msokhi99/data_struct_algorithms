# 217: 

# Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

# Solution: 

class Solution:
  def containsDuplicates(self,nums: List[int]) -> bool:

    new_dict={}
    for num in nums:
      if num not in new_dict:
        new_dict[num]=True
      else:
        return True

    return False
