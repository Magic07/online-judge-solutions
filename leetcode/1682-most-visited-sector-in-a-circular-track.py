class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        visited=[0]*(n+1)
        last=rounds[0]
        for i in range(1, len(rounds)):
          current=rounds[i]
          if current>last:
            for j in range(last, current):
              visited[j]+=1
          else:
            for j in range(0, current):
              visited[j]+=1
            for j in range(last, n+1):
              visited[j]+=1
          last=current
        visited[rounds[-1]]+=1
        most_visited=max(visited[1:])
        answer=[]
        for i in range(1,n+1):
          if visited[i]==most_visited:
            answer.append(i)
        return sorted(answer)