# 2816: 

# You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
# Return the head of the linked list after doubling it.

# Solution: 

# This approach exceeded memory.

class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p=head
        b=None
        a=p.next 
        while p:
            a=p.next
            p.next=b
            b=p
            p=a
        
        new_list=ListNode()
        x=new_list

        p=head 
        carry=0

        while p:
            result=0+carry
            if p:
                result+=2*p.val
            
            carry=result // 10
            result=result % 10

            x.next=ListNode(result)
            x=x.next
        
        if carry==1:
            x.next=ListNode(1)
        
        return new_list.next

# Another Approach: 

class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        new_node=ListNode()
        new_node.next=head
        p=new_node
        c=head
        head=new_node

        while c:
            mul_val=c.val*2
            carry_val=mul_val // 10
            if carry_val:
                p.val=p.val+1
                c.val=mul_val % 10
            else:
                c.val=mul_val
            
            p=c
            c=c.next
        
        if head.val>0:
            return head
        else:
            return head.next
