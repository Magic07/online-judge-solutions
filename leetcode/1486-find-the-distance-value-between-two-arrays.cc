class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
      int answer(0);
      for(int a: arr1){
        for(int b:arr2){
          if(abs(a-b)<=d){
            answer++;
            break;
          }
        }
      }
      return arr1.size()-answer;
    }
};