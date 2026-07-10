class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), can1, can2, count1 = 0, count2 = 0;
        for(int i = 0; i<n; i++){
            if(count1 == 0 && can2 != nums[i]){
                can1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && nums[i] != can1){
                can2 = nums[i];
                count2 = 1;
            }
            else if(can1 == nums[i]){
                count1++;
            }
            else if(can2 == nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        cout<<can1<<". "<<can2<<endl;
        }
        count1 = 0; count2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == can1){
                count1++;
            }
            if(nums[i] == can2){
                count2++;
            }
        }
        vector<int> ans;
        if(count1 > n/3) ans.push_back(can1);
        if(count2 > n/3) ans.push_back(can2);
        return ans;
    }
};