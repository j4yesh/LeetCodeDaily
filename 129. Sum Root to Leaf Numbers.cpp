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
private: 
    vector<int>vec;
    void calitor(TreeNode *root,int sum){
        if(root->left==NULL && root->right==NULL){
            vec.push_back(sum*10+root->val);
            return;
        }
        if(root->left!=NULL){
            calitor(root->left,sum*10+root->val);
        }
        if(root->right!=NULL){
            calitor(root->right,sum*10+root->val);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        calitor(root,0);
        for(auto it: vec){
            cout<<it<<" ";
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};
