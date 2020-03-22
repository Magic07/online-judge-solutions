#include <vector>

class Solution {
 public:
  int maxSize[500][167];
  int dp(const vector<int>& slices, int end, int n, bool skipFirst) {
    int offset=skipFirst?1:0;
    if (maxSize[end][n] != 0) {
      return maxSize[end][n];
    }
    if(n==1){
      int answer= *max_element(slices.begin()+offset,slices.begin()+end+1);
      maxSize[end][n]=answer;
      return answer;
    }
    if(end+1-offset<n*2-1){
      return 0;
    }
    int answer =
        max(dp(slices, end - 2, n - 1,skipFirst) + slices[end], dp(slices, end - 1, n, skipFirst));
    maxSize[end][n]=answer;
    return answer;
  }
  int maxSizeSlices(vector<int>& slices) {
    memset(maxSize,0,sizeof(maxSize));
    int answer=dp(slices, slices.size()-2,slices.size()/3,false);
    memset(maxSize,0,sizeof(maxSize));
    answer=max(answer, dp(slices, slices.size()-1,slices.size()/3,true));
    return answer;
  }
};