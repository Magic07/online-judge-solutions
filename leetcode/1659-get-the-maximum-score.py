class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        s1=[0]*(len(nums1)+1)
        s2=[0]*(len(nums2)+1)
        index1=len(nums1)-1
        index2=len(nums2)-1
        while index1>=0 and index2>=0:
            if nums1[index1]>nums2[index2]:
                s1[index1]=s1[index1+1]+nums1[index1]
                index1-=1
            elif nums2[index2]>nums1[index1]:
                s2[index2]=s2[index2+1]+nums2[index2]
                index2-=1
            else:
                s1[index1]=max(s1[index1+1],s2[index2+1])+nums1[index1]
                s2[index2]=max(s1[index1+1],s2[index2+1])+nums2[index2]
                index1-=1
                index2-=1
        while index1>=0:
                s1[index1]=s1[index1+1]+nums1[index1]
                index1-=1
        while index2>=0:
                s2[index2]=s2[index2+1]+nums2[index2]
                index2-=1
        return max(s1[0],s2[0])%1000000007