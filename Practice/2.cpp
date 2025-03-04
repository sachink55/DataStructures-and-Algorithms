#include <iostream>
#include <vector>

using namespace std;

int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
    int n = original.size();
    int count = 0; 

    for (auto it : bounds) {
        int low = it[0];
        int high = it[1];

        vector<int> copy; 
        copy.push_back(low);

        for (int i = 1; i < n; i++) {
            int val = original[i] - original[i - 1] + copy[i - 1];
            copy.push_back(val);
        }

        bool flag=1;
        for(int i=1; i<=n-1; i++) {
            if((copy[i] - copy[i - 1]) != (original[i] - original[i - 1])){
                flag  =0;
            }
        }
        if(flag) count++;
    }
    return count;
}

int main() {
    vector<int> org = {1, 2, 3, 4};
    vector<vector<int>> bounds = {{1, 2}, {2, 93}, {3, 4}, {4, 5}};
    
    int count = countArrays(org, bounds);
    cout << "count: " << count << endl;
    
    return 0;
}
