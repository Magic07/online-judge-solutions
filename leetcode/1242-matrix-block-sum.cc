class Solution {
public:
    int calculateElement(vector<vector<int>>& mat, int row, int col, int K){
      int answer(0);
      for(int i=max(0, row-K);i<=min((int)mat.size()-1,row+K);i++){
        for(int j=max(0, col-K);j<=min((int)mat[0].size()-1, col+K);j++){
          answer+=mat[i][j];
        }
      }
      return answer;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
      vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(),0));
      for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
          answer[i][j]=calculateElement(mat, i,j,K);
        }
      }
      return answer;
    }
};