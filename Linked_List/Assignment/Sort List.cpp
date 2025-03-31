//leetcode-148: Sort List

class Solution {
public:
    ListNode* findMid(ListNode* &head){
        ListNode*slow= head;
        ListNode*fast= head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }

     ListNode* merge(ListNode* &left, ListNode* &right){
        if(!left) return right;
        if(!right) return left;
        ListNode* dummy= new ListNode(-1);  //dummy node
        ListNode* ptr = dummy;

        while(left && right){
            if(left->val <= right->val){
                ptr->next=left;
                ptr=left;
                left=left->next;
            }
            else{
                ptr->next=right;
                ptr=right;
                right=right->next;
            }
        }
        while(left!=NULL){
            ptr->next=left;
            ptr=left;
            left=left->next;
        }
        while(right!=NULL){
            ptr->next=right;
            ptr=right;
            right=right->next;
        }
        return dummy->next;
    }


    ListNode* sortList(ListNode* head) {
         if(head==NULL || head->next==NULL){
            return head;
        }

        //break into two halves
        ListNode* mid= findMid(head);
        ListNode* left= head;
        ListNode* right= mid->next;
        mid->next=NULL;
        
        //Sort 
        left  = sortList(left);
        right = sortList(right);

        ListNode* mergeLL= merge(left,right);
        return mergeLL; 
    }
};