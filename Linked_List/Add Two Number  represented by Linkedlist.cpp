//leetcode-2 : Add Two Numbers represented by Linked List

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1); //dummy node
        ListNode* curr = dummy;
        int carry = 0;

        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            curr->next = new ListNode(sum%10);
            carry = sum / 10;
            curr = curr->next;
        }

        return dummy->next; //returning actual head
    }
};

