# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        leafs={}
        pairs=[0]
        def findLeafs(root):
            if root==None:
                return [0]*distance
            if root.left==None and root.right==None:
                answer=[0]*distance
                answer[0]=1
                leafs[root.val]=answer
                return answer
            left=findLeafs(root.left)
            right=findLeafs(root.right)
            answer=[0]*distance
            for i in range(1, distance):
                answer[i]=left[i-1]+right[i-1]
                pairs[0]+=left[i-1]*sum(right[:distance-i])
            leafs[root.val]=answer
            return answer
        findLeafs(root)
        return pairs[0]