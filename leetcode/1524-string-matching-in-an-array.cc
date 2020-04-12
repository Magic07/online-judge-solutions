class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
      vector<string> answer;
      for(int i=0;i<words.size();i++){
        const string& w=words[i];
        for(int j=0;j<words.size();j++){
          if(i==j) continue;
          if(words[j].find(w)!=std::string::npos){
            answer.push_back(w);
            break;
          }
        }
      }
      return answer;
    }
};