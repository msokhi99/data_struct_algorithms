# 61: 

# Given the head of a linked list, rotate the list to the right by k places.

# Solution: 

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

      # If head is empty then we will just return the head.
      if not head:
        return head 

      # Otherwise, first we will find the length of the enitre linked list. During the process, we will 
      # end up with a pointer pointing at the last element of the linked list -> Tail.
      length_ll=1
      tail_ptr=head 

      while tail.next:
        tail=tail.next
        length+=1

      # If k is a multiple of the total length, we will simply just return the head.
      k=k%length_ll
      if k==0:
        return head 

      # Now, we will go to the pivot node and break the link and perform the rotation.
      cur=head
      for _ in range(length-k-1):
        curr=curr.next

      new_head=curr.next
      curr.next=None
      tail.next=head
      return new_head


# For example with k=2:

# Original LL: 1->2->3->4->5
# Modified LL: 4->5->1->2->3
