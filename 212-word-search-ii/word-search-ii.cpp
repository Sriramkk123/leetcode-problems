class Node {
    private:
    Node* links[26];
    bool end;

    public:
    void insert(string word) {
        Node* node = this;
        for(int i = 0;i < word.size();i++){
            char character = word[i];
            if(!node->containsKey(character)){
                node->put(character, new Node());
            }
            node = node->get(character);
        }
        node->setEnd();
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void setEnd(){
        end = true;
    }

    bool isEnd(){
        return end;
    }
};
class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis, Node* node, string currWord, unordered_set<string>& res){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j]){
            return;
        }

        if(!node->containsKey(board[i][j])){
            return;
        }

        node = node->get(board[i][j]);
        currWord += board[i][j];
        if(node->isEnd()){
            res.insert(currWord);
        }   

        vis[i][j] = true;
        dfs(i + 1, j, board, vis, node, currWord, res);
        dfs(i, j + 1, board, vis, node, currWord, res);
        dfs(i, j - 1, board, vis, node, currWord, res);
        dfs(i - 1, j, board, vis, node, currWord, res);
        vis[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* trie = new Node(); 
        unordered_set<string> res;
        for(auto word : words){
            trie->insert(word);
        }
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                dfs(i, j, board, visited, trie, "", res);
            }
        }
        vector<string> ans;
        for(auto ele : res){
            ans.push_back(ele);
        }
        return ans;
    }
};