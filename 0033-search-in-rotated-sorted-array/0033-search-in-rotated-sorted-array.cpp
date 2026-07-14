class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), s = 0, e = n-1, m;
        while(s<=e){
            m = (s+e)/2;
            if(nums[m] == target) return m;
            if(nums[m] >= nums[s] && nums[m] >= nums[e]){
                if(target > nums[m]) s = m+1;
                else{
                    if(nums[s] > target) s = m+1;
                    else e = m-1;
                }
            }
            else if(nums[m] < nums[s] && nums[m] < nums[e]){
                if(target > nums[m]){
                    if(nums[e]>=target) s = m+1;
                    else e = m-1;
                }
                else e = m-1;
            }
            else{
                if(target < nums[m]) e = m-1;
                else s = m+1;
            }
        }
        return -1;
    }
};