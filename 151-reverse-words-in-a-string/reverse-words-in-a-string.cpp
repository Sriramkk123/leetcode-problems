class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string> container;
        string word;
        while(ss >> word){
            container.push(word);
        }    

        string res = "";
        while(!container.empty()){
            string word = container.top();
            container.pop();
            res += word + " ";
        }

        if(!res.empty()){
            res.pop_back();
        }
        return res;
    }
};