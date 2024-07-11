# 1313:

# We are given a list nums of integers representing a list compressed with run-length encoding.
# Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  
# For each such pair, there are freq elements with value val concatenated in a sublist. Concatenate all the sublists from left to right to generate the decompressed list.
# Return the decompressed list.

# Solution: 

class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        num_length=int(len(nums)/2)
        result=[]
        j=0
        for _ in range(num_length):
            freq=nums[j]
            val=nums[j+1]
            for _ in range(freq):
                result.append(val)
            j+=2
        return result
