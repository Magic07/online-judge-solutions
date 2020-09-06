class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        d1={}
        d2={}
        for x in nums1:
            if x not in d1:
                d1[x]=1
            else:
                d1[x]+=1
        for x in nums2:
            if x not in d2:
                d2[x]=1
            else:
                d2[x]+=1

        def numTri(d1, d2):
            answer=0
            for k1, v1 in d1.items():
                if k1 in d2:
                    answer+=(comb(d2[k1],2)*v1)
                for k2,v2 in d2.items():
                    if k2>=k1:
                        continue
                    if k1*k1%k2!=0:
                        continue
                    if k1*k1/k2 in d2:
                        answer+=((d2[k1*k1/k2]*v2)*v1)
            return answer
        return numTri(d1, d2)+numTri(d2, d1)