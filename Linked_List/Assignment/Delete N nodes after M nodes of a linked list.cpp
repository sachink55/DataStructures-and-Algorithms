//gfg - Delete N nodes after M nodes of a linked list

class Solution {
  public:
   
    Node* linkdelete(Node* head, int n, int m) {
        Node* temp = head;
        Node* prev = NULL;
        
        while(temp){
            for(int i=1; i<=m && temp!=NULL; i++){
                prev = temp;
                temp = temp->next;
            }
            
            if(temp == NULL){
                return head;
            }
            
            Node* to_delete = temp;
            for(int i=1; i<=n && to_delete != NULL; i++){
                Node* nextNode = to_delete->next;
                delete to_delete;
                to_delete = nextNode;
            }
            prev->next = to_delete;
            temp = to_delete;
        }
        return head;
    }
};