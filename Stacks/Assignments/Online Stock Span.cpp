//leetcode-901: Online Stock Span

//Approach: Using Monotonic Stack

//We can use a stack to keep track of the prices and their spans.
//For each price, we pop elements from the stack until we find a price that is greater than the current price.
//and update the span accordingly.

//TC: O(n)
//SC: O(n)
//
class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};