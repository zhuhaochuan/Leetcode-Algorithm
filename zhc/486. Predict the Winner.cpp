class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return true;
        int sum = 0;
        vector<int> sum_list(n+1,0);
        for(int i=0;i<n;++i) {
            sum += nums[i];
            sum_list[i+1] = sum;
        }
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(i==j) dp[i][j]=nums[i];
                if(j==i+1) dp[i][j] = max(nums[i],nums[j]);
            }
        }
        for(int l=2;l<n;++l) {
            for(int i=0;i+l<n;++i){
                int j = i+l;
                dp[i][j] = max(nums[j]+sum_list[j]-sum_list[i]-dp[i][j-1],nums[i]+sum_list[j+1]-sum_list[i+1]-dp[i+1][j]);
            }
        }
        if(dp[0][n-1]*2>=sum) {
            return true;
        }else return false;
    }
};