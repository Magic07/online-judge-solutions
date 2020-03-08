class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
      int answer(0);
      int lastTurnedOn(0);
      for(int i=0;i<light.size();i++){
        lastTurnedOn=max(lastTurnedOn, light[i]);
        if(lastTurnedOn==i+1){
          answer++;
        }
      }
      return answer;
    }
};