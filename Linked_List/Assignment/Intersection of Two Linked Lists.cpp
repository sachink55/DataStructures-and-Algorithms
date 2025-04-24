//leetcode- 160: Intersection of Two Linked Lists

//Approach-Brute Force
//TC: O(m*n)
//SC: O(1)

node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

//....................................................................................................
//Approach-1: Using Two Pointers
//TC: O(m+n)
//SC: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode *a = headA, *b = headB;

        while (a != b) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;  
    }
};

//....................................................................................................
//Approach-2: By Calculating Length
//TC: O(m + n)
//SC: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0;
		int n = 0;
		ListNode* ptr1 = headA;
		ListNode* ptr2 = headB;
		while(ptr1 != NULL){
			m++;
			ptr1 = ptr1 -> next;
		}
		while(ptr2 != NULL){
			n++;
			ptr2 = ptr2 -> next;
		}
		int t = abs(m - n);
		if(m > n){
			while(t){
				headA = headA -> next;
				t--;
			}
		}
		else{
			while(t){
				headB = headB -> next;
				t--;
			}
		}
		while(headA != NULL and headB != NULL){
			if(headA == headB){
				return headA;
			}
			headA = headA -> next;
			headB = headB -> next;
		}
		return NULL;
    }
};


//......................................................................................................
//Approach-3: Using Set
//TC: O(m+n)
//SC: O(m)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set<ListNode*> nodes;

        while (headA) {
            nodes.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (nodes.find(headB) != nodes.end()) {
                return headB;
            }
            headB = headB->next;
        }

        return NULL;
    }
};