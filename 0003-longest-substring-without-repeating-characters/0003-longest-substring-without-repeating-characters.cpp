class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), curr = 0, max_len = 0;
        if(n == 0) return 0;
        vector<int> v(256, 0);
        int i = 0, j = 0;
        while(j<n){
            if(v[s[j]]){
                while(s[i] != s[j]){
                    v[s[i]]--;
                    i++;
                }
                v[s[i]]--;
                i++;
            }
            v[s[j]]++;
            j++;
            curr = j-i;
            max_len = max(max_len, curr);
        }
        return max_len;
    }
};