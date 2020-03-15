class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
      vector<pair<int,int>> efficiencySpeed;
      for(int i=0;i<n;i++){
        efficiencySpeed.push_back({efficiency[i],speed[i]});
      }
      sort(efficiencySpeed.begin(), efficiencySpeed.end(), greater<pair<int,int>>());
      long answer(0);
      long speedSum(0);
      priority_queue<int, vector<int>, greater<int>> pq;
      for(const auto& es: efficiencySpeed){
        speedSum+=es.second;
        pq.push(es.second);
        if(pq.size()>k){
          speedSum-=pq.top();
          pq.pop();
        }
        answer=max(answer, (long)es.first*speedSum);
      }
      return answer%1000000007;
    }
};