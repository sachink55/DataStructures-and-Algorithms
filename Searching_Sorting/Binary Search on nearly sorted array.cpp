//Binary Search on nearly sorted array

int searchNearlySorted(vector<int>&arr, int target){
    int n = arr.size();
    int s = 0, e = n - 1;

    while(s <= e){
        int mid = s + (e - s) / 2;

        if(arr[mid] == target) {
            return mid; 
        }
        if((mid-1)>=0 && arr[mid-1] == target) {
            return mid - 1; 
        }
        if((mid+1)<n && arr[mid+1] == target) {
            return mid + 1; 
        }

        if(arr[mid] < target) {
            s = mid + 2; // right - we've checked mid+1
        } else {
            e = mid - 2; // left - we've checked mid-1
        }
    }
}