 //leetcode-84: Largest Rectangle in Histogram

 //TC: O(n)
 //SC: O(n)
 
class Solution {
public:
    // returns the index of the next smaller element
    vector<int> nextIndex(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int num = heights[i];
            while (st.top() != -1 && heights[st.top()] >= num) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    // returns the index of the previous smaller element
    vector<int> prevIndex(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int num = heights[i];
            while (st.top() != -1 && heights[st.top()] >= num) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextIndex(heights, n);
        vector<int> prev = prevIndex(heights, n);

        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (next[i] == -1) {
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            int currArea = width * heights[i];
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};