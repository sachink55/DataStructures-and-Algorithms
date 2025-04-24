//Cycle in a Linked List

//Approach: Brute Force

class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode*, bool>mp;
        ListNode* temp = head;

        while(temp){
            if(mp.find(temp) != mp.end()){
                return true;
            }
            else{
                mp[temp] = true;
            }
            temp = temp->next;
        }
        return false;
    }
};


//Approach-2 : Using Fast and Slow Pointers

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast && fast ->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        return false;
    }
};