# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        q=collections.deque([root])
        level=0
        while len(q)>0:
            nextQ=collections.deque([])
            evenLevel=(level%2==0)
            last=-1
            if not evenLevel:
                last=sys.maxsize
            while len(q)>0:
                node=q.popleft()
                if (node.val%2==0)==evenLevel:
                    return False
                if evenLevel and node.val<=last:
                    return False
                if not evenLevel and node.val>=last:
                    return False
                last=node.val
                if node.left:
                    nextQ.append(node.left)
                if node.right:
                    nextQ.append(node.right)
            q=nextQ
            level+=1
        return True
        