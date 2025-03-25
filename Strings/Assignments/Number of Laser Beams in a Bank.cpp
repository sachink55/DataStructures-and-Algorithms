//leetcode-2125: Number of Laser Beams in a Bank

//TC: O(n*m)
//SC: O(1)

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // poc => previous one count
        // coc => current one count
        int poc = 0;
        int ans = 0;
        int m = bank[0].size();
        int n = bank.size();

        for (int i = 0; i < n; i++) {
            int coc = 0;
            for (int j = 0; j < m; j++)
                if (bank[i][j] == '1') coc++;
            if (coc > 0) {
                ans += coc * poc;
                poc = coc;
            }
        }
        return ans;
    }
};