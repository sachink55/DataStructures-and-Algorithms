//leetcode-21: Merge Two Sorted Lists

//Approach-1 : Using Recursion
//TC: O(n+m)
//SC: O(n+m), due to recursive calls

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)  return list2;
        if(!list2)  return list1;

        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};


//......................................................................................................
 //Approach-2: Using Merge Logic
 //TC: O(n + m)
 //SC: O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        if(!list1)  return list2;
        if(!list2)  return list1;

        //ptr to the list starting with smaller number
        ListNode* ptr = list1;
        if(list1->val > list2->val){
            ptr = list2;
            list2 = list2->next;
        } else{
            list1 = list1->next;
        }
        
        ListNode* curr = ptr;
        while(list1 && list2){
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // adding remaining elements of bigger list.
        if (!list1)
            curr->next = list2;
        else
            curr->next = list1;

        return ptr;
    }
};