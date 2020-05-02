class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<char> s1c(s1.size());
        vector<char> s2c(s2.size());
        for(int i=0;i<s1.size();i++){
            s1c[i]=s1[i];
            s2c[i]=s2[i];
        }
        sort(s1c.begin(),s1c.end());
        sort(s2c.begin(),s2c.end());
        int i=0;
        while(i<s1.size()&&s1c[i]==s2c[i]){
            i++;
        }
        if(i==s1.size()-1){
            return true;
        }
        bool aIsGreater(s1c[i]>s2c[i]);
        for(;i<s1.size();i++){
            if(s1c[i]>s2c[i]==aIsGreater||s1c[i]==s2c[i]){
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};