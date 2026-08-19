class Solution {

public:
  int fun(std::vector<std::vector<int>>& a, int n, int guess) {
    int row = n - 1;
    int col = 0;
    int count = 0;
    while (row >= 0 && col < a[0].size()) {
        if (a[row][col] <= guess) {
            count = count + row + 1;
            col++;
        } else {
            row--;
        }
    }
    return count;
}

int kthSmallest(std::vector<std::vector<int>>& a, int k) {
    int n = a.size();
    int m = a[0].size();
    int low = a[0][0];
    int high = a[n - 1][m - 1];
    int res = -1;
    while (low <= high) {
        int guess = low + (high - low) / 2;
        int ans = fun(a, n, guess);
        if (ans < k) {
            low = guess + 1;
        } else {
            res = guess;
            high = guess - 1;
        }
    }
    return res;
}
    
        
    
};