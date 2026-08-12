class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int res = -1;
        while (low <= high) {
            int guess = low + (high - low) / 2;
         if (guess + 1 < n && arr[guess] < arr[guess + 1]) {
                low = guess + 1;
            } 
            else {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};