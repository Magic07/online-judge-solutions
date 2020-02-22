class Solution {
public:
    int countOrders(int n) {
      long long answer(1);
      for(int i=n;i>0;i--){
        answer*=(2*i);
        answer*=(2*i-1);
        answer/=2;
        answer%=(long long)(1e9+7);
      }
      return answer;
    }
};