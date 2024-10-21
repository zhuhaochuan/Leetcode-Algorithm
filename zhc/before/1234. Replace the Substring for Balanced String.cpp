class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int c = n/4;
        //"QQWEQQQW"
        unordered_map<char,int> map;
        map['Q'] = 0;
        map['W'] = 1;
        map['E'] = 2;
        map['R'] = 3;
        vector<int> table(4,0);
        int l=0,r=0;
        for(int i=0;i<n;++i) {
            table[map[s[i]]]++;
        }
        if(table[0]==table[1]&&table[1]==table[2]&&table[2]==table[3]) 
            return 0;
        int res = n;

        while(r<=n) {
            if(!helper(table,c)) {
                table[map[s[r]]]--;
                r++;
            }
            else {
                res = min(res,r-l);
                table[map[s[l]]]++;
                l++;
                
            }
        }
       
        return res;
    }
    bool helper(vector<int>& v,int c){
        for(int i=0;i<4;++i) {
            if(v[i]>c) return false;
        }
        return true;
    }
};