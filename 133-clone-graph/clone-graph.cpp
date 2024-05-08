/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& neighbourCont){
        vector<Node*> neighbours;
        Node* clone = new Node(node->val);
        neighbourCont[node] = clone;
        for(auto it : node->neighbors){
            if(neighbourCont.find(it) != neighbourCont.end()){
                neighbours.push_back(neighbourCont[it]);
            } else {
                neighbours.push_back(dfs(it, neighbourCont));
            }
        }
        clone->neighbors = neighbours;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }

        unordered_map<Node*, Node*> neighbourCont;
        if(node->neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }
        Node* clone = dfs(node, neighbourCont);
        return clone;
    }
};