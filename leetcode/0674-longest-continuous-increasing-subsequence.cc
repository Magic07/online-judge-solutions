class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int longest=0;
        int currentLength=0;
        int lastNum=INT_MIN;
        for(const int& num: nums){
            if(num>lastNum){
                currentLength++;
                if(currentLength>longest){
                    longest=currentLength;
                }
            } else {
                currentLength=1;
            }
            lastNum=num;
        }
        return longest;
    }
};