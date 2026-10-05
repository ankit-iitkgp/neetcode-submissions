class Solution {
struct comp {
    bool operator()(vector<int> a, vector<int> b) {
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
};

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), comp());
        int curr_end = intervals[0][1];
        int removals = 0;
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][1] < curr_end) {
                curr_end = intervals[i][1];
                removals++;
            }
            else if(intervals[i][0] < curr_end) {
                removals++;
            }
            else {
                curr_end = intervals[i][1];
            }
        }
        return removals;
    }
};
