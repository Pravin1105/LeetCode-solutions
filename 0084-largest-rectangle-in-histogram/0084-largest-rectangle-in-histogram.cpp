class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size(), max_area = 0;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int h = heights[st.top()], w;
                st.pop();
                if(st.empty()) w = i;
                else w = i-st.top()-1;
                max_area = max(max_area, w*h);
            }
            st.push(i);
        }
        while(!st.empty()){
            int h = heights[st.top()], w;
            st.pop();
            if(st.empty()) w = n;
            else w = n-st.top()-1;
            max_area = max(max_area, h*w);
        }
        return max_area;
    }
};