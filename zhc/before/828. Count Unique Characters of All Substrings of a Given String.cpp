class Solution {
public:
    int uniqueLetterString(string s) {
        int len=s.length();
        vector<int> left(len,-1);
        vector<int> right(len,-1);

        //求左端点
        vector<int> prev(26,-1);
        for(int i=0;i<len;i++){
            left[i]=prev[s[i]-'A'];
            prev[s[i]-'A']=i;
        }

        //求右端点
        for(int i=0;i<26;i++){
            prev[i]=len;
        }
        for(int i=len-1;i>=0;i--){
            right[i]=prev[s[i]-'A'];
            prev[s[i]-'A']=i;
        }

        //根据区间计算各字符的贡献
        long long int ans=0;
        for(int i=0;i<len;i++){
            ans=(ans+(i-left[i])*(right[i]-i))%1000000007;//计算
        }
        return ans;
    }
};
