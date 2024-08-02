# 4: 

# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
# The overall run time complexity should be O(log (m+n)).

# Solution 1 (Brute Force):
# Time Complexity: O(m+n)
# Space Complexity: O(m+n)

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

# Solution 2: Optimal
# Time Complexity: O(log(m+n))
# Space Complexity: O(1)

class Solution:
    def median_arr(self,nums1:List[int],nums2:List[int])->float:
        A=nums1
        B=nums2
        total_len=len(nums1)+len(nums2)
        half_len=total_len//2

        if len(B) < len(A):
            A=B
            B=A

        left_in=0
        right_in=len(A)-1

        while True:
            mid_a=(left_in+right_in)//2
            mid_b=half_len-mid_a-2

            a_left=A[mid_a] if mid_a>=0 else float("-infinity")
            a_right=A[mid_a+1] if (mid_a+1)<len(A) else float("infinity")
            b_left=B[mid_b] if mid_b>=0 else float("-infinity")
            b_right=B[mid_b+1] if (mid_b+1)<len(B) else float("infinity")

            if a_right<=b_left and b_right<=a_left:
                if total_len % 2:
                    return min(a_right,b_right)
                else:
                    return ((max(a_left,b_left)+min(a_right,b_right))/2)
            elif a_left>b_right:
                right_in=mid_a-1
            else:
                left_in=mid_a+1
