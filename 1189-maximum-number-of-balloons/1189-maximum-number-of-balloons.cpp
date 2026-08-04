class Solution {
public:
    int maxNumberOfBalloons(string s) {
      unordered_map<char,int>f;
      unordered_map<char,int>have;
      for(int i=0;i<s.size();i++){
        have[s[i]]++;
      }  
      unordered_map<char,int>need;{
      need['b']=1;
      need['a']=1;
      need['l']=2;
      need['o']=2;
      need['n']=1;
      }
      int res = INT_MAX;
      for(auto i:need){
        char c= i.first;
        int f_need=i.second;
        int f_have=have[c];
        int times=f_have/f_need;
        res = min(res,times);

      }
      return res;

    }
};