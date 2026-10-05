class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for (auto i=0; i<s.length(); i++) {
            count[s[i]-'a']++;
        }
        for(auto i=0; i<t.length(); i++) {
            count[t[i]-'a']--;
            if (count[t[i]-'a']<0) return false;
        }
        for(int i=0; i<26; i++) {
            if(count[i]>0) return false;
        }
        return true;
    }
};
