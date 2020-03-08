class Solution {
public:
    int minutesOfSpreading(int employee, vector<int>& informTime, unordered_map<int, vector<int>>& org){
      int maxTime(0);
      for(int e: org[employee]){
        maxTime=max(maxTime, minutesOfSpreading(e, informTime, org));
      }
      return maxTime+informTime[employee];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      unordered_map<int, vector<int>> org;
      for(int i=0;i<n;i++){
        org[manager[i]].push_back(i);
      }
      return minutesOfSpreading(headID, informTime, org);
    }
};