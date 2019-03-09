class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* p=root;
        TreeNode* newNode=new TreeNode(val);
        while(p)
        {
            if(val<p->val)
            {
                if(p->left)
                    p=p->left;
                else 
                {
                   p->left=newNode; 
                    break;
                }
            }
            else if(val>p->val)
            {
                if(p->right)
                    p=p->right;
                else 
                {
                    p->right=newNode;
                    break;
                }
            }
                
        }
        
        return root? root:newNode;
            
    }
};
