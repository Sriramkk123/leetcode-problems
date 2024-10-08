/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            auto curr = st.top();
            st.pop();

            res.push_back(curr->val);
            
            int size = curr->children.size();
            for(int i = 0;i < size;i++){
                st.push(curr->children[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};