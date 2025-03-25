//leetcode-6: Zigzag Conversion

//TC: O(n)
//SC: O(numRows)

class Solution {
public:
    //Step1: if numRows = 1, return the given string
    //Step2: Identify the direction. first we will go top to bottom (downward) till last row (numRows-1).
    // (if numRows = 3 => 0, 1, 2)
    //Then reset the row to 1 row before last row. so row = numRows-2. (last row is numRows-1)
    //If we've reached the first row (0th row), then stop and Change the direction
    //Now row will start from row=1. because we've already proccesed row = 0.
    //keep doing it until the string ends.

    string convert(string s, int numRows) {
        //if there is only one row, return the given string
        if(numRows == 1) return s;

        vector<string>zigzag(numRows);
        int i = 0, row = 0;
        bool direction = 1; //Top->Bottom

        while(true){
            //First go from Top -> Bottom
            if(direction){
                while(row < numRows && i < s.size()){
                    zigzag[row++].push_back(s[i++]);
                }
                row = numRows - 2;
            }
            //Now we go from Bottom -> top
            else{
                while(row >= 0 && i< s.size()){
                    zigzag[row--].push_back(s[i++]);
                }
                row = 1;
            }
            
            if(i>= s.size()) break;
            direction = !direction;
        }

        string ans = "";
        for(int i=0; i<zigzag.size(); i++){
            ans += zigzag[i];
        }
        return ans;
    }
};

//.........................................................................
//Appraoch: A little more COOL

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) {
            return s; // No zigzag needed
        }

        vector<string> rows(min(numRows, int(s.size())));
        int currRow = 0;
        bool goingDown = false;

        // Simulate the zigzag pattern
        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown; // Change direction
            }
            currRow += goingDown ? 1 : -1;
        }

        // Combine rows into final string
        string ans;
        for (const string& row : rows) {
            ans += row;
        }

        return ans;
    }
};