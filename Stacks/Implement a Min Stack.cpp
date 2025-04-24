//leetcode-155: Implement a Min Stack

class MinStack {
public:
    vector<pair<int,int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
       if(st.empty()) {
        pair<int, int>p;
        p.first = val;
        //1st element hai, so value and min. same hoga
        p.second = val;
         st.push_back(p);
       }
       else{
        pair<int, int>p;
        p.first = val;
        int oldMin = st.back().second;
        p.second = min(val, oldMin);
        st.push_back(p);
       }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair <int, int > rightMostPair= st.back();
        return rightMostPair.first;
    }
    
    int getMin() {
        pair <int, int > rightMostPair= st.back();
        return rightMostPair.second;
    }
};
