# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        root = ListNode()
        node = root
        r = 0
        while l1 is not None or l2 is not None or r != 0:
            r1 = 0 if l1 is None else l1.val
            r2 = 0 if l2 is None else l2.val
            r += r1 + r2
            
            val = r % 10
            node.next = ListNode(val)
            node = node.next
          
            l1 = None if l1 is None else l1.next
            l2 = None if l2 is None else l2.next
            r //= 10

        return root.next
