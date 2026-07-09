class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n = nums.size();
       int i = nums[0], j = nums[0];
       do{
        cout<<i<<".  "<<j<<endl;
        i = nums[i];
        j = nums[nums[j]];
       }while(i  != j);
       j = nums[0];
       while(i != j){
        i = nums[i];
        j = nums[j];
       }
       return i;
    }
};