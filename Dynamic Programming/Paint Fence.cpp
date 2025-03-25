//leetcode - 278 : Paint Fence

//Approach - 1 : Memoization
//T.C. : O(n)
//S.C. : O(n)

class solution{
    public:
        int solveusingMem(int n, int k, vector<int>&dp){
            //base case
            if(n==1)
                return k;
            if(n==2)
                return k + k*(k-1);

           dp[n] = (solve(n-2,k,dp) + solve(n-1,k,dp)) * (k-1);
           return dp[n];
        }

        int numWays(int n, int k){
            vector<int>dp(n+1, -1);
            return solveUsingMem(n,k,dp);
        }
};

//.............................................................
//Approach - 2 : Tabulation
//T.C. : O(n)
//S.C. : O(n)

class solution{
    public:
        int solveusingTabulation(int n, int k){
            vector<int>dp(n+1, -1);
            dp[1] = k;
            dp[2] = k-1;

            for(int i=3; i<=n; i++){
                dp[i] = (dp[i-2] + d[i-1]) * (k-1);
            }
            return dp[n];
        }

        int numWays(int n, int k){
            return solveUsingTabulation(n,k);
        }
}

//Tabulation : Space Optimisation
//T.C. : O(n)
//S.C. : O(1)

class solution{
    public:
        int solveusingTabulationSO(int n, int k){
            int prev2 = k;
            int prev1 = k-1;

            if(n==1)
                return prev2;
            if(n==2)
                return prev1;
            int curr;
            for(int i=3; i<=n; i++){
               curr = (prev1 + prev2) * (k-1);
               prev2 = prev1;
               prev1 = curr;
            }
            return curr;
        }

        int numWays(int n, int k){
            return solveUsingTabulationSO(n,k);
        }
};
