class Solution {
public:
    int ans=INT_MIN;
int path(TreeNode* root){
        if(!root)return 0;
        int lp=path(root->left);
        int rp=path(root->right);
        ans=max(ans,root->val+max({lp,rp,0,lp+rp}));
        return root->val+max({lp,rp,0});
    }
int maxPathSum(TreeNode* root) {
        path(root);
        return ans;
    }
};
