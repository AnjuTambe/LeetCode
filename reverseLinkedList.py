class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        prev = None
        curr = head
        while curr : 
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next

        return prev    