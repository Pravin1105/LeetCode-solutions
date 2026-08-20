class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> pq;
        int i = 0;
        while(i<k){
            while(!pq.empty() && nums[pq.back()] < nums[i]){
                pq.pop_back();
            }
            pq.push_back(i);
            i++;
        }
        ans.push_back(nums[pq.front()]);
        while(i<n){
            if(!pq.empty() && i - pq.front() > k-1) pq.pop_front();
            while(!pq.empty() && nums[pq.back()] < nums[i]){
                pq.pop_back();
            }
            pq.push_back(i);
            ans.push_back(nums[pq.front()]);
            i++;
        }
        return ans;
    }
};