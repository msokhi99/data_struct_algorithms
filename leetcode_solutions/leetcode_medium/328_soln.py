# 328: 

# Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
# The first node is considered odd, and the second node is even, and so on.
# Note that the relative order inside both the even and odd groups should remain as it was in the input.
# You must solve the problem in O(1) extra space complexity and O(n) time complexity.

class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        even_node_list=ListNode()
        odd_node_list=ListNode()
        even=even_node_list
        odd=odd_node_list 

        p=head
        c=p
        i=0

        while p:
            if i%2==0:
                p=p.next
                c.next=None
                even.next=c
                even=even.next
                c=p
            elif i%2==1:
                p=p.next
                c.next=None
                odd.next=c
                odd=odd.next
                c=p
            i+=1

        even.next=odd_node_list.next
        return even_node_list.next
