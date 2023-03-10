class Solution {
private:
public:
    ListNode *root;

    Solution(ListNode* head) {
        this->root=head;
    }
    int rev=0;
    int getRandom() {
        // return root->val;
        int i=1,ans=0;
        ListNode *p=this->root;
        while(p!=NULL){
            if (rand() % i == 0) 
                ans = p->val;
            i++;
            p = p->next;
        }
        return ans;
    }

    int getlength(ListNode *n){
        int l;
        while(n!=NULL)n=n->next;
        return l;
    }
};
