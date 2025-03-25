// leetcode-133 : Clone Graph

//Approach : Using DFS
class Solution {
public:
    unordered_map<Node*, Node*>mp;

    void DFS(Node* node, Node* clone_node){
        for(auto &nbr : node->neighbors){
            //if the entry is not created for nbr in map
            if(mp.find(nbr) == mp.end()){
                Node* clone = new Node(nbr->val);
                mp[nbr] = clone;
                clone_node->neighbors.push_back(clone);
                DFS(nbr, clone);
            } else{
                //entry is already created. just push mp[nbr] to clone_node neighbors
                clone_node->neighbors.push_back(mp[nbr]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        mp.clear();

        //Clone the given node
        Node* clone_node = new Node(node->val);

        //Now, clone its neighbors and their neighbors recursively
        //But we a node reappears we've to access that cloned node. so store cloned nodes
        // in a map unordered_mp<Node*, Node*>
        
        mp[node] = clone_node;
        DFS(node, clone_node);

        return clone_node;
    }
};

//Approach : Using BFS
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    
    void BFS(Node* node) {
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (auto& nbr : curr->neighbors) {
                if (mp.find(nbr) == mp.end()) {
                    Node* clone_nbr = new Node(nbr->val);
                    mp[nbr] = clone_nbr;
                    q.push(nbr);
                }
                mp[curr]->neighbors.push_back(mp[nbr]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        mp.clear();
        
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;
        
        BFS(node);
        
        return clone_node;
    }
};
