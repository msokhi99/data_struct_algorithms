# Question: 

# Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.
# You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
# Return the answer with the smaller index first.

# Solution: 

class Solution:
  def two_sum(self, nums: List[int], target: int] -> List[int]:
    hash_table={}
    result=[]

    for index, num in nums:
      comp=target-num
      if comp not in hash_table:
        hash_table[num]=index
      else:
        result.append(hash_table[comp])
        result.append(index)

    return result 

# Time Complexity: O(n + 1) -> O(n).
# Space Complexity: O(n).
