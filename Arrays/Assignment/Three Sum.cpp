//leetcode-15: Three Sum

//Using Two Pointers
//TC: O(n^2)
//SC: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>set;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n-2; i++){
            int j=i+1, k=n-1;
            while(j<k){
                if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                else{
                    set.insert({nums[i], nums[j], nums[k]});
                    j++; k--;
                }
            }
        }

        for(auto &it : set){
            ans.push_back(it);
        }
        return ans;
    }
};

//Using Hash Map
//TC: O(n^2)
//SC: O(n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end()); 

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; //ingoring duplicates for i

            unordered_map<int, int> seen;
            for (int j = i + 1; j < n; j++) {
                int complement = -(nums[i] + nums[j]); 
                
                if (seen.count(complement)) { 
                    ans.push_back({nums[i], nums[j], complement});
                    
                    while (j + 1 < n && nums[j] == nums[j + 1]) j++; //ignoring duplicates for j
                }
                
                seen[nums[j]] = j; 
            }
        }
        return ans;
    }
};

