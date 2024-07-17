# 876: 

# Given the head of a singly linked list, return the middle node of the linked list.
# If there are two middle nodes, return the second middle node.

# Solution: 

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
  
      p=head
      q=head

      while q and q.next:
        p=p.next
        q=q.next.next

      head=p
      return head
