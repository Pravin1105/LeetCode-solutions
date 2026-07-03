class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while(j < n){
            if(nums[j]){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        while(i<n){
            nums[i] = 0;
            i++;
        }
        return;
    }
};