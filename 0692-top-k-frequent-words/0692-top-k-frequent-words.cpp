class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        // Count frequency
        for (string word : words) {
            freq[word]++;
        }

        // Min heap
        struct cmp {
            bool operator()(const pair<int, string>& a,
                            const pair<int, string>& b) {

                // Lower frequency has higher priority
                if (a.first != b.first)
                    return a.first > b.first;

                // If frequency is same,
                // lexicographically larger word has higher priority
                return a.second < b.second;
            }
        };

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            cmp
        > pq;

        // Keep only k elements
        for (auto& [word, count] : freq) {

            pq.push({count, word});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Extract answer
        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Heap gives worst -> best,
        // so reverse it
        reverse(ans.begin(), ans.end());

        return ans;
    }
};