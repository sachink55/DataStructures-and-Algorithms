//Binary Search:
//TC: O(log n)
//SC: O(1)

int binarySearch(vector<int>&arr, int target){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2; //to avoid overflow
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; //target not found
}

