class Solution:
    def _cleanString(self, board: str) -> str:
        if not board:
            return board
        boardCopy=board
        lastIndex=0
        lastChar=boardCopy[0]
        for i in range(1, len(boardCopy)):
            if(boardCopy[i]!=lastChar):
                if(i-lastIndex>=3):
                    boardCopy=boardCopy[:lastIndex]+boardCopy[i:]
                    return boardCopy
                lastChar=boardCopy[i]
                lastIndex=i
        if len(boardCopy)-lastIndex>=3:
            boardCopy=boardCopy[:lastIndex]
            return boardCopy
        return boardCopy

    @lru_cache(maxsize=None)
    def _findMinStep(self, boardOri: str, handOri: str) -> int:
        if not boardOri:
            return 0
        answer=sys.maxsize
        board=boardOri
        hand=handOri
        lastBoardSize=len(boardOri)
        board=self._cleanString(board)
        while lastBoardSize!=len(board):
            answer=min(answer,self._findMinStep(board, hand))
            lastBoardSize=len(board)
            board=self._cleanString(board)
        board=boardOri
        for i in range(0, len(board)):
            indexOfHand=hand.find(board[i])
            if(indexOfHand!=-1):
                answer=min(answer, self._findMinStep(board[:i]+board[i]+board[i:], hand[:indexOfHand]+hand[indexOfHand+1:])+1)
                answer=min(answer, self._findMinStep(board[:i+1]+board[i]+board[i+1:], hand[:indexOfHand]+hand[indexOfHand+1:])+1)
        return answer
        
    def findMinStep(self, board: str, hand: str) -> int:
        ballType='RYBGW'
        charInBoard=[0]*5
        for c in board:
            charInBoard[ballType.find(c)]+=1
        charInHand=[0]*5
        for c in hand:
            charInHand[ballType.find(c)]+=1
        for i in range(0,5):
            need=(3-charInBoard[i]%3)%3
            if need>charInHand[i]:
                return -1
            else:
                charInHand[i]=need
        hand=''
        for i in range(0,5):
            hand+=ballType[i]*charInHand[i]
        return self._findMinStep(board, hand)