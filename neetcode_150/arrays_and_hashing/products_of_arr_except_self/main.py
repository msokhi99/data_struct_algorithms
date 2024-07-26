# 238: 

# Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
# You must write an algorithm that runs in O(n) time and without using the division operation.

# Solution: Brute Force Approach 
# Time Complexity: O(n^2)

class Solution:
  def product_arr(self, nums: List[int]) -> List[int]:
    result=[]
    i = 0

    while i<len(nums):
      sum=0
      for j in range(len(nums)):
        if j != i:
          sum*=nums[j]
      result.append(sum)
      i+=1

    return result


# Solution: Optimal
# Time Complexity: O(n).
# Space Complexity: O(n).

class Solution:
  def product_arr(self, nums: List[int]) -> List[int]:
    left_prod=[None]*len(nums)
    right_prod=[None]*len(nums)
    result=[None]*len(nums)

    left_prod[0]=1
    for i in range(len(nums)):
      left_prod=left_prod[i-1]*nums[i-1]

    right_prod[len(nums)-1]=1
    for i in range(len(nums)-2,-1,-1):
      right_prod=right_prod[i+1]*right_prod[i+1]

    for i in range(len(nums)):
      result[i]=left_prod[i]*right_prod[i]

    return result
