class Solution {
    unordered_map<int, vector<int>> tree;
public:
    int visit(int root, const vector<bool>& hasApple){
        int answer(0);
        for(int v: tree[root]){
            answer+=visit(v, hasApple);
        }
        if(answer>0||hasApple[root]){
            answer+=1;
        }
        return answer;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(const auto& e: edges){
            tree[e[0]].push_back(e[1]);
        }
        return max(0,(visit(0, hasApple)-1)*2);
    }
};