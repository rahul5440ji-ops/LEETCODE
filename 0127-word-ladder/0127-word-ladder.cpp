
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> f;
        for (int i = 0; i < wordList.size(); i++) {
            f[wordList[i]] = 1;
        }
        
        
        if (f.find(endWord) == f.end()) {
            return 0;
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); 
        
        
        if (f.find(beginWord) != f.end()) {
            f.erase(beginWord);
        }
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            string s = p.first;
            int val = p.second;
            
            if (s == endWord) {
                return val;
            }
            
            for (int i = 0; i < s.size(); i++) {
                char originalChar = s[i];
                
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) continue;
                    
                    s[i] = c;
                    
                    if (f.find(s) != f.end()) {
                        q.push({s, val + 1});
                        f.erase(s); 
                    }
                }
                s[i] = originalChar;
            }
        }
        
        return 0;
    }
};