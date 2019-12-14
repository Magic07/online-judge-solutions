class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
      if(intervals.size()==1){
        return 1;
      }
      int removed(0);
      int last(0);
      sort(intervals.begin(), intervals.end());
      for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]>=intervals[last][0]&&intervals[i][1]<=intervals[last][1]){
          removed++;
        } else {
          last=i;
        }
      }
      return intervals.size()-removed;
    }
};