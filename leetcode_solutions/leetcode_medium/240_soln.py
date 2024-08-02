# 240: 

# Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

# Integers in each row are sorted in ascending from left to right.
# Integers in each column are sorted in ascending from top to bottom.

# Solution: 
# Time Complexity: O(log(m*n)).
# Space Complexity: O(1).

class Solution:
  def search_second(self,matrix:List[List[int]],target:int)->bool:
    matrix_rows=len(matrix)
    matrix_cols=len(matrix[0])
    left_index=matrix_rows-1
    right_index=0

    while left_index>=0 and right_index<matrix_cols:
      if matrix[left_index][right_index]==target:
        return True
      elif matrix[left_index][right_index]>target:
        left_index-=1
      else:
        right_index+=1

    return False
