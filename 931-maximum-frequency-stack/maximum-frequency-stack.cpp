class FreqStack {
public:
    int maxFreq;
    unordered_map<int,int> freq;
    unordered_map<int,vector<int>> maxFreqMap;
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {    
        freq[val] += 1;
        maxFreq = max(maxFreq, freq[val]);
        maxFreqMap[freq[val]].push_back(val);
    }
    
    int pop() {
        int result = maxFreqMap[maxFreq].back();
        maxFreqMap[maxFreq].pop_back();
        freq[result]--;
        if(maxFreqMap[maxFreq].size() == 0){
            maxFreq -= 1;
        }
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */