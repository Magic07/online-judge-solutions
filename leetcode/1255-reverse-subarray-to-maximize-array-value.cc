class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int low(INT_MAX), high(0), answer(0);
        for(int i=0;i<nums.size()-1;i++){
            answer+=abs(nums[i]-nums[i+1]);
            high=max(high, min(nums[i],nums[i+1]));
            low=min(low, max(nums[i],nums[i+1]));
        }
        int addition=2*(high-low);
        for(int i=1;i<nums.size()-1;i++){
            addition=max(addition, abs(nums[nums.size()-1]-nums[i-1])-abs(nums[i]-nums[i-1]));
            addition=max(addition, abs(nums[0]-nums[i+1])-abs(nums[i]-nums[i+1]));
        }
        if(addition>0){
            answer+=addition;
        }
        return answer;
    }
};