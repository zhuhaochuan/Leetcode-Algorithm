class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if(n<3) return n;
        //dp[i][j]表示i-j为结尾的等差数组的长度
        vector<vector<int>> dp(n,vector<int>(n,2));

        unordered_map<int,set<int,greater<int>>> map;
        map[A[0]].insert(0);
        map[A[1]].insert(1);
        int res = 2;
        for(int i=2;i<n;++i){
            for(int j=0;j<i;++j){
                int d = A[i] - A[j];
                int pre = A[j] - d;
                if(!map.count(pre)) {
                    continue;
                }
                auto set = map[pre];
                auto index = set.upper_bound(j);
                if(index==set.end()){
                    continue;
                }
                dp[j][i] = dp[*index][j]+1;
                // cout << j << i << pre <<" " <<dp[j][i] << endl;
                res = max(res,dp[j][i]);
            }
            map[A[i]].insert(i);
        }
        return res;
    }
};