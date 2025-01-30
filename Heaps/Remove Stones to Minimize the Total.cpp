//Remove Stones to minimize the total -- leetcode-1962

//Approach - in each iteration take biggest pile and keep removing floor(piles[i]/2) until k=0
//T.C : O((n+k)logn)
//S.C : O(n) 
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        for(int i=0; i<piles.size(); i++) {             //O(nlogn)
            int element = piles[i];
            maxHeap.push(element);
        }

        while(k--) {                                    //O(klogn)
            int topElement = maxHeap.top();
            maxHeap.pop();

            topElement = topElement - topElement/2;

            maxHeap.push(topElement);
        }

        int sum = 0;
        while(!maxHeap.empty()) {                      //O(nlogn)
            int top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }
        return sum;
    }
};