class Solution {
public:
    int lower2n(int num){
      for(int i=0;i<num;i++){
        if(pow(2, i)>num){
          return i-1;
        }
      }
      return 0;
    }
    string toBin(int num, int length){
      cout<<"toBin "<<num<<endl;
      stack<int> s;
      while(num!=0){
        s.push(num%2);
        num/=2;
      }
      stringstream ss;
      while(length>s.size()){
        ss<<"0";
        length--;
      }
      while(!s.empty()){
        ss<<s.top();
        s.pop();
      }
      return ss.str();
    }
    string encode(int num) {
      if(num==0) return "";
      if(num==1) return "0";
      if(num==2) return "1";
      int l2n=lower2n(num);
      if(num==pow(2,l2n+1)-1){
        return toBin(0, l2n+1);
      }
      return toBin(num-pow(2,l2n)+1, l2n);
    }
};