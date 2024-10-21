/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        map<int,set<pair<int,int>>> table;
        dfs(table,root,0,0);
        for(auto m:table) {
            auto set = m.second;
            vector<int> temp;
            for(auto e:set){
                temp.push_back(e.second);
            }
            res.push_back(temp);
        }
        return res;
    }

    void dfs(map<int,set<pair<int,int>>>& table,TreeNode* root,int x,int y){
        if(!root) return;
        pair<int,int> p{y,root->val};
        table[x].insert(p);
        dfs(table,root->left,x-1,y+1);
        dfs(table,root->right,x+1,y+1);
    }
};