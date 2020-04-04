class Solution {
public:
    int sumOfDigits(int n){
      int sum(0);
      while(n!=0){
        sum+=n%10;
        n/=10;
      }
      return sum;
    }
    int countLargestGroup(int n) {
      int count[37];
      memset(count, 0,sizeof(count));
      for(int i=1;i<=n;i++){
        count[sumOfDigits(i)]++;
      }
      int largest(0);
      int answer(0);
      for(int i=1;i<37;i++){
        if(count[i]==largest){
          answer++;
        }
        if(count[i]>largest){
          largest=count[i];
          answer=1;
        }
      }
      return answer;
    }
};