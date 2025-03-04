//gfg - Find missing elements from an Array with duplicates

//Approach-1 : 
vector<int> missing_elements(vector<int> nums)
{
	vector<int> mis;
	for (int i = 0; i < nums.size(); i++) {

		int temp = abs(nums[i]) - 1;
		// Update the element at the found index
		nums[temp] = nums[temp] > 0 ? -nums[temp] : nums[temp];
	}

	for (int i = 0; i < nums.size(); i++)
		if (nums[i] > 0)
			mis.push_back(i + 1);

	return mis;
}

//Approach-2 :
vector<int> FindMissing(vector<int> arr)
{
	int i = 0;
	int n = arr.size();
	while (i < n) {
		// as 0 based indexing
		int correct = arr[i] - 1;
		if (arr[i] != arr[correct]) {
			swap(arr[i], arr[correct]);
		}
		else {
			i++;
		}
	}

	vector<int> ans;
	for (i = 0; i < N; i++) {
		if (arr[i] != i + 1) {
			ans.push_back(i + 1);
		}
	}
	return ans;
}

