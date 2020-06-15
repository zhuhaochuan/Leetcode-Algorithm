class Solution {
public:
    vector<int> beautifulArray(int N) {
        if(N==1) return {1};
        if(N==2) return {1,2};
        if(N==3) return {3,1,2};
        vector<int> res;
        res = helper(N);
        for(int i=0;i<res.size();++i){
            if(res[i]>N) res.erase(res.begin()+i);
        }
        return res;
    }
    vector<int> helper(int N){
        if(N==1) return {1};
        vector<int> v;
        if(N&1)  
            v = helper((N+1)/2);
        else 
            v = helper(N/2);

        for(int i=0;i<v.size();++i) {
            v[i] = 2*v[i] - 1;
        }
        int l = v.size();
        for(int i=0;i<l;++i) {
            v.push_back(v[i]+1);
        }
        return v;
    }


};