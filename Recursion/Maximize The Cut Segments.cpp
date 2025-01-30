//gfg - Maximize The Cut Segments

//Approach-1 : Using Recursion
//T.C : O(3^n)
//S.C : O(n)

int maximizeTheCuts(int n, int x, int y, int z){
    // Two Base cases: 
    if (n == 0) {
        return 0;
    }   
    // If the length becomes negative, return INT_MIN to indicate invalid cut
    if (n < 0) {
        return INT_MIN;
    }   

    //Cut a segment of x length
    int opt1 = 1 + maximizeTheCuts(n-x, x, y, z);

    //Cut a segemnt of y length
    int opt2 = 1 + maximizeTheCuts(n-y, x,y,z);

    //Cut a segment of z length
    int opt3 = 1 + maximizeTheCuts(n-z, x,y,z);

    int ans = max(opt1, max(opt2, opt3));

    return ans;
}

//.............................................................................
//Approach-2: DP Memoization
//T.C : O(n)
//S.C : O(n)

class Solution
{
public:

    int solve(int n, int x, int y, int z, vector<int>& dp) {

        // Two Base cases: 
        if (n == 0) {
            return 0;
        }   
        // If the length becomes negative, return INT_MIN to indicate invalid cut
        if (n < 0) {
            return INT_MIN;
        }  
        
        // Check if the result for the current length is already calculated
        if (dp[n] != -1) {
            return dp[n];
        }
        
        // Recursive calls for three possible cut lengths (x, y, z)
        int a = solve(n - x, x, y, z, dp) + 1;
        int b = solve(n - y, x, y, z, dp) + 1;
        int c = solve(n - z, x, y, z, dp) + 1;
        
        // Update dp table with the maximum of the three cuts
        dp[n] = max(a, max(b, c));
        
        return dp[n];
    }

    int maximizeTheCuts(int n, int x, int y, int z) {

        vector<int> dp(n + 1, -1);
        
        int ans = solve(n, x, y, z, dp);
        
        if(ans < 0) {
            return 0;
        }
        return ans;
    }
};