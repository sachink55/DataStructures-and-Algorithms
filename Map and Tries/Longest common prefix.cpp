//leetcode- 14 : Longest Common Prefix

//Approach-1 : Brute force 
//T.C : O(n * m) where n - total no. of words in strs and m - length of first string
//S.C : O(1)

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
      return "";

    for (int i = 0; i < strs[0].length(); ++i)
      for (int j = 1; j < strs.size(); ++j)
        if (i == strs[j].length() || strs[j][i] != strs[0][i])
          return strs[0].substr(0, i);

    return strs[0];
  }
};

//...................................................................................

//Approach-2 : Using Trie
//T.C : O(n*m) where n - no. of words in strs and m - length of longest word
//S.C : O(n*m) if all strings have distinct characters, a new node is created for each character. 

class TrieNode {
public:
    char value;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char val) {
        this->value = val;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
        this->childCount = 0;
    }
};

class Solution {
public:

    void insertWord(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            // present
            child = root->children[index];
        } else {
            // absent
            child = new TrieNode(ch);
            root->children[index] = child;
            root->childCount++;
        }

        // recursion
        insertWord(child, word.substr(1));
    }

    void findLCP(string& ans, TrieNode* root) {
        // base case
        if (root->isTerminal == true) {
            return;
        }

        /// abhi main root node pr hu
        TrieNode* child;
        if (root->childCount == 1) {

            // child tk jao
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    child = root->children[i];
                }
            }
            // ans me store karwao
            ans.push_back(child->value);
        } else {
            return;
        }
        // ab recursion ki baari
        findLCP(ans, child);
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        // insert all strings 
        for (auto str : strs) {
            insertWord(root, str);
        }

        string ans = "";
        findLCP(ans, root);

        return ans;
    }
};