class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> answer;
        set<float> values;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                float value=float(j)/float(i);
                if(values.find(value)==values.end()){
                    stringstream ss;
                    ss<<j<<"/"<<i;
                    answer.push_back(ss.str());
                    values.insert(value);
                }
            }
        }
        return answer;
    }
};