#include<bits/stdc++.h>
using namespace std;

int knapsackMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>>&dp){
    //base case
    if(index >= n)
        return 0;
    
    //already exists
    if(dp[capacity][index] != -1)
        return dp[capacity][index];

    //include
    int include = 0;
    if(wt[index] <= capacity)
        include = profit[index] + knapsackMem(capacity - wt[index], wt, profit, index+1, n, dp);
    
    //exclude
    int exclude = knapsackMem(capacity, wt, profit, index+1, n, dp);

    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

int solveUsingTabulation(int capacity, int wt[], int profit[], int n){
    vector<vector<int>>dp(capacity+1, vector<int>(n+1,-1));

    for(int i=0; i<=capacity; ++i){
        dp[i][n] = 0;
    }

    for(int i=0; i<=capacity; ++i){
       for(int j=n-1; j>=0; j--){
            //include
            int include = 0;
            if(wt[j] <= i){
               include = profit[j] + dp[i - wt[j]][j+1];
            }
            //exclude
            int exclude = dp[i][j+1];

            dp[i][j] = max(include, exclude);
       }
    }
    return dp[capacity][0];
}

// Space Optimisation with 2 arrays
int solveSO1(int capacity, int wt[], int profit[], int n){
    vector<int>next(capacity+1, 0);
    vector<int>curr(capacity+1, 0);

    for(int j=n-1; j>=0; j--){
        for(int i=0; i<=capacity; ++i){
            //include
            int include = 0;
            if(wt[j] <= i){
            include = profit[j] + next[i - wt[j]];
            }
            //exclude
            int exclude = next[i];
            curr[i] = max(include, exclude);
        }
        //shifting 
        next = curr;
    }
    return curr[capacity];
}

// Space Optimisation with 1 array
int solveSO2(int capacity, int wt[], int profit[], int n){
    vector<int>next(capacity+1, 0);

    for(int j=n-1; j>=0; j--){
        for(int i=capacity; i>=0; i--){
            //include
            int include = 0;
            if(wt[j] <= i){
            include = profit[j] + next[i - wt[j]];
            }
            //exclude
            int exclude = next[i];
            next[i] = max(include, exclude);
        }
    }
    return next[capacity];
}

int main(){
    int capacity = 6;
    int wt[] ={1,2,3};
    int profit[] = {10,15,40};
    // int index = 0;
    int n = 3;

    //vector<vector<int>>dp(capacity+1, vector<int>(n+1,-1));
    int ans = solveSO2(capacity, wt, profit, n);
    cout << "Max Profit : " << ans << endl;
    return 0;
}