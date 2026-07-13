class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), s = 0, e = n-1, mid;
        if(n == 1) return nums[0];
        while(s <= e){
            mid = (s+e)/2;
            if(mid == 0 || (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])){
                return nums[mid];
            }
            if(nums[mid] != nums[mid+1]){
                if(!(mid&1)) e = mid-1;
                else s = mid+1;
            }
            else if(nums[mid] == nums[mid+1]){
                if(mid&1) e = mid-1;
                else s = mid+1;
            }
        }
        return -1;
    }
};