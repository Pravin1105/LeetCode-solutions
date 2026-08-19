class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return min(nums[0], nums[1]);
        int s = 0, e = n-1, m;
        while(s < e){
            m = (s+e)/2;
            if(nums[m] > nums[e]){
                s = m+1;
            }
            else e = m;
        }
        return nums[s];
    }
};