class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        int n = nums.size();
        
        if (n == 0) return result;
        
        int start = nums[0];
        int end = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == end + 1) {
                end = nums[i];
            } else {
                if (start == end) {
                    result.push_back(std::to_string(start));
                } else {
                    result.push_back(std::to_string(start) + "->" + std::to_string(end));
                }
                start = nums[i];
                end = nums[i];
            }
        }
        
        // Handle the last range
        if (start == end) {
            result.push_back(std::to_string(start));
        } else {
            result.push_back(std::to_string(start) + "->" + std::to_string(end));
        }
        
        return result;
    }
};