# 86: 

# Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
# You should preserve the original relative order of the nodes in each of the two partitions.

# Solution: 

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
      low_val=ListNode()
      high_val=ListNode()
      low_tail=low_val
      high_tail=high_val

      while head:
        if head.val<val:
          low_tail.next=head
          low_tail=low_tail.next
        else:
          high_tail.next=head
          high_tail=high_tail.next
        head=head.next

      low_tail.next=high_val.next
      high_tail.next=None
      return low_val.next
