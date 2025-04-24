//leetcode-1109: Next Greater Node In Linked List

//Approach-1: Using Stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr) {
        int size = arr.size();
        stack<int> st;
        st.push(0); 
        vector<int> ans(size, 0); 

        for(int i = size - 1; i >= 0; i--){
            int curr = arr[i];
            //ans find karo curr ke liye
            while(st.top() <= curr && st.top() != 0){
                st.pop();
            }

            ans[i] = st.top(); 
            st.push(curr); // Push current element onto the stack
        }
        return ans;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }

        return nextGreaterElement(arr);
    }
};


//Approach-2: Using Stack of Pairs

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        //creating a stack of pairs to hold index-value pairs
        stack< pair<int,int>> st;

        vector<int>ans;

        int i=0;
        while(head){
            //push 0 for the current node
            ans.push_back(0);

            //check if the stack is not empty and current node value is greater
            //than the value at the top of stack. if true, update ans.
            while(!st.empty() && st.top().second < head->val){
                auto top = st.top(); st.pop();
                ans[top.first] = head->val;
            }

            //push current index-value pair in stack
            st.push({i++, head->val});
            
            //move head to the next node
            head = head->next;
        }

        return ans;
    }
};