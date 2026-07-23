class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        std::unordered_map<int, int> f;
        f[0] = 1;
         for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int qus = sum - k;
            if (f.find(qus) != f.end()) {
                res += f[qus];
            } 
            f[sum]++;
        }
        
        return res;
    }
};