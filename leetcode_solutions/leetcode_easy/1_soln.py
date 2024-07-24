# 1: 

# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.

# Solution: 

class Solution:
  def two_sum(self, nums: List[int], target=int) -> List[int]:
    result=[]

    # Brute Force Approach: 
    # Time Complexity: O(n^2)

    for i in range(len(nums)):
      for j in range(i+1,len(nums)):
        sum=nums[i]+nums[j]
        if sum==target:
          result.append(i)
          result.append(j)

    return result 

# Second Method using Sorting:
# Time Complexity: O(n*log(n))

class Solution:
  def two_sum(self, nums: List[int], target=int) -> List[int]:
    sorted_nums=sorted(nums)
    result=[]

    left_ptr=0
    right_ptr=len(nums)-1

    while left_ptr<right_ptr:
      temp_sum=sorted_nums[left_ptr] + sorted_nums[right_ptr]
      if temp_sum==target:
        result.append(nums.index(sorted_nums[left_ptr]))
        result.append(nums.index(sorted_nums[right_ptr]))
        break
      elif temp_sum>target:
        right_ptr-=1
      elif temp_sum<target:
        left_ptr+=1

    return result

# Third Method using Hash Table (Best Method):
# Time Complexity: O(n + 1) -> O(n)

class Solution:
  def two_sum(self, nums: List[int], target=int) -> List[int]:
    hash_table={}
    result=[]

    for index, num in nums:
      comp=target-num
      if comp not in hash_table:
        hash_table[num]=index
      else:
        result.append(index)
        result.append(hash_table[comp])

  return result
