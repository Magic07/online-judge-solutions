class Solution {
public:
  bool isValidPosition(int p,const vector<vector<int>>& grid){
    int row=p/1000;
    int col=p%1000;
    if(col>=grid[0].size()||col<0){
      return false;
    } else if(row>=grid.size()||row<0){
      return false;
    }
    return true;
  }
  int nextPosition(int currentPosition, const vector<vector<int>>& grid){
    int row=currentPosition/1000;
    int col=currentPosition%1000;
    int direction=grid[row][col];
    if(direction==1){
      col++;
    } else if(direction==2){
      col--;
    } else if(direction==3){
      row++;
    } else if(direction==4){
      row--;
    }
    int answer=row*1000+col;
    if(isValidPosition(answer,grid)){
      return answer;
    } else {
      return -1;
    }
  }
  
  vector<int> changeArrow(int currentPosition, const vector<vector<int>>& grid){
    vector<int> result;
    int row=currentPosition/1000;
    int col=currentPosition%1000;
    int direction=grid[row][col];
    if(direction!=1){
      col++;
      int p=row*1000+col;
      if(isValidPosition(p,grid)){
        result.push_back(p);
      }
      col--;
    }
    if(direction!=2){
      col--;
      int p=row*1000+col;
      if(isValidPosition(p,grid)){
        result.push_back(p);
      }
      col++;
    }
    if(direction!=4){
      row--;
      int p=row*1000+col;
      if(isValidPosition(p,grid)){
        result.push_back(p);
      }
      row++;
    }
    if(direction!=3){
      row++;
      int p=row*1000+col;
      if(isValidPosition(p,grid)){
        result.push_back(p);
      }
      row--;
    }
    return result;
  }
  
  void walk(int start, int steps, const vector<vector<int>>& grid, vector<vector<int>>& cost, queue<int>& walked){
    while(start>=0&&cost[start/1000][start%1000]<0){
      cost[start/1000][start%1000]=steps;
      walked.push(start);
      start=nextPosition(start,grid);
    }
  }

  int minCost(vector<vector<int>>& grid) {
    vector<vector<int>> cost(grid.size(), vector<int>(grid[0].size(),-1));
    queue<int> currentQueue;
    queue<int> nextQueue;
    int currentCost(0);
    walk(0,currentCost, grid, cost, currentQueue);
    currentCost++;
    while(!currentQueue.empty()){
      int c=currentQueue.front();
      currentQueue.pop();
      auto starts= changeArrow(c,grid);
      for(int s:starts){
        walk(s, currentCost,grid,cost,nextQueue);
      }
      if(currentQueue.empty()){
        currentQueue=nextQueue;
        nextQueue={};
        currentCost++;
      }
    }
    return cost[cost.size()-1][cost[0].size()-1];
  }
};