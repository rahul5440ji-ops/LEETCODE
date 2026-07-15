class Solution{
public:    
    int characterReplacement(string s, int k) {
    int n = s.size();
    vector<int> f(256, 0);
    int low = 0, high = 0;
    int max_freq = 0; 
    int res = 0;

    for (high = 0; high < n; high++) {
        f[s[high]]++;
        
       
        max_freq = max(max_freq, f[s[high]]);
        
        int len = high - low + 1;
        
         
      
        if (len - max_freq > k) {
            f[s[low]]--;
            low++;
        }
        
        
        res = max(res, high - low + 1);
    }
    
    return res;
}
};
