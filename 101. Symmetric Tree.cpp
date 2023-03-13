/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    
    private bool sectify(TreeNode a,TreeNode b){
            if (a == null || b == null)
            {
                return a == b;
            }
            if(a.val!=b.val){
                return false;
            }
            return sectify(a.left, b.right) && sectify(a.right, b.left);
        }
    public bool IsSymmetric(TreeNode root) {
        if(root==null){
            return true;
        }
        return sectify(root.left,root.right);
    }
}

//ALternative

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
 #define MEN INT_MIN
class Solution {
private: bool checkify(TreeNode *t1, TreeNode *t2){
            int al = MEN, ar = MEN, bl = MEN, br = MEN;
            if (t1->left != NULL) {
                al = t1->left->val;
            }
            if (t1->right != NULL) {
                ar = t1->right->val;
            }
            if (t2->left != NULL) {
                bl = t2->left->val;
            }
            if (t2->right != NULL) {
                br = t2->right->val;
            }
            cout<<"----------------------\n";
            cout<<"al:"<<al<<endl;
            cout<<"br:"<<br<<endl;
            cout<<"ar:"<<ar<<endl;
            cout<<"bl:"<<bl<<endl;
            cout<<"----------------------\n";
            if (al != bl || (al == MEN && bl != MEN)) {
                return true;
            }
            if (ar != br || (ar == MEN && br != MEN)) {
                return true;
            }
            return false;
}
TreeNode* mirror(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        swap(node->left, node->right);
        if (node->left != nullptr) {
            stk.push(node->left);
        }
        if (node->right != nullptr) {
            stk.push(node->right);
        }
    }
    return root;
}

public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *l=root->left;
        l=mirror(root->left);
        TreeNode *r=root->right;

        if ((l == nullptr && r != nullptr) || 
    (l != nullptr && r == nullptr) || 
    (l != nullptr && r != nullptr && l->val != r->val)) {
    return false;
        }
        if(l == nullptr && r == nullptr){
            return true;
        }

        queue<TreeNode*>st1;
        queue<TreeNode*>st2;
        st1.push(root->left);
        st2.push(root->right);
        while(!st1.empty() && !st2.empty()){
            TreeNode *t1=st1.front();
            TreeNode *t2=st2.front();
            cout<<t1->val<<" "<<t2->val<<endl;
            if(checkify(t1,t2)){
                return false;
            }
            st1.pop();
            st2.pop();
            int al=MEN,ar=MEN,bl=MEN,br=MEN;
            if(t1->left!=NULL){
                st1.push(t1->left);
                al=t1->left->val;
            }
            if(t1->right!=NULL){
                st1.push(t1->right);
                ar=t1->right->val;
            }
            if(t2->left!=NULL){
                st2.push(t2->left);
                bl=t2->left->val;
            }
            if(t2->right!=NULL){
                st2.push(t2->right);
                br=t2->right->val;
            }
        }

        return true;
    }
};
