//Given an array find the next smaller element for each element in the array.

//TC: O(n) => O(n+n) worst case: every element push & pop
//SC: O(n)

vector<int> nextSmallerElement(vector<int>& arr) {
    stack<int> st;
    st.push(-1); // Initialize stack with -1 to handle edge case
    vector<int> ans(arr.size(), -1); // Initialize answer array with -1

    for(int i=size-1; i>=0; i--){
        int curr = arr[i];
        //ans find karo curr ke liye
        while(st.top() >= curr){
            st.pop();
        }

        ans[i] = st.top(); 
        st.push(curr); // Push current element onto the stack
    }
    return ans;
}