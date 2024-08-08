# 872: 

# Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

# Solution: 
# Time Complexity: O(n).
# Space Complexity: O(n).

class Solution: 
  def similar_leaf(self, root1:List[TreeNode], root2:List[TreeNode])->bool:
    res_one=self.check_leaf(root1)
    res_two=self.check_leaf(root2)
    return res_one==res_two
    
  def check_leaf(self, root)->List[int]:
    result=[]
    stack=[]

    if root:
      stack.append(root)

    while stack:
      node=stack.pop()
      if node:
        if not node.left and not node.right:
          result.append(node.val)
        stack.append(node.right)
        stack.append(node.left)

    return result
