// Insert in a Sorted Stack

void insertSorted(stack<int>&st, int num){
    //base case
    if(st.empty() || st.top() < num){
        st.push(num);
        return;
    }
    //1 case hum solve krenge
    int temp = st.top();
    st.pop();
    
    //recursion
    insertSorted(st,num);
    
    //backtrack
    st.push(temp);
}


// Sort a Stack 

//Using Recursion
void sortStack(stack<int>&st){
    //base case
    if(st.empty()){
        return;
    }
    //1 case hum solve krenge
    int temp = st.top();
    st.pop();
    
    //recursion
    sortStack(st);
    
    //backtrack
    insertSorted(st,temp);
}