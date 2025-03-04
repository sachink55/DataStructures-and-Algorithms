//leetcode-532 : K-diff Pairs in an Array

//Approach-1 : Brute Force
//Get all pairs and check if the satisfy the condition
//TC: O(n^2 * logn)   SC: O(n^2)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       int n = nums.size();
       set<pair<int,int>> set;
    
       for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[j]-nums[i]) == k){
                    set.insert({nums[i], nums[j]}); 
                }
            }
       }
       return set.size();
    }
};


//Approach-2 : Using Two Pointers
//TC: O(nlogn) SC: O(1)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
		int j=1;
		int i=0;
		int ans=0;
		while(i<nums.size() && j<nums.size()){
			if(nums[j]-nums[i]==k){
                ans++;
				j++;
				i++;
 				while(j<nums.size() && nums[j]==nums[j-1]){
					j++;
 				}
 			}
 			else if(nums[j]-nums[i]>k){
 				i++;  
 			}
 			else {      
 				j++;
 			}     
            
            if(i==j){ j++;}
 		}
 		return ans;
    }
};

//Approach-3 : Using Binary Search
//TC: O(nlogn)  SC: O(n)

class Solution {
public:
    int bs(vector<int>&nums, int s, int target){
        int e = nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return -1;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set< pair<int, int>> ans;

        for(int i=0; i<nums.size(); i++){
            //serach for nums[i]+k in right, if found insert in set
            if(bs(nums, i+1, nums[i]+k) != -1){
                ans.insert({nums[i], nums[i]+k});
            }
        }
        return ans.size();
    }
};


//Approach-4 : Using Maps
//TC: O(n)  SC: O(n)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      
        unordered_map<int, int>freqMap;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            freqMap[nums[i]]++;
        }

        for(auto &[num, freq] : freqMap){
            if(k==0){
                //if freq is atleast 2 then ek valid pair mil gya
                if(freq > 1) count++;
            }
            else if(freqMap.find(num+k) != freqMap.end()){
                count++;
            }
        }
        return count;
    }
};