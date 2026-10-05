class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> sorted_str;
        for(int i=0; i<strs.size(); i++) {
            string temp = strs[i];
            string key = strs[i];
            sort(key.begin(), key.end());
            sorted_str[key].push_back(temp);
        }
        vector<vector<string>> res;
        for(auto const& [key, val] : sorted_str) {
            res.push_back(val);
        }
        return res;
    }
};
