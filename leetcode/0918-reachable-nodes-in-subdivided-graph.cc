class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
      int MAX_N=3000;
      int graph[MAX_N][MAX_N];
      int remain[MAX_N];
      for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
          graph[i][j]=INT_MAX;
        }
      }
      for(int i=0;i<MAX_N;i++){
        remain[i]=-1;  // Less than 0 means not reachable.
      }
      remain[0]=M;
      for(auto& edge: edges){
        graph[edge[0]][edge[1]]=edge[2];
        graph[edge[1]][edge[0]]=edge[2];
      }
      // First element is the distance between source and the second element.
      priority_queue<pair<int,int>, vector<pair<int,int>>> edgeQueue;
      edgeQueue.push(pair<int,int>(M,0));
      while(!edgeQueue.empty()){
        pair<int, int> current=edgeQueue.top();
        edgeQueue.pop();
        int currentNode=current.second;
        int currenteRemain=current.first;
        for(int i=0;i<N;i++){
          if(graph[currentNode][i]!=INT_MAX&&remain[i]<remain[currentNode]-graph[currentNode][i]-1){
            remain[i]=remain[currentNode]-graph[currentNode][i]-1;
            edgeQueue.push(pair<int,int>(remain[i],i));
          }
        }
      }
      int answer=0;
      for(vector<int>& edge: edges){
        int left=max(0,remain[edge[0]]);
        int right=max(0, remain[edge[1]]);
        answer+=min(edge[2], left+right);
      }
      for(int r: remain){
        if(r>=0){
          answer++;
        }
      }
      return answer;
    }
};