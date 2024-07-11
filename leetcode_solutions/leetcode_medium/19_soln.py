# 19: 

# Given the head of a linked list, remove the nth node from the end of the list and return its head.

# Solution: 

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head.next is None or head is None:
            return None
        else:
            dummy_node=ListNode(next=head)
            curr=head
            prev=dummy_node
            for _ in range(n):
                curr=curr.next
            while curr:
                prev=prev.next
                curr=curr.next
            prev.next=prev.next.next
            return dummy_node.next
