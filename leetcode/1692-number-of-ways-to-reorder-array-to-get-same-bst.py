class TreeNode:
    def __init__(self,val=0):
        self.val=val 
        self.left=None
        self.right=None
        self.numOfNodes=1
        self.combinations=1

class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        root=TreeNode(nums[0])
        def insertNode(root, num):
            if root.val==num:
                return
            if num<root.val:
                if root.left:
                    insertNode(root.left, num)
                else:
                    root.left=TreeNode(num)
            else:
                if root.right:
                    insertNode(root.right, num)
                else:
                    root.right=TreeNode(num)
        for i in range(1, len(nums)):
            insertNode(root, nums[i])

        def calculate(root):
            if root.left!=None:
                calculate(root.left)
                root.numOfNodes+=root.left.numOfNodes
            if root.right!=None:
                calculate(root.right)
                root.numOfNodes+=root.right.numOfNodes
            if root.left==None and root.right!=None:
                root.combinations=root.right.combinations
                return
            if root.left!=None and root.right==None:
                root.combinations=root.left.combinations
                return
            if root.left==None and root.right==None:
                return
            root.combinations=(root.left.combinations*root.right.combinations*comb(root.left.numOfNodes+root.right.numOfNodes, root.left.numOfNodes))%1000000007
                
        calculate(root)
        return (root.combinations-1)%1000000007