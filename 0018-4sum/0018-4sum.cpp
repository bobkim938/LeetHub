class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            vector<vector<int>> output = {};
            for(int i = 0; i < n; i++) {
                if (i > 0 && nums[i] == nums[i-1]) continue;
                for(int j = n - 1; j > i; j--) {
                    if (j < n-1 && nums[j] == nums[j+1]) continue; 
                    int left = i + 1;
                    int right = j - 1;
                    while(left < right) {
                        long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                        if(sum == target) {
                            vector<int> tmp = {nums[i], nums[j], nums[left], nums[right]};
                            output.push_back(tmp);
                            while(left < right && nums[left] == nums[left+1]) left++;
                            while(left < right && nums[right] == nums[right-1]) right--;
                            left++; right--;
                        }
                        else if(sum > target) right--;
                        else left++;
                    }
                }
            }
            return output;
        }
};