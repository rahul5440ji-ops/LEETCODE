class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int n = A.size();
        int m = B.size();

        while (i < n && j < m) {
            int l = max(A[i][0], B[j][0]);
            int k = min(A[i][1], B[j][1]);

            if (l <= k) {
                res.push_back({l, k});
            }

            if (A[i][1] < B[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return res; 
    } 
};


