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
class WordDictionary {
private: 
    Node* root;
    bool helper(string word, Node* node){
        for(int i = 0;i < word.size();i++){
            char character = word[i];
            if(character != '.'){
                if(!node->containsKey(character)){
                    return false;
                }
                node = node->get(character);
            } else {
                int j = 0;
                bool found = false;
                while(j < 26){
                    if(node->containsKey(j + 'a')){
                        found |= helper(word.substr(i+1), node->get(j + 'a'));
                    }
                    if(found){
                        return true;
                    }
                    j++;
                }
                if(j == 26){
                    return false;
                } 
            }
            
        }
        return node->isEnd();
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
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
        return helper(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */