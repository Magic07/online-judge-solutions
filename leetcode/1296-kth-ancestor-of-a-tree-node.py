class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        self.parents = [[-2 for i in range(int(log2(n)+1))] for j in range(n+1)]
        for i in range(n):
            self.parents[i][0]=parent[i]
            for j in range(1,int(log2(n))+1):
                if self.parents[i][j-1]==-1:
                    self.parents[i][j]=-1
                else:
                    self.parents[i][j]=self.parents[self.parents[i][j-1]][j-1]

    def getKthAncestor(self, node: int, k: int) -> int:
        while k>0 and node!=-1:
            p=int(log2(k))
            node=self.parents[node][p]
            k-=(1<<p)
        return node


# Ref: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/discuss/686482/Python3-binary-lifting-(dp)