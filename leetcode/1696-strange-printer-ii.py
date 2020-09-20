class Solution:
    def isPrintable(self, targetGrid: List[List[int]]) -> bool:
        regions={}
        dependencies={}
        visited={}
        printedRegions=0
        for i in range(len(targetGrid)):
            for j in range(len(targetGrid[0])):
                regionId=targetGrid[i][j]
                if regionId not in dependencies:
                    dependencies[regionId]=[]
                if regionId not in regions:
                    regions[regionId]=[i,j,i,j]
                if regionId not in visited:
                    visited[regionId]=False
                else:
                    [minI, minJ, maxI, maxJ]=regions[regionId]
                    regions[regionId]=[min(minI,i), min(minJ,j), max(maxI,i), max(maxJ,j)]
        for k,[minI,minJ,maxI,maxJ] in regions.items():
            for i in range(minI, maxI+1):
                for j in range(minJ, maxJ+1):
                    regionId=targetGrid[i][j]
                    if regionId!=k and regionId not in dependencies[k]:
                        dependencies[k].append(regionId)
        lastPrintedRegions=0
        while printedRegions<len(regions):
            for k,v in dependencies.items():
                if len(v)==0 and visited[k]==False:
                    visited[k]=True
                    printedRegions+=1
                    if printedRegions==len(regions):
                        return True
                    for k1,v1 in dependencies.items():
                        if k in v1:
                            v1.remove(k)
            if printedRegions==lastPrintedRegions:
                return False
            lastPrintedRegions=printedRegions
        return True