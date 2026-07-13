class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        string word = "";
        for(int i = 0; i<n; i++){
            if(s[i] == ' ' && word != ""){
                st.push(word);
                word = "";
            }
            else if(s[i] == ' ' && word == ""){
                continue;
            }
            else if(s[i] != ' '){
                word += s[i];
            }
        }
        if(word != "") st.push(word);
        word = "";
        while(!st.empty()){
            word += " ";
            word += st.top();
            st.pop();
        }
        return word.substr(1);
    }
};