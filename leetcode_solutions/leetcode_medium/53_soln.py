# 53: 

# Given an integer array nums, find the subarray with the largest sum, and return its sum.

# Solution: 
# Time Complexity: O(n).

class Solution:
  def max_sub(self, nums: List[int]) -> int:

    curr_max=nums[0]
    max_updated_after_loop=nums[0]

    for i in range(1,len(nums)):
      curr_max=max(nums[i],nums[i]+curr_max)
      max_updated_after_loop=max(curr_max,max_updated_after_loop)

    return max_updated_after_loop
