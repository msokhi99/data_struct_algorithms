# Question:

# You are given an m x n integer matrix matrix with the following two properties:

# Each row is sorted in non-decreasing order.
# The first integer of each row is greater than the last integer of the previous row.
# Given an integer target, return true if target is in matrix or false otherwise.

# You must write a solution in O(log(m * n)) time complexity.

# Solution:
# Time Complexity: O(log(n*m)).
# Space Complexity: O(1).

class Solution:
  def search_matrix(self,matrix:List[List[int]])->bool:
    mat_rows=len(matrix)
    mat_cols=len(matrix[0])
    top_row=0
    bottom_row=mat_rows-1

    while top_row<=bottom_row:
      middle_row=(top_row+bottom_row)//2
      if target>matrix[middle_row][-1]:
        top_row=middle_row+1
      elif target<matrix[middle_row][0]:
        bottom_row=middle_row-1
      else:
        break

    if not (top_row<=bottom_row):
      return False

    left_ptr=0
    right_ptr=mat_cols-1
    row_to_search=(top_row+bottom_row)//2

    while left_ptr<=right_ptr:
      middle_point=(left_ptr+right_ptr)//2
      if matrix[row_to_search][middle_point]==target:
        return True
      elif matrix[row_to_search][middle_point]>target:
        right_ptr=middle_point-1
      else:
        left_ptr=middle_point+1

    return False
