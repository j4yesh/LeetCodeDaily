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
    bool isCompleteTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool fleg=false;
        while(!q.empty()){
            TreeNode *pick=q.front();
            q.pop();
            if(pick->left!=NULL){
                if(fleg)return false;
                q.push(pick->left);
            }else{
                fleg==true;
            }
            if(pick->right!=NULL){
                if(fleg==true){return false;}
                q.push(pick->right);
            }else{
                fleg=true;
            }
        }
        return true;
    }
};
