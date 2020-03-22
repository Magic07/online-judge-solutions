class Solution {
public:
    unordered_map<int,int> sumOfDivisors;
    set<int> sumFourDivisors(int num){
      set<int> divisors;
      divisors.insert(1);
      divisors.insert(num);
      for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
          divisors.insert(i);
          divisors.insert(num/i);
          if(divisors.size()>4){
            return set<int>();
          }
        }
      }
      if(divisors.size()==4){
        return divisors;
      }
      return set<int>();
    }
    int sumFourDivisors(vector<int>& nums) {
      int answer(0);
      for(int n: nums){
        if(sumOfDivisors.find(n)!=sumOfDivisors.end()){
          answer+=sumOfDivisors[n];
        } else {
          auto ds=sumFourDivisors(n);
          int sumOfN(0);
          for(int d:ds){
            sumOfN+=d;
          }
          sumOfDivisors[n]=sumOfN;
          answer+=sumOfN;
        }
      }
      return answer;
    }
};