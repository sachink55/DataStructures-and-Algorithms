//leetcode-2327: Number of People Aware of a Secret

// Approach-1: Simulation - Using Queue
// TC: O(n)
// SC: O(n)

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9 + 7;
        int curr = 0; // active spreader
        int ans = 1; // people aware of the secret
        queue<pair<int, int>> delayQ, forgetQ;
        // ith day pe kitne logo ko secret pta lga
        delayQ.push({1, 1});
        forgetQ.push({1, 1});

        for(int i = 1; i <= n; ++i){
            // step1: active spreader and person know about secret reduce kro
            while(!forgetQ.empty() && forgetQ.front().first + forget <= i){
                auto front = forgetQ.front();
                forgetQ.pop();
                auto num = front.second;
                ans = (ans - num + M) % M; // modulo add kr diya
                curr = (curr - num + M) % M; 
            }

            //step2: make new active spreaders
            while(!delayQ.empty() && delayQ.front().first + delay <= i){
                auto front = delayQ.front();
                delayQ.pop();
                curr = (curr + front.second) % M; // active kr diya
            }
            // step3: Add new spreaders
            if(curr > 0){
                ans = (ans + curr) % M;
                delayQ.push({i, curr});
                forgetQ.push({i, curr});
            }
        }
        return ans;
    }
};

// Approach-2: Using DP
// TC: O(n)
// SC: O(n)

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1; // first person knows the secret

        for (int i = 1; i <= n; ++i) {
            // If the person is not aware of the secret, continue
            if (dp[i] == 0) continue;

            // Calculate the range of days when this person can spread the secret
            int startSpread = i + delay;
            int endSpread = min(i + forget, n + 1); // exclusive

            // Update the dp array for the days when this person spreads the secret
            for (int j = startSpread; j < endSpread; ++j) {
                dp[j] = (dp[j] + dp[i]) % M;
            }
        }

        // Calculate the total number of people aware of the secret
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; ++i) {
            ans = (ans + dp[i]) % M;
        }

        return ans;
    }
};
