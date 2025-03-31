//Starting Point of the Loop in a Linked List

Node* startingPoint(Node* head){
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
    //return starting point
    return slow;
}