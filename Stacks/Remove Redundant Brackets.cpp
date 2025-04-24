//Remove Redundant Brackets

//Appraoch-1
bool checkRedundant(string &s){
    stack<char> st;
    int n = s.size();
    for(int i=0; i<n; i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            int operatorCont = 0;
            while(!st.empty() && st.top() != '('){
                char top = st.top();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    operatorCont++;
                    st.pop();
                }
            }
            st.pop(); // pop the '('
            if(operatorCont == 0) return true; // Redundant brackets found
        }
    }
    return 0;
}

//Approach-2
bool isRedundant(string &s) {
    stack<char> st;
    for (char c : s) {
        if (c == ')') {
            char top = st.top();
            st.pop();
            bool isRedundant = true;
            while (top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
                top = st.top();
                st.pop();
            }
            if (isRedundant) return true;
        } else {
            st.push(c);
        }
    }
    return false;
}