class Solution {
public:
    string simplifyPath(string path) {
        stack<string> seenPaths;
        for(int i = 0;i < path.size();i++){
            if(path[i] == '/'){
                continue;
            }

            string temp;
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }

            if(temp == "."){
                continue;
            } 

            if(temp == ".."){
                if(!seenPaths.empty()){
                    seenPaths.pop();
                }
            }else{
                seenPaths.push(temp);
            }
        }
        string res;
        while(!seenPaths.empty()){
            res = "/" + seenPaths.top() + res;
            seenPaths.pop();
        }
        
        return res.size() == 0 ? "/" : res;
    }
};