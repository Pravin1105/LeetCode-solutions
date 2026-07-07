class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        int j, n = triangle.size(), m=0;
        for(int i = 1; i<n; i++){
            m = triangle[i].size();
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for(j = 1; j<m-1; j++){
                dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            }
            dp[i][j] = triangle[i][j] + dp[i-1][j-1];
        }
        // for(int i = 0; i<n; i++){
        //     m = triangle[i].size();
        //     for(j = 0; j<m; j++){
        //         cout<<dp[i][j]<<"    ";
        //     }
        //     cout<<endl;
        // }
        int ans = dp[n-1][0];
        for(int i = 1; i<m; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};