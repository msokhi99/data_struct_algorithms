# 94: 

# Given the root of a binary tree, return the inorder traversal of its nodes' values.

# Solution: 
# Time Complexity: O(n).
# Space Complexity: O(n). 

class Solution:
  def in_order_traversal(self, root:List[TreeNode])->List[int]:
    return self._recurse(root, [])

  def _recurse(self, node:TreeNode, result:List[int])->List[int]:
    if node:
      self._recurse(node.left, result)
      result.append(node.val)
      self._recurse(node.right, result)
    return result
