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
            if (!node->containsKey(character)) {
              node->put(character, new Node());
            }
            node = node->get(character);
        }
        node->setEnd();
    }

    string longestPrefix(string word){
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            char character = word[i];
            if (!node->containsKey(character)) {
                return word;
            }
            node = node->get(character);
            if(node->isEnd()){
                return word.substr(0, i + 1);
            }
        }
        return word;
    }
};
class Solution {
private:
    vector<string> splitBySpace(string sentence){
        vector<string> res;
        string temp = "";
        int i = 0;
        int size = sentence.size();

        while(i < size){
            if(sentence[i] == ' '){
                res.push_back(temp);
                temp = "";
                i++;
            } else { 
                temp += sentence[i];
                i++;
            }
        }
        if(temp != " ") {
            res.push_back(temp);
        }
        return res;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res;
        Trie* trie = new Trie();
        for(auto item : dictionary){
            trie->insert(item);
        }
        vector<string> sentenceList = splitBySpace(sentence);

        for(auto val : sentenceList){
          res += trie->longestPrefix(val) + " ";
        }
        if(!res.empty()){
            res.pop_back();
        }
        return res;
    }
};