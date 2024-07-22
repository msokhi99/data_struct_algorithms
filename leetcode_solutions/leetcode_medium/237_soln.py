# 237: 

# There is a singly-linked list head and we want to delete a node node in it.
# You are given the node to be deleted node. You will not be given access to the first node of head.
# All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
# Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
# The value of the given node should not exist in the linked list.
# The number of nodes in the linked list should decrease by one.
# All the values before node should be in the same order.
# All the values after node should be in the same order.

# Solution: 

class Solution:
    def deleteNode(self, node):

      # Since, we do not have access to the head of the linked list, we will simply traverse the linked list 
      # from the give node and update the previous nodes value with the one after. In, the end we will delete
      # the last node.

      cur_node=node
      prev_node=None 

      while cur_node and cur_node.next:
        cur_node.val=cur_node.next.val
        prev_node=cur_node
        cur_node=cur_node.next

      # Delete the last node.

      prev_node.next=None

# For example, we want to delete 5 from the linked list:

# Original List: 1->2->5->4
# Modified List: 1->2->4
