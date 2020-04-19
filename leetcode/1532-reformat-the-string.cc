class Solution {
public:
    string reformat(string s) {
      std::queue<char> letters;
      std::queue<char> digits;
      for(char c:s){
        if(c>='a'&&c<='z'){
          letters.push(c);
        } else {
          digits.push(c);
        }
      }
      cout<<letters.size()<<" "<<digits.size()<<endl;
      if(!(letters.size()==digits.size()||letters.size()==digits.size()+1||digits.size()==letters.size()+1)){
        return "";
      }
      stringstream ss;
      if(letters.size()>digits.size()){
        ss<<letters.front();
        letters.pop();
        while(!letters.empty()){
          ss<<digits.front();
          digits.pop();
          ss<<letters.front();
          letters.pop();
        }
      } else if(digits.size()>letters.size()){
        ss<<digits.front();
        digits.pop();
        while(!letters.empty()){
          ss<<letters.front();
          letters.pop();
          ss<<digits.front();
          digits.pop();
        }
      } else {
        while(!letters.empty()){
          ss<<letters.front();
          letters.pop();
          ss<<digits.front();
          digits.pop();
        }
      }
      return ss.str();
    }
};