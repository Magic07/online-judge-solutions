class Solution {
public:
    double probability(unordered_map<int, vector<int>>& tree, int current, int target, int t){
      if(current==target){
        if(t==0||tree[current].size()==0){
          return 1;
        } else{
          return 0;
        }
      }
      if(t==0){
        return 0;
      }
      double p((double)1/tree[current].size());
      for(int c: tree[current]){
        double childP=probability(tree, c, target, t-1);
        if(childP>0){
          return p*childP;
        }
      }
      return 0;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
      unordered_map<int, vector<int>> tree;
      for(const auto& e: edges){
        if(e[0]>e[1]){
          tree[e[1]].push_back(e[0]);
        } else {
          tree[e[0]].push_back(e[1]);
        }
      }
      return probability(tree, 1, target, t);
    }
};