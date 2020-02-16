class Solution {
public:
    bool isPossible(vector<int>& target) {
      priority_queue<int> pq;
      long long sum(0);
      for(int t: target){
        pq.push(t);
        sum+=t;
      }
      while(!pq.empty()&sum>=target.size()){
        int current=pq.top();
        pq.pop();
        if(current==1)
          return true;
        if(sum-current>current)
          return false;
        int newPush=current-(sum-current);
        pq.push(newPush);
        sum-=current;
        sum+=newPush;
      }
      return false;
    }
};