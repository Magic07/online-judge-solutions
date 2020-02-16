class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
      priority_queue<int, vector<int>, greater<int>> pq;
      sort(events.begin(), events.end());
      int index(0);
      int answer(0);
      for(int i=1;i<=100000;i++){
        while(index<events.size()&&events[index][0]==i){
          pq.push(events[index][1]);
          index++;
        }
        while(!pq.empty()&&pq.top()<i){
          pq.pop();
        }
        if(!pq.empty()){
          pq.pop();
          answer++;
        }
      }
      return answer;
    }
};