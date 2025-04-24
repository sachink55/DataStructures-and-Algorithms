//leetcode-25 : Reverse Nodes in k-Group

class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len =0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head);
        if(len < k){
            return head;
        }
        // Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = curr->next;
        int pos = 1;

        while(pos <= k){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }
        
        //Now attach the recursion ka ans 
        ListNode* recursionKaAns = NULL;
        if(nextNode != NULL){
            recursionKaAns = reverseKGroup(nextNode, k);
            head->next = recursionKaAns;
        }
        return prev;
    }
};