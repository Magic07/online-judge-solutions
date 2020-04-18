class Solution {
public:
    int findMaxFibonacciNumber(int k, vector<int>& fibonacciNumbers){
      for(int i=fibonacciNumbers.size()-1;i>=0;i--){
        if(fibonacciNumbers[i]<k){
          return fibonacciNumbers[i];
        }
      }
      assert(false);
      return -1;
    }
    int findMinFibonacciNumbers(int k) {
      vector<int> fibonacciNumbers;
      fibonacciNumbers.push_back(1);
      int last1(1);
      int last2(1);
      while(true){
        int current=last1+last2;
        if(current==k){
          return 1;
        }
        if(current>k){
          break;
        }
        fibonacciNumbers.push_back(current);
        last2=last1;
        last1=current;
      }
      int answer(0);
      while(find(fibonacciNumbers.begin(), fibonacciNumbers.end(),k)==fibonacciNumbers.end()){
        k-=findMaxFibonacciNumber(k,fibonacciNumbers);
        answer++;
      }
      return answer+1;
    }
};