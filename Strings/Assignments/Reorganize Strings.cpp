//leetcode-767: Reorganize Strings

//Approach : count freq. of all characters, push them into maxHeap. top two characters whose freq. is highest, process them first. handle the last character separately.
//T.C : O(n) where n is length of string s
//S.C : O(n) 

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        int n = s.size();

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] > (n + 1) / 2)
                return "";
        }

        //maxHeap
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                pq.push({freq[i], (char)i + 'a'});
            }
        }

        string ans = "";
        while (pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            ans += p1.second; p1.first--;
            ans += p2.second; p2.first--;

            if (p1.first > 0) pq.push(p1);
            if (p2.first > 0) pq.push(p2);
        }

        if (pq.size() == 1)
            ans += pq.top().second;

        return ans;
    }
};

//...........................................................................................
//Approach-2: Using Maps (GREEDY)
//TC: O(n)

class Solution {
public:
    string reorganizeString(string s) {
        int count[26] = {0};
        for(int i=0; i<s.size(); i++){
            count[s[i]-'a']++;
        }

        char max_freq_char;
        int max_freq = INT_MIN;

        for(int i=0; i<26; i++){
            if(count[i] > max_freq){
                max_freq = count[i];
                max_freq_char = i+'a';
            }
        }

        //place most freq char 
        int index = 0;
        while(max_freq > 0 && index < s.size()){
            s[index] = max_freq_char;
            max_freq--;
            index += 2;
        }

        //if we can't place max_freq_char separately
        if(max_freq != 0) return "";

        count[max_freq_char - 'a'] = 0;

        //Now place the rest of the characters
        for(int i=0; i<26; i++){
            while(count[i] > 0){
                //if index goes out of the bound put it back on 1.
                index = (index >= s.size()) ? 1 : index;
                s[index] = i+'a';
                count[i]--;
                index += 2;
            }
        }

        return s;
    }
};