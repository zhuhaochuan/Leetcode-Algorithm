// https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked



class Solution {
public:
    int findMaxPath(unordered_map<int,int>& table, int num) {
        if (table.find(num) == table.end()) return 0;
        if (table[num] > 0) return table[num];
        table[num] = 1 + findMaxPath(table, num+1);
        return table[num];
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> table;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            table[nums[i]] = 0;
        }
        int res = 0;
        for (int i=0; i<n; i++) {
            int cur = findMaxPath(table, nums[i]);
            res = max(res, cur);
        }
        return res;
    }
};