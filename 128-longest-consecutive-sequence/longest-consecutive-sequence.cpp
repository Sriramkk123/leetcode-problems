class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cont;
        for(auto ele : nums){
            cont.insert(ele);
        }

        int longest = 0;
        for(int i = 0;i < nums.size();i++){
            int currentNum = nums[i];
            if(cont.find(currentNum-1) == cont.end()){
                int count = 1;
                while(cont.find(currentNum+1) != cont.end()){
                    count++;
                    currentNum++;
                }
                longest = max(count, longest);
            }
        }
        return longest;
    }
};

// 0 0 1 2 3 4 5 6 7