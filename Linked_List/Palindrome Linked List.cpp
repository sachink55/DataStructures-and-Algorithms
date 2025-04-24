//leetcode-234: Palindrome Linked List

//Approach-1:
//step1- break the list into 2 halves
//step2- reverse second half
//step3- compare both linked lists

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
                // we are able to move fast pointer 2 steps. so we will move
                // slow by 1 steps
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseLL(ListNode* prev, ListNode* curr) {
        // base case
        if (curr == NULL) {
            return prev;
        }

        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        ListNode* ans = reverseLL(prev, curr);
        return ans;
    }

    bool compareLists(ListNode* head1, ListNode* head2) {
        while (head2 != NULL) {
            if (head1->val != head2->val) {
                return false;
            } else {
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        // Break the List
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        // revesre the second half
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseLL(prev, curr);

        // compare both linked lists
        bool ans = compareLists(head, head2);
        return ans;
    }
};


//Approach-2: 

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev = NULL;

        // Reverse the first half while finding the middle
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // If the list has odd elements, skip the middle node
        if (fast) slow = slow->next;

        // Compare reversed first half with the second half
        while (prev && slow) {
            if (prev->val != slow->val) return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};
