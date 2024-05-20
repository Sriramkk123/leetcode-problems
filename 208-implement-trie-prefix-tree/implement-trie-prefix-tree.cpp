class Node {
    private:
    Node* links[26];
    bool end;

    public:
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
class Trie {
private: 
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            char character = word[i];
            if(!node->containsKey(character)){
                node->put(character, new Node());
            }
            node = node->get(character);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            char character = word[i];
            if(!node->containsKey(character)){
                return false;
            }
            node = node->get(character);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0;i < prefix.size();i++){
            char character = prefix[i];
            if(!node->containsKey(character)){
                return false;
            }
            node = node->get(character);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */