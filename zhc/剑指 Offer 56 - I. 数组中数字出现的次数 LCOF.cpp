class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return nums;
        int o = 0;
        for(int i=0;i<n;++i) {
            o = o^nums[i];
        }
        int tag = 1;
        while((o&1)==0){
            o = o>>1;
            tag = tag<<1;
        }
        int or1 = 0,or2 = 0;
        for(int i=0;i<n;++i){
            if(nums[i]&tag){
                or1 ^= nums[i];
            }else {
                or2 ^= nums[i];
            }
        }
        return vector<int>{or1,or2};
    }
};