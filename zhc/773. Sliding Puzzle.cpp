class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int x = 0,y = 0;
        for(int i=0;i<2;++i) {
            for(int j=0;j<3;++j) {
                if(board[i][j]==0) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int res = 0;
        int status = board[0][0]*100000 + board[0][1]*10000 + board[0][2]*1000 + board[1][0]*100 + board[1][1]*10 + board[1][2];
        unordered_set<int> path;
        queue<int> bsf_path;
        bsf_path.push(status);
        bsf_path.push(-1);
        
        while(!bsf_path.empty()) {
            status = bsf_path.front();
            bsf_path.pop();
            if(status==-1) {
                bsf_path.push(-1);
                res++;
                continue;
            }
            if(path.count(status)) continue;
            if(status==123450) return res;
            if(status==123540) return -1;
            string s = to_string(status);
            //bug容易出现 当0出现在头部的时候s->int会丢失这个0
            //转回s的时候需要做判断
            if(status<100000) {
                s = "0" + s;
            }
            path.insert(status);
            helper(s,bsf_path);
        }
        return -1;
    }
    void helper(string s,queue<int>& bsf_path){
        int index = 0;
        for(int i=0;i<s.size();++i) {
            if(s[i]=='0'){
                index = i;
                break;
            }
        }
        //上
        if(index-3>=0) {
            string up = s;
            swap(up[index-3],up[index]);
            bsf_path.push(stoi(up));
        }
        if(index+3<6) {
            string down = s;
            swap(down[index+3],down[index]);
            bsf_path.push(stoi(down));
        }
        if((index-1>=0)&&(index-1!=2)) {
            string left = s;
            swap(left[index-1],left[index]);
            bsf_path.push(stoi(left));
        }
        if((index+1<6) && (index+1!=3)){
            string right = s;
            swap(right[index+1],right[index]);
            bsf_path.push(stoi(right));
        }
        return;

    }

};