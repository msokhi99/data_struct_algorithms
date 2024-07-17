# 3217: 

# You are given an array of integers nums and the head of a linked list. 
# Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

# Solution: 

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:

      # Pushing nums into a set as otherwise, it exceeds the time limit. 

      nums=set(nums)
      dummy_node=ListNode()
      dummy_node.next=head
      p=head
      q=dummy_node

      while p:
        p_next=p.next
        if p.val in nums:
          q.next=p_next
          p_next=None
          p=p_next
        else:
          q=p
          p=p_next

      return dummy_node.next
