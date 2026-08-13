class Solution {
public:
    int search(vector<int>& a, int target) {
        int low = 0, high = a.size() - 1;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            if (a[guess] == target)
                return guess;

            // Check if the left half is sorted
            if (a[low] <= a[guess]) {
                // Check if the target lies within the sorted left half
                if (a[low] <= target && target < a[guess]) {
                    high = guess - 1; // Search left
                } else {
                    low = guess + 1;  // Search right
                }
            } 
      
            else {
                // Check if the target lies within the sorted right half
                if (a[guess] < target && target <= a[high]) {
                    low = guess + 1;  // Search right
                } else {
                    high = guess - 1; // Search left
                }
            }
        }
        return -1;
    }
};