# 15:

# Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
# Notice that the solution set must not contain duplicate triplets.

# Solution: 
# Time Complexity: O(n^2)

class Solution:
  def three_sum(self,nums: List[int])->List[List[int]]:
    sorted_nums=sorted(nums)
    result=set()

    for i in range(len(nums)-2):
      left_ptr=i+1
      right_ptr=len(nums)-1

      while left_ptr<right_ptr:
        total_sum=sorted_nums[i]+sorted_nums[left_ptr]+sorted_nums[right_ptr]
        if total_sum==0:
          result.add(sorted_nums[i],sorted_nums[left_ptr],sorted_nums[right_ptr])
          left_ptr+=1
          right_ptr-=1
        elif total_sum>0:
          right_ptr-=1
        elif total_sum<0:
          left_ptr+=1

      return list(result)
