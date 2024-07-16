# 4: 

# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
# The overall run time complexity should be O(log (m+n)).

# Solution: 
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged_arr = []

        ptr_num_one=0
        ptr_num_two=0

        while ptr_num_one<len(nums1) and ptr_num_two<len(nums2):
            if nums1[ptr_num_one]<nums2[ptr_num_two]:
                merged_arr.append(nums1[ptr_num_one])
                ptr_num_one+=1
            else:
                merged_arr.append(nums2[ptr_num_two])
                ptr_num_two+=1
        
        merged_arr.extend(nums1[ptr_num_one:])
        merged_arr.extend(nums2[ptr_num_two:])

        total_length=len(merged_arr)

        if total_length%2==0:
            element_one=int((total_length)/2)-1
            element_two=int(math.floor((total_length+1)/2))
            result=float((merged_arr[element_one]+merged_arr[element_two])/2)
            return result
        else:
            element_one=int((math.ceil(total_length)/2))
            result=float(merged_arr[element_one])
            return result
