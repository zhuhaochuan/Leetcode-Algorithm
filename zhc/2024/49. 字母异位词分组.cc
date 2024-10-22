https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        int n = strs.size();
        for (auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            table[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto& v : table) {
            res.push_back(v.second);
        }
        return res;
    }
};