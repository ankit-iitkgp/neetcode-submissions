class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sorted_str;
        for(int i=0; i<strs.size(); i++) {
            string temp = strs[i];
            string key = strs[i];
            sort(key.begin(), key.end());
            sorted_str[key].push_back(temp);
        }
        vector<vector<string>> res;
        for(auto& pai : sorted_str) {
            res.push_back(pai.second);
        }
        return res;
    }
};
