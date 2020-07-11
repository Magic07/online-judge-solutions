class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        def isSquare(x):
            return int(sqrt(x))**2==x
    
        @functools.lru_cache(maxsize=None)
        def moves(x):
            if isSquare(x):
                return True
            i=1
            while i**2<x:
                if not moves(x-i**2):
                    return True
                i+=1
            return False
        
        for i in range(n):
            moves(i)
        
        return moves(n)
                    