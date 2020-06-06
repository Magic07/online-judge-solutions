# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Node:
    def __init__(self, ln):
        self.val=ln.val
        self.ln=ln
        
    def __lt__(self, other):
        return self.val<other.val
    
    def __le__(self, other):
        return self.val<=other.val

class Solution:        
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return None
        pq=[]
        for l in lists:
            if l:
                heappush(pq, Node(l))
        if not pq:
            return None
        current=heappop(pq)
        if current.ln.next:
            heappush(pq, Node(current.ln.next))
        answer=current.ln
        it=answer
        while pq:
            current=heappop(pq)
            it.next=current.ln
            it=current.ln
            if current.ln.next:
                heappush(pq, Node(current.ln.next))
        return answer
            