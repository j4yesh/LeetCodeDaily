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
    int x;
    TreeNode *builify(vector<int>inorder,vector<int>postorder){
          if (inorder.size() == 0 || postorder.size() == 0) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder.back());
        if (postorder.size() == 1) {
            return root;
        }

        //inorder sirf left deta
        int left=0,right=inorder.size()-1;

auto pos = find(begin(inorder), end(inorder), postorder.back()) - inorder.begin();

         vector<int> IL(inorder.begin(), inorder.begin() + pos);
        vector<int> IR(inorder.begin() + pos + 1, inorder.end());
        vector<int> PL(postorder.begin(), postorder.begin() + pos);
        vector<int> PR(postorder.begin() + pos, postorder.end() - 1);

        root->left=builify(IL,PL);
        root->right=builify(IR,PR);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int right=inorder.size();
        TreeNode *root=builify(inorder,postorder);
        return root;
    }
};
