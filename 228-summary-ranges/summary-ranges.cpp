class Solution {
public:
    string convert(int startingNumber, int endingNumber) {
        string partialRes;
        if (startingNumber == endingNumber) {
            partialRes = to_string(startingNumber);
        } else {
            partialRes =
                to_string(startingNumber) + "->" + to_string(endingNumber);
        }
        return partialRes;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<string>{};
        }
        int startingNumber = nums[0];
        int endingNumber = nums[0];
        vector<string> res;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                endingNumber = nums[i];
            } else {
                res.push_back(convert(startingNumber, endingNumber));
                startingNumber = nums[i];
                endingNumber = nums[i];
            }
        }
        res.push_back(convert(startingNumber, endingNumber));
        return res;
    }
};