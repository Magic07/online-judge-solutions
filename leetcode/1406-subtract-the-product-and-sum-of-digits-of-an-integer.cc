class Solution {
public:
    int subtractProductAndSum(int n) {
      if(n==0) return 0;
      vector<int> digits;
      while(n!=0){
        digits.push_back(n%10);
        n/=10;
      }
      int sum(0);
      int product(1);
      for(int d: digits){
        sum+=d;
        product*=d;
      }
      return product-sum;
    }
};