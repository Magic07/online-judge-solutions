class Solution {
public:
    int answer=0;
    int removePalindromeSub(string s) {
        if(s.size()==0||answer==2){
            return answer;
        }
        int start=0,end=s.size()-1;
        while(start<end){
            if(s[start]==s[end]){
                s.erase(end, 1);
                s.erase(0,1);
                end-=2;
            } else {
                end--;
            }
        }
        if(start==end){
            s.erase(s.begin());
        }
        answer++;
        return removePalindromeSub(s);
    }
};