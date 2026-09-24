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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l=max(p->val,q->val);
        int s=min(p->val,q->val);
        if(root==NULL) return root;
        while(root!=NULL){
            if(root==p||root==q) return root;
            if(root->val>l) root=root->left;
            else if(root->val<s) root=root->right;
            if(s<=root->val && root->val<=l) return root;
        }
        return NULL;
    }
};