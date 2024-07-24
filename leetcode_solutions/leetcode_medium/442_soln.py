# 442: 

# Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
# You must write an algorithm that runs in O(n) time and uses only constant extra space.

# Solution 1: 

class Solution:
  def containsDups(self, nums: List[int]) -> List[int]:
    new_dict={}
    duplicate_elements=[]

    for num in nums:
      if num not in new_dict:
        new_dict[num]=True
      else:
        duplicate_elements.append(num)

    return duplicate_elements

# Time Complexity: O(n).
# Space Complexity: O(n).

# Solution 2: (As required):

class Solution:
  def containsDups(self, nums: List[int]) -> List[int]:
    result=[]

    for num in nums:
      index_to_check=abs(num)-1

      if nums[index_to_check]<0:
        result.append(abs(num))
      else:
        nums[index_to_check] = -nums[index_to_check]

    return result

# Time Complexity: O(n).
# Space Complexity: O(1).
