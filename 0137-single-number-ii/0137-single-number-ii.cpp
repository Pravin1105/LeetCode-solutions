class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> arr(32, 0);
        for(int i = 0; i<32; i++){
            for(int j = 0; j<n; j++){
                arr[i] += nums[j]&1;
                nums[j] >>= 1;
            }
            arr[i] %= 3;
        }
        for(int i = 0; i<32; i++){
            if(arr[i]) ans += (1<<i);
        }
        return (int)ans;
    }
};