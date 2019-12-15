class Solution {
 public:
  int calSum(vector<vector<int>>& mat, int row, int col, int length) {
    int answer(0);
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < length; j++) {
        answer += mat[row + i][col + j];
      }
    }
    return answer;
  }
  bool isLengthOkay(vector<vector<int>>& mat, int threshold, int length) {
    cout<<"length="<<length<<endl;
    for (int i = 0; i <= mat.size() - length; i++) {
      for (int j = 0; j <= mat[0].size() - length; j++) {
        if (calSum(mat, i, j, length) <= threshold) {
          return true;
        }
      }
    }
    return false;
  }
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int length(1);
    for (int i = 0; i < min(mat.size(), mat[0].size()); i++) {
      if (isLengthOkay(mat, threshold, length)) {
        length++;
        cout<<"length++"<<endl;
      } else {
        break;
      }
    }
    return length-1;
  }
};