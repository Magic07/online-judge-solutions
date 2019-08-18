class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> answer;
    if(S.size()==0){
      return answer;
    }
    auto charArray = S.c_str();
    char last=charArray[0];
    int start=0;
    for (int i = 1; i < S.size(); i++) {
      char current=charArray[i];
      if(current==last){
        continue;
      } else {
        if(i-start>=3){
          vector<int> interval{start, i-1};
          answer.push_back(interval);
        }
        start=i;
        last=charArray[i];
      }
    }
    if(S.size()-start>=3){
      answer.push_back({start, S.size()-1});
    }
    return answer;
  }
};