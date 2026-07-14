class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            pq.push(make_pair(it.second, it.first));
        }
        for(int i = 0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};