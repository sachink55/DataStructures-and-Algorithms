//gfg - Minimum Cost of ropes

class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        int minCost = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int rope:arr){
            minHeap.push(rope);
        }
        
        while(minHeap.size() > 1){
            int top1 = minHeap.top(); minHeap.pop();
            int top2 = minHeap.top(); minHeap.pop();
            
            int currCost = top1 + top2;
            minCost += currCost;
            
            minHeap.push(currCost);
        }
        
        return minCost;
    }
};