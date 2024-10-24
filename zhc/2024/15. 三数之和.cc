
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i] ;
            int l = i+1, r = n-1;
            while (l < r) {
                if (l > i+1 && nums[l] == nums[l-1]) {
                    l++;
                    continue;
                }
                int sum = nums[l] + nums[r];
                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    res.push_back({nums[l], nums[r], nums[i]});
                    l++;r--;
                }
            }
        }
        return res;
    }
};