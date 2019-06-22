class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> parentheses({{'(',')'},{'{','}'},{'[',']'}});
        std::stack<char> input;
        for(char const &c: s){
            if(parentheses.find(c)!=parentheses.end()){
                input.push(c);
            } else {
                if(input.empty()){
                    return false;
                } else if(parentheses[input.top()]!=c){
                    return false;
                } else {
                    input.pop();
                }
            }
        }
        if(input.empty()){
            return true;
        } else {
            return false;
        }
    }
};