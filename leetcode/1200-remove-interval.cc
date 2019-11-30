class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
      bool removeStarted(false);
      bool removeEnded(false);
      vector<vector<int>> answer;
      for(const auto& interval:intervals){
        if(removeEnded){
          answer.push_back(interval);
          continue;
        }
        if(removeStarted){
          if(interval[0]>toBeRemoved[1]){
            removeEnded=true;
            answer.push_back(interval);
          } else if(interval[1]>=toBeRemoved[1]){
            removeEnded=true;
            vector<int> temp={toBeRemoved[1], interval[1]};
            if(temp[0]!=temp[1])
              answer.push_back(temp);
          }
        } else {
          if(interval[0]>toBeRemoved[1]){
            removeStarted=true;
            removeEnded=true;
            answer.push_back(interval);
          }else if(interval[0]>toBeRemoved[0]){
            removeStarted=true;
            if(toBeRemoved[1]<interval[1]){
              removeEnded=true;
              vector<int> temp={toBeRemoved[1], interval[1]};
              if(temp[0]!=temp[1])
                answer.push_back(temp);              
            }else{
              continue;
            }
          } else if(interval[1]<=toBeRemoved[0]){
            answer.push_back(interval);
          } else if(toBeRemoved[1]>interval[1]){
            removeStarted=true;
            vector<int> temp={interval[0], toBeRemoved[0]};
            if(temp[0]!=temp[1])
              answer.push_back(temp);
          } else {
            removeStarted=true;
            removeEnded=true;
            vector<int> temp={interval[0], toBeRemoved[0]};
            if(temp[0]!=temp[1])
              answer.push_back(temp);
            temp={toBeRemoved[1], interval[1]};
            if(temp[0]!=temp[1])
              answer.push_back(temp);
          }
        }
      }
      return answer;
    }
};