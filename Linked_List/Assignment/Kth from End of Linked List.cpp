//gfg - Kth from End of Linked List

//Approach-1: Brute Force
//TC: O(2N)
//SC: O(1)

class Solution {
  public:
    int getLength(Node* head){
        int len = 0;
        Node* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    int getKthFromLast(Node *head, int k) {
        Node* curr = head;
        int len = getLength(head);
        if(k > len) return -1;
        
        int KthfromEnd = len-k+1;
        
        int i = 0;
        while(curr){
            i++;
            if(i == KthfromEnd){
                return curr->data;
            }
            curr = curr->next;
        }
        return -1;
    }
};

//Approach-2: Using Recursion
//TC: O(n)
//SC: O(n)
class Solution {
  public:
    
    int fun(Node *head, int &k) {
        if (!head) return -1;
        int ans = fun(head->next, k);
        k--;  
    
        if (k == 0) return head->data;  
        return ans; 
    }

    int getKthFromLast(Node *head, int k) {
        return fun(head, k);
    }

};

//Approach-3: Using first and second pointer - OPTIMAL
//TC: O(n)
//SC: O(1)

class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        Node *first = head, *second = head;

        // Move first k steps
        for (int i = 0; i < k; i++) {
            if (!first) return -1; // If k is greater than list length
            first = first->next;
        }

        // Move both first and second until first reaches the end
        while (first) {
            first = first->next;
            second = second->next;
        }

        return second->data; // second now points to the kth node from the end
    }
};
