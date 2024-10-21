class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(arr.size()==0) return 0;
        int mod = 1000000007;
        long sum1 = 0;
        long sum2 = 0;
        int sum = 0;
        long arr_sum = 0;

        for(int i=0;i<arr.size();i++) {
            arr_sum += arr[i];
        }

        sum1 = helper(arr,sum);
        if(k==1) return sum1;

        sum2 = helper(arr,sum);
        if(k==2) return max(sum2,sum1);

        if(arr_sum<=0) return max(sum1,sum2);
        
        if(sum1>=sum2){
            return sum1 + (k-1)*arr_sum%mod;
        }else {
            return sum2+(k-2)*arr_sum%mod;
        }
        return 0;
    }
    
    int helper(vector<int>& arr,int& sum){
        int res = 0;
        int n = arr.size();
        for(int i=0;i<n;++i) {
            sum += arr[i];
            if(sum>=0){
                res = max(res,sum);
            }else {
                sum = 0;
            }
        }
        res = max(res,sum);
        return res;
    }
};