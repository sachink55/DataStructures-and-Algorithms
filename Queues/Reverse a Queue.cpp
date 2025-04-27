// Reverse a Queue 

void reverseQueue(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}


//Using Recursion
void reverseQueueRec(queue<int> &q)
{
    // base case
    if (q.empty())
        return;
    int top = q.front();
    q.pop();
    reverseQueueRec(q);
    q.push(top);
}