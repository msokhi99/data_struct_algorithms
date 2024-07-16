# 2: 

# You are given two non-empty linked lists representing two non-negative integers. 
# The digits are stored in reverse order, and each of their nodes contains a single digit. 
# Add the two numbers and return the sum as a linked list.
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.

# Solution: 

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry=0
        dummy_node=ListNode()
        current=dummy_node

        p_one=l1
        p_two=l2

        while p_one or p_two:
            sum=carry 

            if p_one:
                sum+=p_one.val
                p_one=p_one.next 
            
            if p_two:
                sum+=p_two.val
                p_two=p_two.next 
            
            carry = sum // 10
            sum = sum % 10

            current.next=ListNode(sum)
            current=current.next
        
        if carry==1:
            current.next=ListNode(1)
        
        return dummy_node.next
