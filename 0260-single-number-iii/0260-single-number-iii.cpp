class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size(), xor_sum = 0;
        vector<int> bits;
        for(int i = 0; i<n; i++){
            xor_sum ^= nums[i];
        }
        int k = 0;
        while(!(xor_sum & 1)){
            xor_sum >>= 1;
            k++;
        }
        int s = 1<<k, xor1 = 0, xor2 = 0;
        for(int i = 0; i<n; i++){
            if(s & nums[i]) xor1 ^= nums[i];
            else xor2 ^= nums[i];
        }
        return {xor1, xor2};
    }
};