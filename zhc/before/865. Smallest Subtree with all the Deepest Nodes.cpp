/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct node {
    int deep;
    TreeNode* n;
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //找到最深的所有节点的第一个公共祖先
        //层序遍历的最后一层就是最深节点
        //树形dp
        if(!root) return NULL;
        node res = helper(root);
        return res.n;
    }

    node helper(TreeNode* root){
        if(!root) return node{0,NULL};
        node n1 = helper(root->left);
        node n2 = helper(root->right);
        if(n1.deep>n2.deep) return node{n1.deep+1,n1.n};
        else if(n2.deep>n1.deep) return node{n2.deep+1,n2.n};
        else return node{n1.deep+1,root}; 
    }
};