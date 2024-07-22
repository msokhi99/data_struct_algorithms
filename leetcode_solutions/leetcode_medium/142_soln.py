# 142: 

# Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
# There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
# Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
# Do not modify the linked list.

# Solution: 

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:

      # First, we will use the cycle checking algo. to see if our linked list contains a loop.
      fast_ptr=head
      slow_ptr=head 

      while fast_ptr and fast_ptr.next:
        fast_ptr=fast_ptr.next.next
        slow_ptr=slow_ptr.next 

      # If, there is a loop, then we will bring the fast pointer back to the head position and 
      # now we will increment both the fast and the slow pointer equally. 

      if slow_ptr==fast_ptr:
        fast_ptr=head
        while fast_ptr != slow_ptr:
          fast_ptr=fast_ptr.next
          slow_ptr=slow_ptr.next
        return slow_ptr

      return None


# Exceeding time limit on Leetcode.
