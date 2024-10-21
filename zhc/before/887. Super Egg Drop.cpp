class Solution {
public:
    int superEggDrop(int K, int N) {
        // int res = N;
        if(K==1||N==1) return N;
        if(K>=N) K=N-1;
        int res = N-1;

        vector<vector<int>> dp(N+1,vector<int>(K+1,0));
        for(int i=1;i<=N;++i){
            dp[i][1] = i;
        }

        return helper(K,N,dp);
    }

    int helper(int K,int n,vector<vector<int>>& dp){
        if(dp[n][K]) return dp[n][K];
        int cur = n;
        int l = 0,r = n;
        while(l<r-1){
            int mid = l+(r-l)/2;
            int lv = helper(K-1,mid,dp);
            int rv = helper(K,n-mid-1,dp);
            cur = min(max(lv,rv)+1,cur);
            if(lv>rv) {
                r = mid;
            }else if(lv<rv){
                l = mid;
            }else{
                cur = min(max(lv,rv)+1,cur);
                break;
            }
        }
        dp[n][K] = cur;
        return cur;
    }
};