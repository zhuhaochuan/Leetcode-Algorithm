class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        if(n<=1) return n;
        int res = 0;
        int cur = 1;
        for(int i=0;i<n-1;++i) {
            if(i&1){
                if(A[i]>A[i+1]) cur++;
                else {
                    res = max(res,cur);
                    cur = 1;
                }
            }else {
                if(A[i]<A[i+1]) cur++;
                else {
                    res = max(res,cur);
                    cur = 1;
                }
            }
        }
        res = max(res,cur);
        cur = 1;
        for(int i=0;i<n-1;++i) {
            if(i&1){
                if(A[i]<A[i+1]) cur++;
                else {
                    res = max(res,cur);
                    cur = 1;
                }
            }else {
                if(A[i]>A[i+1]) cur++;
                else {
                    res = max(res,cur);
                    cur = 1;
                }
            }
        }
        return max(res,cur);;
    }
};