class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        unordered_set<string> set(deadends.begin(),deadends.end());
        if (!check(deadends,target,set)) return -1;
        queue<string> path;
        string cur = "0000";
        path.push(cur);
        path.push("-1");
        int res = 0;
        while(!path.empty()) {
            cur = path.front();
            path.pop();
            if(set.count(cur)) continue;
            if(cur==target) return res;
            if(cur=="-1") {
                if(path.empty()) break;
                res += 1;
                path.push("-1");
                continue;
            }
            move(path,cur);
            set.insert(cur);
        }
        return -1;
    }
    bool check(vector<string>& deadends, string target,unordered_set<string>& set) {
        for(int i=0;i<4;++i) {
            string s = target;
            char c = target[i];
            if(c=='0'){
                s[i] = '9';
                if(!set.count(s)) return true;
                s[i] = '1';
                if(!set.count(s)) return true;
            }
            else if(c=='9') {
                s[i] = '8';
                if(!set.count(s)) return true;
                s[i] = '0';
                if(!set.count(s)) return true;
            }
            else {
                char temp = s[i];
                s[i] = temp + 1;
                if(!set.count(s)) return true;
                s[i] = temp - 1;
                if(!set.count(s)) return true;
            }
        }
        return false;
    }
    
    void move(queue<string>& path,string cur) {
        for(int i=0;i<4;++i) {
            string s = cur;
            char c = cur[i];
            if(c=='0'){
                s[i] = '9';
                path.push(s);
                s[i] = '1';
                path.push(s);
            }
            else if(c=='9') {
                s[i] = '8';
                path.push(s);
                s[i] = '0';
                path.push(s);
            }
            else {
                char temp = s[i];
                s[i] = temp + 1;
                path.push(s);
                s[i] = temp - 1;
                path.push(s);
            }
        }
    }
};