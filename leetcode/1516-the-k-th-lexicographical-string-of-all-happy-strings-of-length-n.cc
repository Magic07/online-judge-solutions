class Solution {
public:
  vector<string> happyStrings;
  void generateHappyStrings(const string& prefix, int n){
    if(prefix.size()==n){
      happyStrings.push_back(prefix);
      return;
    }
    char last=prefix[prefix.size()-1];
    vector<char> p({'a','b','c'});
    for(char c:p){
      if(c!=last){
        generateHappyStrings(prefix+c,n);
      }
    }
  }
  string getHappyString(int n, int k) {
    generateHappyStrings("a",n);
    generateHappyStrings("b",n);
    generateHappyStrings("c",n);
    if(happyStrings.size()<k){
      return "";
    }
    std::sort(happyStrings.begin(), happyStrings.end());
    return happyStrings[k-1];
  }
};