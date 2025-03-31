//leetcode-206 : Reverse a Linked List

//TC: O(n), n: no of nodes

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    //update head
    head = prev;

    return head;
}


//Using Recursion:
Node* usingRecursion(Node* prev, Node* curr){
    //base case
    if(curr == NULL){
        return prev;
    }

    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;

    return usingRecursion(prev, curr);
}

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    return usingRecusrsion(prev, curr);
}