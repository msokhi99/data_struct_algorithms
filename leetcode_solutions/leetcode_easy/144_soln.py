# 144: 

# Given the root of a binary tree, return the preorder traversal of its nodes' values.

# Solution:
# Time Complexity: O(n).
# Space Complexity: O(n).

class Solution: 
  def pre_order_traversal(self, root:List[TreeNode]) -> List[int]:
    return self._recurse(root,[])
  def _recurse(self,node,result):
    if node:
      result.append(node.val)
      self._recurse(node.left,result)
      self._recurse(node.right,result)
    return result
