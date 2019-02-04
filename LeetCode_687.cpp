class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int max=0;
        longestPath(root,max);
        return max;
    }
    
    int longestPath(TreeNode* root,int& max)
    {
        if(!root)
            return 0;
        int l=longestPath(root->left,max);
        int r=longestPath(root->right,max);
        int pl=0, pr=0;
        if(root->left && root->left->val==root->val)
        {
            pl=l+1;
        }
        if(root->right && root->right->val==root->val)
        {
            pr=r+1;
        }
        max=std::max(max,pl+pr);
        return std::max(pl,pr);
    }
};
