//leetcode-225: Implement Stack using Queues

class MyStack {
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        queue<int> q2;
        q2.push(x);
        while (!q.empty()) {
            q2.push(q.front());
            q.pop();
        }
        q = q2;
    }

    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
