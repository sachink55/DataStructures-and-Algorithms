// Reverse first K elements of a Queue

void reverseKElements(queue<int> &q, int k)
{
    // edge case
    if (k > q.size() || k == 0)
        return;
    stack<int> st;
    // push first k elements in stack
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    // pop from stack and push in queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    // remaining elements in queue
    // push them in queue
    int n = q.size();
    for (int i = 0; i < n - k; i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

