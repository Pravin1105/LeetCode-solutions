class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), count = 1, candidate = nums[0];
        for(int i = 1; i<n; i++){
            if(count == 0){
                candidate = nums[i];
                count = 1;
            }
            else if(candidate == nums[i]){
                count++;
            }
            else count--;
        }
        return candidate;
    }
};