//When we go back from the left sub-tree to root, the stack is empty!
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        while(!s.empty()||root)
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                root=s.top();
                result.push_back(root->val);
                s.pop();
                root=root->right;
            }
        }
        return result;
    }
};
