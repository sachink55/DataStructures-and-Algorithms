//leetcode-23 : Merge K Sorted Lists

//Appraoch - Process first element of each list using a minHeap and take the top of minHeap , insert it into the new list. jis list ka top node remove hoga, usi ka next element insert hoga.

//T.C : O(nlogk)
//S.C : O(n + k) 

class compare{
     public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        } 
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        //process first element of every LL
        for(int i=0; i<lists.size(); i++) {
            ListNode* listHead = lists[i];
            if(listHead != NULL) {
                pq.push(listHead);
            }
        }

        ///for new LL
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()) {
            ListNode* topNode = pq.top();
            pq.pop();

            //ye frontNode jo nikali h, 
            //ye hamari first node ho
            if(head == NULL) {
                ///pehli node insert krra hu
                head = topNode;
                tail = topNode;
                if(tail->next != NULL) {
                    pq.push(tail->next);
                }
            }
            else {
                //pehle ke baad me koi node insert krra hu
                tail->next = topNode;
                tail = topNode;
                if(tail->next != NULL) {
                    pq.push(tail->next);
                }
            }
        }

    return head;  
    }
};