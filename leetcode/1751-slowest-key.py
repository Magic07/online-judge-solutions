class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        pressed=[0]*26
        lastRelease=0
        for i in range(len(releaseTimes)):
            index=ord(keysPressed[i])-ord('a')
            pressed[index]=max(pressed[index],releaseTimes[i]-lastRelease)
            lastRelease=releaseTimes[i]
        maxPressed=max(pressed)
        for i in range(25,-1,-1):
            if pressed[i]==maxPressed:
                return chr(i+ord('a'))