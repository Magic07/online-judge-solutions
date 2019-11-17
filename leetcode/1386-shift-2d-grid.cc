class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      k=k%(grid.size()*grid[0].size());
      vector<int> firstCol(grid.size());
      for(int i=0;i<k;i++){
        firstCol[0]=grid[grid.size()-1][grid[0].size()-1];
        for(int j=1;j<grid.size();j++){
          firstCol[j]=grid[j-1][grid[0].size()-1];
        }
        for(int a=0;a<grid.size();a++){
          for(int b=grid[0].size()-1;b>0;b--){
            grid[a][b]=grid[a][b-1];
          }
          grid[a][0]=firstCol[a];
        }
      }
      return grid;
    }
};