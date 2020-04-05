class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
      int sum=accumulate(nums.begin(), nums.end(),0);
      sort(nums.begin(), nums.end(), greater<int>());
      vector<int> answer;
      int sumOfSubsequence(0);
      for(int num: nums){
        sumOfSubsequence+=num;
        answer.push_back(num);
        if(sumOfSubsequence>((double)sum)/2){
          return answer;
        }
      }
      return answer;
    }
};