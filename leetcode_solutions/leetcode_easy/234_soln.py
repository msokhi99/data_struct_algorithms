# 234: 

# Given the head of a singly linked list, return true if it is a palindrome
# or false otherwise.

# Solution: 

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
      fast_ptr=head
      slow_ptr=head

      while fast_ptr and fast_ptr.next:
        fast_ptr=fast_ptr.next.next
        slow_ptr=slow_ptr.next 

      prev_node=None
      while slow_ptr:
        slow_ptr_next=slow_ptr.next
        slow_ptr.next=prev_node
        prev_node=slow_ptr
        slow_ptr=slow_ptr_next

      left_ptr=head
      right_ptr=prev_node

      while right_ptr:
        if left_ptr.val!=right_ptr.val:
          return False
        left_ptr=left_ptr.next
        right_ptr=right_ptr.next
      return True
