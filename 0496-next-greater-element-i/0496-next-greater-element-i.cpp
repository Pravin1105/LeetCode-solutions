class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        int n = nums1.size(), m = nums2.size();
        for(int i = 0; i<m; i++){
            mp[nums2[i]] = i;
        }
        for(int i = 0; i<n; i++){
            int k = nums1[i], curr = INT_MAX, idx = mp[nums1[i]];
            for(auto it: mp){
                if(it.first > k && it.second > idx){
                    curr = min(curr, it.second);
                }
            }
            if(curr == INT_MAX) nums1[i] = -1;
            else nums1[i] = nums2[curr];
        }
        return nums1;
    }
};