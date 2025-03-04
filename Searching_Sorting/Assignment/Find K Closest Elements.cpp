//leetcode-658 : Find K Closest Elements

//Approach-1 : Using Two Pointers
//TC: O(n-k)  SC : O(k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, h = arr.size() - 1;

        while (h - l >= k) {
            if (x - arr[l] > arr[h] - x) {
                l++;
            } else {
                h--;
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + h + 1);
    }
};


//Approach-2 : Using Two Pointers and Binary Search - find lower bound and expand.
//TC :  O(log n + k)   SC: O(k)

class Solution {
public:
    //Time Complexity : O(logn)
    int lowerBound(vector<int>& arr, int x) {
        int start = 0, end = arr.size() - 1;
        int ans = end;
        while (start <= end) {          
            int mid = (start + end) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                end = mid - 1;
            } 
            else if (arr[mid] < x) {
                start = mid + 1;
            } 
            else
                end = mid - 1;
        }
        return ans;
    }
   
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //lower bound
        int h = lowerBound(arr, x);
        int l = h - 1;
        while (k--) {       //while loop runs k times to expand -> O(k)
            if (l < 0) {
                h++;
            } 
            else if (h >= arr.size()) {
                l--;
            } 
            else if (x - arr[l] > arr[h] - x) {
                h++;
            } 
            else 
                l--;
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }
};


//Approach-3 : Using Sorting Based on Difference
//TC : O(nlogn)  SC: O(k)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //custom comprator (lambda function) - based on the given conditions
        auto comp = [x](int a, int b) {
            int diffA = abs(a - x);
            int diffB = abs(b - x);
            return diffA < diffB || (diffA == diffB && a < b);
        };

        //sorting array based on the comp
        sort(arr.begin(), arr.end(), comp);

        //first k elements will make the resuls
        vector<int>ans (arr.begin(), arr.begin()+k);

        // Sort the elements to maintain order
        sort(ans.begin(), ans.end());

        return ans;
    }
};