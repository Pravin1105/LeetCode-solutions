class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n == 1) return intervals;
        int l = 0, r = 1;
        while(r < n){
            if(intervals[l][1] < intervals[r][0]){
                ans.push_back(intervals[l]);
                l = r;
            }
            else{
                if(intervals[r][1]<intervals[l][1]){

                }
                else{
                    intervals[l][1] = intervals[r][1];
                }
            }
            r++;
        }
        ans.push_back(intervals[l]);
        return ans;
    }
};