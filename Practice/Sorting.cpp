//Sorting Practice

//1. Bubble Sort
//2. Selection Sort
//3. Insertion Sort
//4. Merge Sort
//5. Quick Sort

//Bubble Sort 

#include<bits/stdc++.h>
using namespace std;

//TC: O(n^2)
// void bubbleSort(vector<int>&arr, int n){
//     for(int i=0; i<n-1; i++){
//         for(int j = 0; j<n-i-1; j++){
//             if(arr[j] > arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }

//TC : O(n^2)
//Selection sort
// void selectionSort(vector<int>&arr){
//     int n = arr.size();
//     for(int i=0; i<n-1; i++){
//         int minIndex = i;
//         for(int j=i+1; j<n; j++){
//             if(arr[j] < arr[minIndex]){
//                 minIndex = j;
//             }
//         }
//         swap(arr[i], arr[minIndex]);
//     }
// }

//Insertion sort
//TC : O(n^2)
// void insertionSort(vector<int> &arr){
//     int n = arr.size();
//     for(int i=1; i<n; i++){
//         int key = arr[i];
//         int j = i-1;
//         while(j>=0 && arr[j] > key){
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = key;
//     }
// }


//Merge Sort

// void merge(vector<int>&arr, int low, int mid, int high){
//     vector<int>temp;
//     int left = low;
//     int right = mid+1;

//     while(left <= mid && right <= high){
//         if(arr[left] <= arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else{
//             temp.push_back(arr[right])
//             right++;
//         } 
//     }
//     while(left <= mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right <= high){
//         temp.push_back(arr[right]);
//     }

//     for(int i=low; i<=high; i++){
//         arr[i] = temp[i-low];
//     }
// }
// void mergeSort(vector<int>&arr, int low, int high){
//     //base case
//     if(low>= high) return;
//     int mid = (low + high)/2;
//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid+1, high);
//     merge(arr, low, mid, high);
// }


//Quick Sort

//1. Taking last element as pivot
int partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

//2. Taking random element as pivot
int partition(vector<int>&arr, int low, int high){
    int randomIndex = low + rand() % (hig-low+1);
    swap(arr[randomIndex], arr[high]);

    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

//3. Taking first element as pivot
int partition(vector<int>&arr, int low, int high){
    int pivot = arr[low];
    int i = low; 
    int j = high;

    while(i < j){
        //check 1:
        while(i<high && arr[i] <= pivot) i++;
        //check 2:
        while(j>low && arr[j] > pivot) j--;

        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>&arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();

    // bubbleSort(arr, n);
    //selectionSort(arr);
    insertionSort(arr);

    cout <<"Sorted array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
