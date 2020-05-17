class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string>> words;
        std::istringstream iss(text);
        for(std::string s; iss >> s;){
            if(s[0]>='A'&&s[0]<='Z'){
                s[0]-=('A'-'a');
            }
            words[s.size()].push_back(s);
        }
        stringstream ss;
        for(auto it=words.begin();it!=words.end();++it){
            for(const string& w: it->second){
                ss<<w<<" ";
            }
        }
        string answer=ss.str();
        answer[0]+=('A'-'a');
        return answer.substr(0, answer.size()-1);
    }
};