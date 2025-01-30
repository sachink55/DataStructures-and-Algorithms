//leetcode - 121 : Best Time to Buy and Sell Stocks

//Approach - 1 : keeping track of min. stock price and checking to sell the stock each day if we found today's profit > maxProfit then update the maxProfit
//T.C : O(n)
//S.C : O(1)

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int maxi = 0;       // Stores the maximum profit
        int mini = INT_MAX; // Stores the minimum stock price

        for (auto x : prices) {
            mini = min(mini, x);        // Update minimum stock price
            maxi = max(x - mini, maxi); // today's profit = x - mini , accordingly Update maximum profit
        }

        return maxi; // Return the maximum profit
    }
};

//Approach - 2 : Using Recursion
//T.C : O(n)
//S.C : O(n)

class Solution {
public:

    void maxProfitFinder(vector<int>&prices, int i, int &minPrice, int &maxProfit){
        //base case
        if(i >= prices.size()){
            return;
        }
        //ek case khud se
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        if(prices[i] - minPrice > maxProfit){
            maxProfit = prices[i] - minPrice;
        }
        //recursion
        maxProfitFinder(prices, i+1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        
        int maxProfit = INT_MIN;
        int minPrice = INT_MAX;

        maxProfitFinder(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};