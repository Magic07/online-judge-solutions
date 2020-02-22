class Solution {
public:
    int numberOfOne(int x){
      int answer(0);
      while(x!=0){
        if(x%2==1){
          answer++;
        }
        x/=2;
      }
      return answer;
    }
    vector<int> sortByBits(vector<int>& arr) {
      std::sort(arr.begin(), arr.end(), [this](int lhs, int rhs){
        int numl=numberOfOne(lhs);
        int numr=numberOfOne(rhs);
        if(numl<numr) {
          return true;
        } else if(numl==numr){
          return (lhs<rhs);
        } else {
          return false;
        }
      });
      return arr;
    }
};