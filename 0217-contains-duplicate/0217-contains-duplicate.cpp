class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size(), xor_sum = 0;
        unordered_set<int> s;
        for(int i = 0; i<n; i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            else s.insert(nums[i]);
        }
        return false;
    }
};