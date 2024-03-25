class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' '){
            i++;
        }

        stack<string> container;
        string temp = "";
        while(i < s.size()){
            if(s[i] == ' '){
                if(!temp.empty()){
                    container.push(temp);
                }
                temp = "";
            }else {
                temp += s[i];
            }
            i++;
        }

        if(!temp.empty()){
            container.push(temp);
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