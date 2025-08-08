//Exponential Search
//TC: O(log (2^ logm-1)) Or O(log( 2^logm / 2))  SC: O(1)

int binarySearch(vector<int>&arr, int s, int e, int target) {
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return -1; // Not found
}

int exponentialSearch(vector<int>&arr, int x) {
    int n = arr.size();
    if (arr[0] == x) return 0;
    int i = 1;
    while (i < n && arr[i] <= x) {
        i *= 2; // i = i<<1;
    }
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

//..................................................................................................
//Unbounded Binary Search
//TC: O(log n)  SC: O(1)

//1. Brute Force
int unbounded_bs(vector<int>&arr, int x){
    int i=0; 
    while(1){
        if(arr[i] > x) break;
        if(arr[i] == x){
            return i;
        }
        i++;
    }
    return -1;
}

//2. exponential search optimized

int unbounded_bs(vector<int>& arr, int x) {
    int n = arr.size();
    int i = 0, j = 1;

    while (j < n && arr[j] < x) {
        i = j;
        j *= 2;
    }
    j = min(j, n - 1);

    return binarySearch(arr, i, j, x);
}