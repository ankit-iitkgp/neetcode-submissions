class KthLargest {
private:
    multiset<int> largestk;
    int k_limit;

public:
    KthLargest(int k, vector<int>& nums) {
        k_limit = k;
        for(int i=0; i<nums.size(); i++) {
            largestk.insert(nums[i]);
            if(largestk.size() > k_limit) {
                largestk.erase(largestk.begin());
            }
        }
    }
    
    int add(int val) {
        largestk.insert(val);
        if(largestk.size() > k_limit) {
            largestk.erase(largestk.begin());
        }
        return *largestk.begin();
    }
};