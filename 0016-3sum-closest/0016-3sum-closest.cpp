class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int output, diff = INT_MAX;
            for(int i = 0; i < nums.size() - 2; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue; 
                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if(abs(target - sum) < abs(diff)) {
                        diff = target - sum;
                        output = sum;
                    }
                    if(sum < target) {
                        left++;
                    }
                    else right--;
                }
            }
            return output;
        }
};