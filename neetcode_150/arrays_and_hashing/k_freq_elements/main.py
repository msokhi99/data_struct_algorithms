# Question:

# Given an integer array nums and an integer k, return the k most frequent elements within the array.
# The test cases are generated such that the answer is always unique.
# You may return the output in any order.

# Solution: 

class Solution:
  def freq_elements(self, nums: List[int], k: int] -> List[int]:
    hash_table={}

    for num in nums:
      hash_table[num]=1+hash_table.get(num,0)

    bucket_sort_arr=[[] for i in range(len(nums)+1)]

    for key,value in hash_table.items():
      bucket_sort_arr[value].append(key)

    result=[]

    for i in range(len(bucket_sort_arr)-1,0,-1):
      for num in bucket_sort_arr(i):
        result.append(num)
        if len(result)==k:
          return result

# Time Complexity: O(n).
