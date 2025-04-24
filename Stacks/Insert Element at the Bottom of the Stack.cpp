//insert an element at the bottom of a stack

void insertAtBottom(stack<int>&st, int num){
    //base case
    if(st.empty()){
        st.push(num);
        return;
    }
    //1 case hum solve krenge
    int temp = st.top();
    st.pop();
    
    //recursion
    insertAtBottom(st,num);

    //backtrack
    st.push(temp);
}