class Solution {
public:
    int rob(vector<int>& nums) {
        /*--- using dp -----*/
        // int n = nums.size();
        // vector<int> dp(n, 0);
        // if(n == 1) return nums[0];
        // if(n == 2) return max(nums[0], nums[1]);
        // dp[0] = nums[0]; dp[1] = max(nums[1], dp[0]);
        // for(int i = 2; i<n; i++){
        //     dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        // }
        // for(int i = 0; i<n; i++){
        //     cout<<dp[i]<<"  ";
        // }
        // return dp[n-1];

        /*---- using O(1) space -----*/
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int sum0 = nums[0], sum1 = max(nums[1], nums[0]);
        for(int i = 2; i<n; i++){
            if(!(i&1)) sum0 = max(nums[i] + sum0, sum1);
            else sum1 = max(nums[i] + sum1, sum0);
            // cout<<sum0<<"  ";
        }
        return max(sum0, sum1);
    }
};