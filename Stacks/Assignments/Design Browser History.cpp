//leetcode- 1472: Design Browser History 

class BrowserHistory {
public:
    stack<string>browserStack, fwdStack;
    BrowserHistory(string homepage) {
        browserStack.push(homepage);
    }
    
    void visit(string url) {
        //let's clear all the fwd history
        while(!fwdStack.empty()) fwdStack.pop();
        browserStack.push(url);
    }
    
    string back(int steps) {
        while(steps--){
            //ek bar back jayenge
            if(browserStack.size() > 1){
                fwdStack.push(browserStack.top());
                browserStack.pop();
            }
            else{
                //only homepage present
                //back not possible.
            }
        }
        return browserStack.top();
    }
    
    string forward(int steps) {
        while(steps--){
            if(!fwdStack.empty()){
                browserStack.push(fwdStack.top());
                fwdStack.pop();
            }
            else break;
        }
        return browserStack.top();
    }
};


//Approach-2: Without Stack

class BrowserHistory {
public:
    vector<string> sites;
    int index;
    BrowserHistory(string homepage) {
        sites.clear();
        index = 0;
        sites.push_back(homepage);
    }
    
    void visit(string url) {
        index = index+1;
        while(sites.size() > index){
            sites.pop_back();
        }
        sites.push_back(url);
    }
    
    string back(int steps) {
        int val = index-steps;
        int i =  max(val, 0);
        index = i;
        return sites[i];
    }
    
    string forward(int steps) {
        int val = sites.size()-1;
        int i =  min(index+steps, val);
        index = i;
        return sites[i];
    }
};