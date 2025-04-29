//SPOJ: DEFKIN - Defense of a Kingdom

#include <iostream>
using namespace std;

int findMaxArea(int row, int col, vector<pair<int, int>> &towers){
	vector<int> xDim = {0, row+1};
	vector<int> yDim = {0, col+1};
	
	for(auto it:towers){
		xDim.push_back(it.first);
		yDim.push_back(it.second);
	}
	
	sort(xDim.begin(), xDim.end());
	sort(yDim.begin(), yDim.end());
	
	int xMaxi = -1;
	for(int i=1; i<xDim.size(); i++){
		int diff = xDim[i] - xDim[i-1] - 1;
		xMaxi = max(xMaxi, diff);
	}
	
	int yMaxi = -1;
	for(int i=1; i<yDim.size(); i++){
		int diff = yDim[i] - yDim[i-1] - 1;
		yMaxi = max(yMaxi, diff);
	}
	
	return xMaxi * yMaxi;
}

int main() {
	int t;
	cin >> t;
	while(t--){
		int row, col, tower;
		vector<pair<int, int>> towers;
		
		cin >> row >> col >> tower;
		for(int i=0; i<tower; i++){
			int x, y;
			cin >> x >> y;
			towers.push_back({x, y});
		}
		
		cout << findMaxArea(row, col, towers) << endl;
	}
	return 0;
}