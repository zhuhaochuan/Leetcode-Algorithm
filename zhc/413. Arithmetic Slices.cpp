class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n<3) return 0;
        //长度为k的等差数列有：((k-3+1)+1)(k-2)/2 = (k-1)(k-2)/2
        int res = 0;
        vector<int> diff(n-1,0);
        for(int i=0;i<n-1;++i) {
            diff[i] = A[i+1]-A[i];
        }
        int count = 2;
        for(int i=1;i<n-1;++i) {
            if(diff[i]==diff[i-1]) {
                count++;
            }else {
                int c = (count-1)*(count-2)/2;
                res += c;
                count = 2;
            }
        }
        if(count!=2) {
            int c = (count-1)*(count-2)/2;
            res += c;
        }
        return res;
    }
};