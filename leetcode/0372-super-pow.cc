class Solution {
public:
    int superPow(int a, vector<int>& b) {
      if(a==0){
        return 0;
      }
      int answer=1;
      for(int d:b){
        int a1=longPow(answer,10);
        int a2=longPow(a,d);
        long long a1a2=(long)a1*(long)a2;
        answer=a1a2%1337;
      }
      return answer;
    }
  
  int longPow(int b, int e){
    b=b%1337;
    if(e==0){
      return 1;
    }
    if(e>5){
      long long p=pow(b,5);
      p=p%1337;
      p*=((long long)pow(b,e-5)%1337);
      return p;
    } else {
      long long p=pow(b,e);
      p=p%1337;
      return p;
    }
  }
};