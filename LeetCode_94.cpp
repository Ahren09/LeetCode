//Recursive solution

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(res,root);
        return res;
    }
    void helper(vector<int>& res,TreeNode* root)
    {
        if(!root)
            return;
        helper(res,root->left);
        res.push_back(root->val);
        helper(res,root->right);
    }
};
