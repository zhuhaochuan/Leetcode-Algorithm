class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int res = 1;
        unordered_map<char, int> index_map;
        int l = 0; int r = 0;
        while(r < n) {
            auto it = index_map.find(s[r]);
            if (it != index_map.end()) {
                l = max(it->second + 1, l);
            }
            index_map[s[r]] = r;
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};