class Solution {
public:
    bool xorGame(vector<int>& nums) {
        //所有偶数次出现的不影响结果 剔除
        int n = nums.size();
        unordered_map<int,int> map;

        int v = 0;
        for(int i=0;i<n;++i){
            map[nums[i]]++;
        }

        int c = 0;
        for(int i=0;i<n;++i){
            if(map[nums[i]]&1){
                v = v^nums[i];
                c++;
            }
        }
        if(v==0) return true;
        
        if(c&1){
            return false;
        }else {
            return true;
        }
    }
};