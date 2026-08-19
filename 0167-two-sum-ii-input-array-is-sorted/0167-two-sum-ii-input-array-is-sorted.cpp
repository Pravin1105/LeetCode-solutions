class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), i = 0, j = n-1;
        vector<int> ans(2, 0);
        while(i<j){
            if(numbers[i] == target - numbers[j]){
                ans[0] = i+1;
                ans[1] = j+1;
                break;
            }
            else if(numbers[i] < target - numbers[j]) i++;
            else j--;
        }
        return ans;
    }
};