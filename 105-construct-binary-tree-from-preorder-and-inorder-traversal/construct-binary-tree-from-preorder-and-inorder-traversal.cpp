/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int index=0;
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return helper(preorder,0,inorder.size()-1);
    }
    TreeNode* helper(vector<int> preorder, int st, int end){
        if(st>end) return NULL;
        int rootv=preorder[index++];
        TreeNode* root=new TreeNode(rootv);
        int mid=mp[rootv];
        root->left=helper(preorder,st,mid-1);
        root->right=helper(preorder,mid+1,end);
        return root;
    }
};