//leetcode-1823: Find the Winner of the Circular Game

// Josephus Probelm.
// Recursive Relation=>

//0-indexed: josephus(n, k) = (josephus(n-1, k) + k) % n           base case: josephus(1, k) = 0
//1-indexed: josephus(n, k) = (josephus(n-1, k) + k - 1) % n + 1   base case: josephus(1, k) = 1


// Appraoch-1: Recursive
// TC: O(n)
// SC: O(n) + O(n) = O(n) for recursion stack and dp array
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> dp(n+1, -1);
        return josephus(n, k, dp);
    }
    int josephus(int n, int k, vector<int>& dp) {
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        dp[n] = (josephus(n - 1, k, dp) + k - 1) % n + 1;
        return dp[n];
    }
};

//Approach-2: Using Queue
// TC: O(n*k) => O(n^2) in worst case
// SC: O(n)

class Solution {
public:
    int findTheWinner(int n, int k) {
        //all players should go into the queue
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        //simulate the game
        while (q.size() > 1) {
            for (int i = 0; i < k - 1; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop(); // Remove the k-th person
        }
        
        return q.front();
    }
};
