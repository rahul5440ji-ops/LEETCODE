#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> result = {-1, -1};
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false);
        
        result[0] = leftIndex;
        result[1] = rightIndex;
        return result;
    }

private:
    int binarySearch(std::vector<int>& nums, int target, bool isSearchingLeft) {
        int low = 0, high = (int)nums.size() - 1;
        int res = -1;
        
        while (low <= high) {
            int guess = low + (high - low) / 2;
            
            if (nums[guess] < target) {
                low = guess + 1;
            } else if (nums[guess] > target) {
                high = guess - 1;
            } else {
                res = guess;
                if (isSearchingLeft) {
                    high = guess - 1; // Search towards the left for the first occurrence
                } else {
                    low = guess + 1;  // Search towards the right for the last occurrence
                }
            }
        }
        return res;
    }
};