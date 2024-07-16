# 3194:

# You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.
# You repeat the following procedure n / 2 times:
# Remove the smallest element, minElement, and the largest element maxElement, from nums.
# Add (minElement + maxElement) / 2 to averages.
# Return the minimum element in averages.

# Solution: 

class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        averages=[]
        
        while nums:
            max_num=max(nums)
            min_num=min(nums)
            nums.remove(max_num)
            nums.remove(min_num)
            result=float((max_num+min_num)/2)
            averages.append(result)
        
        return min(averages)
