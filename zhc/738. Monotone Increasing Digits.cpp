class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int r = N;
        vector<int> v;
        while(N){
            int t = N%10;
            N /= 10;
            v.push_back(t);
        }
        reverse(v.begin(),v.end());
        int index = -1;
        for(int i=0;i<v.size()-1;++i){
            if(v[i]>v[i+1]){
                index = i;
                break;
            }
        }
        if(index==-1) return r;
        for(int i=index;i>=0;--i){
            if(v[i]==v[index]){
                index = i;
            }else break;
        }
        int res = 0;
        for(int i=0;i<index;++i){
            res = 10*res+v[i];
        }
        res = res*10 + v[index]-1;
        for(int i=index+1;i<v.size();++i){
            res = res*10 + 9;
        }
        return res;
    }
};