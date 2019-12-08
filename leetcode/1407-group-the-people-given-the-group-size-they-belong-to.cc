class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
      int grouped(0);
      vector<vector<int>> answer;
      for(int i=1;i<=groupSizes.size()&&grouped<groupSizes.size();i++){
        vector<int> currentGroup;
        int seatLeft(i);
        for(int j=0;j<groupSizes.size();j++){
          if(groupSizes[j]==i){
            currentGroup.push_back(j);
            seatLeft--;
            if(seatLeft==0){
              answer.push_back(currentGroup);
              currentGroup=vector<int>();
              seatLeft=i;
            }
          }
        }
      }
      return answer;
    }
};