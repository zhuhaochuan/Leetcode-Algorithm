class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        //枚举转折点
        int count = 0;
        for(int i=0;i<n;++i) {
            if(S[i]!='1')
                ++count;
        }
        int res = min(n,count);
        
        for(int i=1;i<=n;++i) {
            if(S[i-1]=='0') {
                --count;
            }else {
                ++count;
            }
            res = min(res,count);
        }
        return res;
    }
};