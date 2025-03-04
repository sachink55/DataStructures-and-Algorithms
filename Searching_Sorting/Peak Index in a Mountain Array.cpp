//leetcode - 852 : Peak Index in a Mountain Array

//Approach : Binary Search
//TC : O(logn)
//SC : O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] < arr[mid + 1]) // line A par hain, go right
                s = mid + 1;
            else{
                //peak or B par hain, go left
                e = mid;
            }
        }
        return s;
    }
};

//not doing e = mid - 1, if we do e = mid-1 , then we may miss the peak element, as peak element can be at mid.

//s < e , when s=e , it will go into infinite loop, so we need to check s < e, and not s <= e. when s=e , we have found the peak element, so we can return s.