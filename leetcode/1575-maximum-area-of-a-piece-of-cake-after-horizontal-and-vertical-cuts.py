class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        maxHorizontalCuts=0
        maxVerticalCuts=0
        lastX=0
        for x in sorted(horizontalCuts):
            maxHorizontalCuts=max(maxHorizontalCuts, x-lastX)
            lastX=x
        maxHorizontalCuts=max(maxHorizontalCuts, h-lastX)
        lastX=0
        for x in sorted(verticalCuts):
            maxVerticalCuts=max(maxVerticalCuts, x-lastX)
            lastX=x
        maxVerticalCuts=max(maxVerticalCuts, w-lastX)
        return maxHorizontalCuts*maxVerticalCuts%1000000007