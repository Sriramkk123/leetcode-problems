class Solution {
public:
    bool exists(vector<vector<char>>& board, int i, int j, string word, int index){
        if(index == word.size()){
            return true;
        }

        if(i < 0 || j < 0 || i == board.size() || j == board[i].size() || board[i][j] != word[index]){
            return false;
        }

        char c = board[i][j];
        board[i][j] = '0';
        bool otherDirectionsResult = exists(board,i + 1,j,word,index+1) || 
                                exists(board,i,j + 1,word,index+1) ||
                                exists(board,i - 1,j,word,index+1) ||
                                exists(board,i,j-1,word,index+1);
        
        board[i][j] = c;
        return otherDirectionsResult;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        unordered_map<char,int> wordFrequency;
        unordered_map<char,int> boardWordFrequency;

        for(int i = 0;i < word.size();i++){
            wordFrequency[word[i]]++;
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                boardWordFrequency[board[i][j]]++;
            }
        }

        for(auto it : wordFrequency){
            if(boardWordFrequency[it.first] < it.second){
                return false;
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] != word[0]){
                    continue;
                }
                if(exists(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};