class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0;
        int currSum = 0;
        int maxVal = nums[0];
        for(int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            if(currSum<0) currSum = 0;
            maxSum = max(maxSum, currSum);
            maxVal = max(maxVal, nums[i]);
        }
        if(maxSum>0) return maxSum;
        return maxVal;
    }
};
