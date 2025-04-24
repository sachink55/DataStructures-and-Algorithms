//leetcode-138: Copy List with Random Pointer

//Approach-1: Using Maps
//TC: O(n)
//SC: O(n)

class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*, Node*>&mp){
        if(head==0)
            return 0;
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = helper(head->next, mp);
        if(head->random){
            newHead->random = mp[head->random];
        }
        return newHead;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;  //old Node ---> new Node
        return helper(head, mp);
    }
};


//Approach-2: 
//TC: O(n)
//SC: O(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return 0;

        //step1 : clone A->A'
        Node* it = head;    //iterate over old list
        while(it){
            Node* clonedHead = new Node(it->val);
            clonedHead->next = it->next;
            it->next = clonedHead;
            it = it->next->next;
        }

        //step2 : assign random links of A' with the help of A
        it = head;
        while(it){
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next: nullptr;
            it = it->next->next;
        }

        //detach A' from A
        it = head;
        Node* clonedHead = it->next;
        while(it){
            Node* clonedNode = it->next;
            it->next = it->next->next;
            if(clonedNode->next){
                clonedNode->next = clonedNode->next->next;
            }
            it = it->next;
        }
        return clonedHead;
    }
};