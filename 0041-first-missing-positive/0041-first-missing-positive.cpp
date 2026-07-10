class Solution {
public:
    void swap(int &x, int &y){
        int temp = x;
        x = y;
        y = temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1, n = nums.size(), i = 0;
        while(i<n){
            if(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[nums[i] - 1], nums[i]);
            }
            else i++;
        }
        i = 0;
        for(i; i<n; i++){
            if(nums[i] != i+1){
                return i + 1;
            }
        }
        return n+1;
    }
};