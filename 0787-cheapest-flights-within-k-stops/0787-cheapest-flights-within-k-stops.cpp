class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize distance vector with a large value (infinity)
        vector<int> res(n, 1e8);
        res[src] = 0;
        
        // Perform k + 1 iterations (0 stops means 1 flight, k stops means k + 1 flights)
        for (int i = 0; i <= k; i++) {
            vector<int> temp = res; // Use temp to avoid using updated prices from the same iteration
            
            for (int j = 0; j < flights.size(); j++) {
                int s = flights[j][0];
                int d = flights[j][1];
                int wt = flights[j][2];
                
                // If the source node is reachable, try to relax the edge
                if (res[s] != 1e8 && temp[d] > res[s] + wt) {
                    temp[d] = res[s] + wt;
                }
            }
            res = temp; // Update res with the values calculated for this step
        }
        
        // If the destination is unreachable, return -1; otherwise, return the cost
        return res[dst] == 1e8 ? -1 : res[dst];
    }
};