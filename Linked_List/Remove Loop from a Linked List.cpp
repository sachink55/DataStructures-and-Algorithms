//Remove Loop from a Linked List


void removeLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){   //loop detected, break.
            break;
        }
    }

    if(fast == NULL){   //No Cycle
        return NULL;
    }

    slow = head;
    while(fast != slow){    //move 1 step
        slow = slow->next;
        fast = fast->next;
    }
    
    Node* startPoint = slow;
    
    Node* temp = fast           //we can take slow also
    while(temp->next != startPoint){
        temp = temp->next;
    }

    temp->next = NULL;
}