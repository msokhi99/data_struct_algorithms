# 82: 

# Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
# Return the linked list sorted as well.

# Solution: 

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:

      dummy_node=ListNode()
      dummy_node.next=head

      p=dummy_node
      q=head

      while q and q.next:
        if q.val == q.next.val:
          while q.next and q.val == q.next.val:
            q=q.next
          p.next=q.next
        else:
          p=p.next

      q=q.next

      return dummy_node.next
          
