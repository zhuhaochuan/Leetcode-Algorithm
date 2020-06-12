class Solution {
public:
    bool checkValidString(string s) {
        bool res = false;
        helper(s,res,0,0);
        return res;
    }
    void helper(string& s,bool& res,int count,int index){
        int n = s.size();
        if(count<0||res) return;
        if(index>=n) {
            if(count==0){
                res = true;
            }
            return;
        }
        if(s[index]=='(') {
            helper(s,res,count+1,index+1);
        }else if(s[index]==')'){
            helper(s,res,count-1,index+1);
        }else{
            helper(s,res,count,index+1);
            helper(s,res,count-1,index+1);
            helper(s,res,count+1,index+1);
        }
    }
};