class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string res;
        if(n<2) return res;
        stack<char> stack;

        for(int i=0;i<n;++i) {
            if(s[i]!=')'){
                stack.push(s[i]);
            }else {
                string temp;
                while(stack.top()!='('){
                    char cur = stack.top();
                    stack.pop();
                    temp += cur;
                }
                stack.pop();
                for(auto c:temp) {
                    stack.push(c);
                }
            }
        }
        
        while(!stack.empty()){
            res = stack.top() + res;
            stack.pop();
        }

        return res;
    }
};