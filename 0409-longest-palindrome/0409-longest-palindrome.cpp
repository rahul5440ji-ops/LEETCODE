class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> f;
        
        // Step 1: Count character frequencies
        for (char c : s) {
            f[c]++;
        }
        
        int res = 0;
        bool hasOdd = false;
        
        // Step 2: Calculate maximum palindrome length
        for (auto i : f) {
            int val = i.second;
            
            if (val % 2 == 0) {
                res += val; // Add the full even count
            } else {
                res += val - 1; // Add the largest even part
                hasOdd = true;  // Mark that we have at least one odd count
            }
        }
        
        // Step 3: Add 1 for the middle character if any odd frequency existed
        if (hasOdd) {
            res += 1;
        }
        
        return res;
    }
};