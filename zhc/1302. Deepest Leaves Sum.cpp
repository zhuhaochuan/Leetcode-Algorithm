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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        if(!root) return res;
        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* back = queue.front();
        while(!queue.empty()) {
            TreeNode* cur = queue.front();
            queue.pop();
            res += cur->val;
            if(cur->left) queue.push(cur->left);
            if(cur->right) queue.push(cur->right);
            if(cur==back) {
                back = queue.back();
                if(queue.empty()) return res;
                res = 0;
            }
        }
        return res;
    }
};