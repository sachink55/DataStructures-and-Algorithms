//gfg - Add 1 to a Linked List Number

class Solution {
  public:
    Node* reverseList(Node* head){
        Node* prev = NULL;
        Node* curr = head;
    
        while(curr != NULL){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        // Reverse the linked list
        head = reverseList(head);
        
        // Add 1 to the number
        int carry = 1;
        Node* temp = head;
        Node* prev = NULL; // To keep track of the last processed node
        
        while(temp){
            int totalSum = temp->data + carry;
            temp->data = totalSum % 10;
            carry = totalSum / 10;
            
            prev = temp;
            temp = temp->next;
            
            if (carry == 0) break;
        }
        
        // If there is still a carry after processing all nodes, add a new node
        if (carry) {
            prev->next = new Node(carry);
        }
        
        // Reverse the list back 
        return reverseList(head);
    }
};


