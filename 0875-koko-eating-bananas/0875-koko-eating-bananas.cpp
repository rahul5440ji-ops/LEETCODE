
class Solution {
public:
   
    long long calculateHours(vector<int>& piles, int h) {
        long long s = 0;
        int n = piles.size(); 
        
        for(int i = 0; i < n; i++) {
            s = s + piles[i] / h;
            if (piles[i] % h != 0)
                s++;
        } 
        return s;
    }

    int minEatingSpeed(vector<int>& piles, int guard){
        int n = piles.size();
        
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = -1;

        while(low <= high) {
            
            int guess = low + (high - low) / 2;
            
          
            long long hours = calculateHours(piles, guess);

            if(hours > guard) {
                low = guess + 1;
            } else {
                res = guess;
                high = guess - 1;
            }
        } 
        return res; 
    } 
};