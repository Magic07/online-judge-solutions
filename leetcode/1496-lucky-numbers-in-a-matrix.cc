class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
      vector<int> minElementRow;
      vector<int> maxElementCol;
      vector<int> answer;
      for(const auto& m: matrix){
        minElementRow.push_back(*min_element(m.begin(),m.end()));
      }
      for(int i=0;i<matrix[0].size();i++){
        int maxOfThisCol(0);
        for(int j=0;j<matrix.size();j++){
          maxOfThisCol=max(maxOfThisCol, matrix[j][i]);
        }
        maxElementCol.push_back(maxOfThisCol);
      }
      for(int x: minElementRow){
        if(find(maxElementCol.begin(), maxElementCol.end(), x)!=maxElementCol.end()){
          answer.push_back(x);
        }
      }
      return answer;
    }
};