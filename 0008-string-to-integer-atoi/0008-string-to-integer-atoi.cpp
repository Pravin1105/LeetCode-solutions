class Solution {
public:
    int myAtoi(string s) {
        long long sign = 1, i = 0, n = s.size();
        long long ans = 0;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '-') {sign = -1; i++;}
        else if(s[i] == '+') i++;
        while(i<n){
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                ans = ans*10 + (s[i]-'0');
                if(sign*ans >= INT_MAX) {cout<<ans; return INT_MAX;}
                else if(sign*ans <= INT_MIN) return INT_MIN;
            }
            else {
                break;
            }
            i++;
        }
        return sign*ans;
    }
};