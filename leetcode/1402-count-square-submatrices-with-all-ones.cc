class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
      int row=matrix.size();
      int col=matrix[0].size();
      int answer(0);
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          for(int k=0;k<min(row-i, col-j);k++){
            bool square(true);
            for(int a=0;a<=k;a++){
              if(matrix[i+k][j+a]==0||matrix[i+a][j+k]==0){
                square=false;
                break;
              }
            }
            if(square){
              answer++;
            } else {
              break;
            }
          }
        }
      }
      return answer;
    }
};