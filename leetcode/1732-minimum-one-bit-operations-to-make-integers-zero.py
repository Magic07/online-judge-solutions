class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n<=1:
            return n
        bits=len(bin(n))-2  # Starts with 0x.
        return (1<<bits)-1-self.minimumOneBitOperations(n-(1<<(bits-1)))
        

# Ref: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/discuss/877741/C%2B%2B-solution-with-explanation