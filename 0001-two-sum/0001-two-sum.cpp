class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> vp;
        for(int i = 0; i<n; i++){
            vp.push_back(make_pair(nums[i], i));
        }
        sort(vp.begin(), vp.end());
        int i = 0, j = n-1;
        while(i<j){
            int l = vp[i].first, r = vp[j].first;
            if(l == target - r) return {vp[i].second, vp[j].second};
            else if(l < target - r) i++;
            else j--;
        }
        return {i, j};
    }
};