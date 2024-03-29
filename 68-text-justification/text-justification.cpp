class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> curr;
        int numOfLetters = 0;
        for(int i = 0;i < words.size();i++){
            if(words[i].size() + numOfLetters + curr.size() > maxWidth){
                int totalSpace = maxWidth - numOfLetters;
                int gaps = curr.size() - 1;
                if(gaps == 0){
                    res.push_back(curr[0] + string(totalSpace, ' '));
                } else {
                    int spacePerGap = totalSpace / gaps;
                    int emptySpaces = totalSpace % gaps;
                    string toInsert;
                    for(int i = 0;i < curr.size();i++){
                        toInsert += curr[i];
                        if(i < gaps){
                            toInsert += string(spacePerGap, ' ');
                            if(i < emptySpaces){
                                toInsert += ' ';
                            }
                        }
                    }
                    res.push_back(toInsert);
                }
                curr.clear();
                numOfLetters = 0;
            }
            curr.push_back(words[i]);
            numOfLetters += words[i].size();
        }

        string lastLine;
        for(int i = 0;i < curr.size();i++){
            if(!lastLine.empty()){
                lastLine += ' ';
            }
            lastLine += curr[i];
        }

        lastLine += string(maxWidth - lastLine.size(), ' ');
        res.push_back(lastLine);
        return res;
    }
};