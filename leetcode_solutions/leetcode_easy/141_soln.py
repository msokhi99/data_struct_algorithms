# 141: 

# Given head, the head of a linked list, determine if the linked list has a cycle in it.
# There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
# Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
# Return true if there is a cycle in the linked list. Otherwise, return false.

# Solution: 

class Solution:
  def contains_cycle(self, head: ListNode) -> bool:
    slow_ptr=head
    fast_ptr=head 

    while fast_ptr and fast_ptr.next:
      fast_ptr=fast_ptr.next.next
      slow_ptr=slow_ptr.next

      if fast_ptr==slow_ptr:
        return True

    return False

# Time Complexity: O(n).
