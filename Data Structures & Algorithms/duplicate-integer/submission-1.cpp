class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i=0; i<nums.size(); i++) {
            if(seen.count(nums[i])>0) return true;
            seen.insert(nums[i]);
        }
        return false;
    }
};