class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)
            return 0;
        if(root->val<L)
           return 0+rangeSumBST(root->right, L, R);
        else if(root->val>R)
           return 0+rangeSumBST(root->left, L, R);
        return root->val+rangeSumBST(root->left, L, R)
            +rangeSumBST(root->right,L,R);
        
    }
};
