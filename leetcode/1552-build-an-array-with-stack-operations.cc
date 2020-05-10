class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> answer;
        int current=1;
        for(int i: target){
            while(current<i){
                answer.push_back("Push");
                answer.push_back("Pop");
                current++;
            }
            answer.push_back("Push");
            current++;
        }
        return answer;
    }
};