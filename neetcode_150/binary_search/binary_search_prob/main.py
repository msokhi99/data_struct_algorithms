# Question: 

# Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
# You must write an algorithm with O(log n) runtime complexity.

# Solution: 
# Time Complexity: O(log(n))
# Space Complexity: O(1)

class Solution:
  def binary_search(self,nums:List[int])->int:
    left_index=0
    right_index=len(nums)-1

    while left_index<=right_index:
      middle_point=(left_index+right_index)//2
      if nums[middle_point]==target:
        return middle_point
      elif nums[middle_point]>target:
        right_index=middle_point-1
      elif nums[middle_point]<target:
        left_index=middle_point+1

    return -1
