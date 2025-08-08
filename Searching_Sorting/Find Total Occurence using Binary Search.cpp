//Find Total Occurrence using Binary Search
//TC: O(log n)
//SC: O(1)

int FirstOccurrence(vector<int>&arr, int target){
    int s = 0;
    int e = arr.size() - 1;
    int firstOcc = -1;

    while(s <= e){
        int mid = s + (e - s) / 2;
        if(arr[mid] == target){
            firstOcc = mid; //found, go left
            e = mid - 1;
        }
        else if(arr[mid] < target) s = mid + 1;
        else e = mid - 1;
    }
    return firstOcc;
}

int LastOccurrence(vector<int>&arr, int target){
    int s = 0;
    int e = arr.size() - 1;
    int lastOcc = -1;

    while(s <= e){
        int mid = s + (e - s) / 2;
        if(arr[mid] == target){
            lastOcc = mid; //found, go right
            s = mid + 1;
        }
        else if(arr[mid] < target) s = mid + 1;
        else e = mid - 1;
    }
    return lastOcc;
}

int TotalOccurrence(vector<int>&arr, int target){
    int first = FirstOccurrence(arr, target);
    if(first == -1) return 0; //target not found

    int last = LastOccurrence(arr, target);
    return last - first + 1; //total occurrences
}
