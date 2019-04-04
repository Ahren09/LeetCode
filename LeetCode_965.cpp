//First Solution using DFS
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;
        bool isUnival=true;
        if(root->left)
            isUnival=isUnival && root->left->val==root->val;
        if(root->right)
            isUnival=isUnival && root->right->val==root->val;
        return isUnival && isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

//Second Solution: Using helper function
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
    
    bool dfs(TreeNode* root, int val){
        if(!root) return true;
        if(root->val!=val) return false;
        return dfs(root->left,val) && dfs(root->right,val);
        
    }
    
};


//3rd using BFS
class Solution {
public:
bool isUnivalTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int value=root->val;
    while(!q.empty())
    {
        TreeNode* tmp=q.front();
        q.pop();
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
        if(tmp->val!=value)
            return false;
    }
    return true;
}
};
