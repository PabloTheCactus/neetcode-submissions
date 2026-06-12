class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        for(int i = 0; i < nums.size(); i++){
            nums_map[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums_map[target - nums[i]] != 0 && i != nums_map[target - nums[i]])
            return{(i), (nums_map[target - nums[i]])};
        }
        
    }
};
