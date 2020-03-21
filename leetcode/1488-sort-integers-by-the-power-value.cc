class Solution {
public:
  unordered_map<int,int> powerValue;
  int getPower(long x){
    if(powerValue.find(x)!=powerValue.end()){
      return powerValue[x];
    }
    int answer;
    if(x%2){
      answer= getPower(3*x+1)+1;
    } else {
      answer= getPower(x/2)+1;
    }
    powerValue[x]=answer;
    return answer;
  }
  int getKth(int lo, int hi, int k) {
    powerValue[1]=1;
    vector<vector<int>> pv; 
    for(int i=lo;i<=hi;i++){
      pv.push_back({getPower(i),i});
    }
    sort(pv.begin(),pv.end());
    return pv[k-1][1];
  }
};