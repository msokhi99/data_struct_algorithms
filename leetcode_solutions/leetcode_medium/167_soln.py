# 167: 

# Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
# Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
# Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
# The tests are generated such that there is exactly one solution. You may not use the same element twice.
# Your solution must use only constant extra space.

# Solution:
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
  def two_sum(self,nums:List[int])->List[int]:
    left_ptr=0
    right_ptr=len(nums)-1

    while left_ptr<right_ptr:
      total_sum=nums[left_ptr]+nums[right_ptr]

      if total_sum>target:
        right_ptr-=1
      elif total_sum<target:
        left_ptr+=1
      elif total_sum==target:
        return [left+1,right+1]
