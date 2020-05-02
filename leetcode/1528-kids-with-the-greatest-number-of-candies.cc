class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy=*max_element(candies.begin(), candies.end());
        vector<bool> answer(candies.size());
        for(int i=0;i<candies.size();i++){
            answer[i]=((candies[i]+extraCandies)>=maxCandy);
        }
        return answer;
    }
};