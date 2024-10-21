class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        if(n<=1) return "";
 
        long tail = 0,front = 0;
        int mod = 1000000007;
        //哈希取模的方式解决数值过大的问题
        //取模的值取质数
        long r = 1;
        int index = -1;
        for(int i=0;i<n-1;++i) {
            front = (front*31 + (s[i]-'a'))%mod;
            tail = ((s[n-1-i]-'a')*r + tail)%mod;
            r = (r*31)%mod;
            if(front==tail) {
                index = i;
            }
        }
        
        return s.substr(0,index+1);
    }
};