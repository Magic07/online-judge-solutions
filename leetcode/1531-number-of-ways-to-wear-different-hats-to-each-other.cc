class Solution {
    vector<vector<int>> dp;
    int person;
public:
    int numberWays(const vector<vector<int>>& prefer, int index, int status){
        if(status==((1<<person)-1)){
            return 1;
        }
        if(index>=prefer.size())
            return 0;
        if(dp[index][status]!=-1){
            return dp[index][status];
        }
        long long answer(0);
        for(int p : prefer[index]){
            if((status|(1<<p))!=status){
                answer+=numberWays(prefer, index+1, status|(1<<p));
            }
        }
        answer+=numberWays(prefer, index+1, status);
        answer%=1000000007;
        dp[index][status]=answer;
        return answer;
    }
    int numberWays(vector<vector<int>>& hats) {
        person=hats.size();
        dp=vector<vector<int>>(41, vector<int>((1<<hats.size())-1,-1));
        vector<vector<int>> prefer(41);
        for(int i=0;i<hats.size();i++){
            for(int h: hats[i]){
                prefer[h].push_back(i);
            }
        }
        return numberWays(prefer, 0, 0);
    }
};