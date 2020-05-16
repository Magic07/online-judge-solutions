class Solution {
public:
    int maxPower(string s) {
        char last('A');
        int current(0);
        int answer(1);
        for(const char c: s){
            if(c==last){
                current++;
                answer=max(answer,current);
            } else {
                last=c;
                current=1;
            }
        }
        return answer;
    }
};