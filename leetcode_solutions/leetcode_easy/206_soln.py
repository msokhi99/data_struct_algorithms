# 206: 

# Given the head of a singly linked list, reverse the list, and return the reversed list.

# Solution: 

class Solution:
  def reverse_list(self, head: ListNode) -> ListNode:
    if head is None:
      return None

    prev_ptr=None
    curr_ptr=head
    after_ptr=curr_ptr.next

    while curr_ptr:
      after_ptr=curr_ptr.next
      curr_ptr.next=prev_ptr
      prev_ptr=curr_ptr
      curr_ptr=after_ptr

    return prev_ptr

# Time Complexity: O(n).
