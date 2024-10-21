class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        int res = 0;
        int cur = 0;
        for(int i=0;i<n;++i){
            if(nums[i]>=0){
                int next = i;
                while(nums[next]>=0){
                    int temp = nums[next];
                    nums[next] = -nums[next];
                    if(nums[temp]==nums[next]) {
                        cur++;
                        break;
                    }
                    next = temp;
                    cur++;
                }
                res = max(res,cur);
                cur = 0;
            }
        }
        return max(res,cur);
    }
};