#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char ch;
        TrieNode* children[26];
        bool isEnd;

        TrieNode(char val){
            this->ch = val;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            this->isEnd = false;
        }
};

void insertWord(TrieNode* root, string word){
    //base case
    if(word.length()== 0){
        root->isEnd = true;
        return;
    }

    char ch = word[0];
    int i = ch-'a';
    TrieNode* child;

    if(root->children[i] != NULL){
        //present 
        child = root->children[i];
    }

    else{
        //absent -> create and traverse
       child = new TrieNode(ch);
       root->children[i] = child;
    }

    //recursion
    insertWord(child, word.substr(1));
}

void searchWord(TrieNode* root, string word){
    if(word.length()==0 && root->isEnd){
        cout << " Found" << endl;
        return;
    }

    char ch = word[0];
    int i = ch -'a';
    TrieNode* child;

    if(root->children[i] != NULL){
        //present or found
        child = root->children[i];
    }
    else{
        cout << " Not Found" << endl;
        return;
    }

    searchWord(child, word.substr(1));
}

void deleteWord(TrieNode* root, string word){
    if(word.length()==0){
        root->isEnd = false;
        return;
    }
    
    char ch = word[0];
    int i = ch-'a';
    TrieNode* child;

    if(root->children[i] != NULL){
        //present 
        child = root->children[i];
    }
    else{
       cout << "can't delete.. word is not in the trie" << endl;
       return;
    }
    
    deleteWord(child, word.substr(1));
}

void storeString(TrieNode* root, string &input, vector<string> &ans, string &prefix){
    if(root->isEnd){
        //ek word mil gya
        ans.push_back(prefix+input);
        //No need to return, aur answers ho sakte hai
    }

    for(char ch='a'; ch<='z'; ch++){
        int i = ch-'a';
        TrieNode* next = root->children[i];
     
        if(next){
            //child exists
            input.push_back(ch);
            //baki recursion
            storeString(next, input, ans, prefix);
            //backtrack
            input.pop_back();
        }
    }
}

void findWordsByPrefix(TrieNode* root, string input, vector<string>&ans, string &prefix){
    if(input.length() == 0){
        TrieNode* lastchar = root;
        storeString(lastchar, input, ans, prefix);
        return;
    }

    char ch = input[0];
    int i = ch -'a';
    TrieNode* child;

    if(root->children[i] != NULL){
        //present or found
        child = root->children[i];`
    }
    else{
        cout << " No Words with the given prefix! " << endl;
        return;
    }

    findWordsByPrefix(child, input.substr(1), ans, prefix);
}

//Find words by given prefix 
//e.g. for input "jok", find words starting with 'j', 'jo', 'jok'

vector<vector<string>> getSuggestions (TrieNode* root, string input){
    vector<vector<string>output;

    TrieNode* prev =  root;
    string inputhelper = "";
    
    for(int i=0; i<input.length(); i++){
        char lastchar = input[i];
        int index = lastchar - 'a';

        TrieNode* curr = prev->children[index];

        if(curr == NULL){
            break;
        }
        else{
            vector<string>nicheKaAns;

            prefix.push_back(lastchar);
            string dummy = "";
            storeString(curr, nicheKaAns, inputhelper, dummy);
            output.push_back(nicheKaAns);
            //important
            prev = curr;
        }
    }
    return output;
}


int main(){
    TrieNode* root = new TrieNode('-');

    insertWord(root, "car");
    insertWord(root, "caring");
    insertWord(root, "love");
    insertWord(root, "lover");
    insertWord(root, "cat");
    insertWord(root, "loom");
    insertWord(root, "cater");
    insertWord(root, "dove");
    insertWord(root, "cow");

    cout << "insertion done! " << endl;

    // searchWord(root, "cat");
    // searchWord(root, "loved");
    // searchWord(root, "dove");

    // deleteWord(root, "dove");

    // searchWord(root, "dove");


    string input = "ca";
    vector<string> ans;  

    for(int i = 1; i <= input.size(); i++){  
        string newInput = input.substr(0, i); 
        string prefix = newInput;

        findWordsByPrefix(root, newInput, ans, prefix);  

        cout << "for " << prefix << " : ";  
        for(auto word : ans){  
            cout << word<< ", ";
        }
        cout << endl;
        ans.clear(); 
    }

    return 0;
}