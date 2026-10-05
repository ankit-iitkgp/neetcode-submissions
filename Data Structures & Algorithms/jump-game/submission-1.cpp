class Solution {
public:
    bool canJump(vector<int>& nums) {
        long i=0, j=0;
        int n = nums.size();
        for(long i=0; i<=j; i++) {
            if(j>=n-1) return true;
            j = max(j, nums[i]+i);
        }
        return false;
    }
};
