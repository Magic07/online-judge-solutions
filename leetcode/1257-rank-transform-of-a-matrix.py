import collections

class Solution:
    def matrixRankTransform(self, matrix):
        answer=[[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        valueMap={}
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                value=matrix[r][c]
                if value not in valueMap:
                    valueMap[value]=[]
                valueMap[value].append((r,c))
        valueMap={key:valueMap[key] for key in sorted(valueMap.keys())}
        rowMax=[0]*len(matrix)
        colMax=[0]*len(matrix[0])
        def findRoot(parents, i):
            #print('Find root of %d at %s'%(i, parents))
            if parents[i]==i:
                return i
            parents[i]=findRoot(parents, parents[i])
            return parents[i]
        def group(coordinates):
            #print('group %s.'%coordinates)
            parents=[x for x in range(len(matrix)+len(matrix[0]))]
            for r,c in coordinates:
                parents[findRoot(parents, r)]=findRoot(parents,len(matrix)+c)
            return parents
        def maxRank(r,c):
            return max(rowMax[r], colMax[c])
        for value in valueMap.keys():
            coordinates=valueMap[value]
            parents=group(coordinates)
            groups=collections.defaultdict(list)
            for i in range(len(coordinates)):
                [r,c]=coordinates[i]
                groups[findRoot(parents, r)].append((r,c))
            for g in groups.values():
                rank=0
                for r,c in g:
                    rank=max(rank, maxRank(r,c))
                rank+=1
                for r,c in g:
                    answer[r][c]=rank
                    rowMax[r]=rank
                    colMax[c]=rank
        return answer