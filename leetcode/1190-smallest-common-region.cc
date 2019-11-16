class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
      unordered_map<string, string> upperRegion;
      for(vector<string>& r:regions){
        if(r.size()==1) continue;
        for(int i=1;i<r.size();i++){
          upperRegion[r[i]]=r[0];
        }
      }
      string currentRegion(region1);
      stack<string> r1;
      r1.push(region1);
      while(upperRegion.find(currentRegion)!=upperRegion.end()){
        string ur=upperRegion[currentRegion];
        r1.push(ur);
        currentRegion=ur;
      }
      stack<string> r2;
      r2.push(region2);
      currentRegion=region2;
      while(upperRegion.find(currentRegion)!=upperRegion.end()){
        string ur=upperRegion[currentRegion];
        r2.push(ur);
        currentRegion=ur;
      }
      string answer("");
      while(!r1.empty()&&!r2.empty()&&r1.top()==r2.top()){
        answer=r1.top();
        r1.pop();
        r2.pop();
      }
      return answer;
    }
};