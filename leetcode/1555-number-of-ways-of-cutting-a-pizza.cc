class Solution {
    int dp[51][51][11];
public:    
    bool hasAppleInRow(const vector<string>& pizza, int r, int left){
        for(int i=left;i<pizza[0].size();i++){
            if(pizza[r][i]=='A'){
                return true;
            }
        }
        return false;
    }
    bool hasAppleInCol(const vector<string>& pizza, int c, int top){
        for(int i=top;i<pizza.size();i++){
            if(pizza[i][c]=='A'){
                return true;
            }
        }
        return false;
    }
    bool hasAppleInRegion(const vector<string>& pizza, int left, int top){
        for(int i=left;i<pizza[0].size();i++){
            for(int j=top;j<pizza.size();j++){
                if(pizza[j][i]=='A'){
                    return true;
                }
            }
        }
        return false;
    }
    int ways(const vector<string>& pizza, int left, int top, int k){
        if(k<=0){
            return 0;
        }
        if(dp[left][top][k]>=0){
            return dp[left][top][k];
        }
        if(k==1&&hasAppleInRegion(pizza, left,top)){
            return 1;
        }
        long long answer(0);
        bool rowHasApple(false);
        bool colHasApple(false);
        for(int i=top;i<pizza.size();i++){
            if(!rowHasApple&&hasAppleInRow(pizza, i, left)){
                rowHasApple=true;
            }
            if(rowHasApple){
                answer+=ways(pizza, left,i+1,k-1);
            }
        }
        for(int i=left;i<pizza[0].size();i++){
            if(!colHasApple&&hasAppleInCol(pizza, i, top)){
                colHasApple=true;
            }
            if(colHasApple){
                answer+=ways(pizza, i+1, top, k-1);
            }
        }
        answer%=1000000007;
        dp[left][top][k]=answer;
        return answer;
    }
    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof(dp));
        return ways(pizza, 0,0,k);
    }
};