class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
      int answer=0;
      stack<int> s;
      s.push(INT_MAX);
      for(int a: arr){
        if(a<=s.top()){
          s.push(a);
        } else {
          do{
            int temp=s.top();
            s.pop();
            answer+=min(s.top(),a)*temp;
          }while(s.top()<a);
          s.push(a);
        }
      }
      while(s.size()>2){
        int temp=s.top();
        s.pop();
        answer+=s.top()*temp;
      }
      return answer;
    }
};