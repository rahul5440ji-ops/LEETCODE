class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Count frequency
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        // Min heap: (frequency, number)
        struct cmp {
            bool operator()(const pair<int, int>& a,
                            const pair<int, int>& b) {
                if (a.first == b.first)
                    return a.second > b.second;

                return a.first > b.first;
            }
        };

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       cmp> pq;

        // Keep only k most frequent elements
        for (auto& [num, count] : freq) {
            pq.push({count, num});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Get answer
        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};