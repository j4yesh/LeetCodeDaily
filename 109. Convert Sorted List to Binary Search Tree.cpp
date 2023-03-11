/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *calit(vector<int>&vr,int i,int j){
        if(i>j){
            return NULL;
        }
        int mid=i+(j-i)/2;
        TreeNode *root=new TreeNode(vr[mid]);
        root->left=calit(vr,i,mid-1);
        root->right=calit(vr,mid+1,j);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return NULL;
        }
        vector<int>vr;
        while(head!=NULL){
            vr.push_back(head->val);
            head=head->next;
        }
        int cap=vr.size();
      
        return calit(vr,0,cap-1);
    }
};
