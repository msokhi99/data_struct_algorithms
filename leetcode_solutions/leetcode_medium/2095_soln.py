# 2095 

# You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
# The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

# Solution: 

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy_node=ListNode()
        dummy_node.next=head
        p=dummy_node
        c=head
        fast=head

        while fast and fast.next:
            p=c
            c=c.next
            fast=fast.next.next

        c_next=c.next
        p.next=c_next
        c.next=None

        return dummy_node.next
