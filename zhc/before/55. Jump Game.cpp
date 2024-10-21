class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return true;
        int max_next = 0;
        for(int i=0;i<n;++i){
            if(i>max_next) return false;
            max_next = max(max_next,nums[i]+i);
            if(max_next>=n-1) return true;
        }
        return false;
    }
};