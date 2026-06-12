class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = -1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if(nums[mid] == target){return mid;}
            if(nums[low] == target){return low;}
            else if(nums[mid] > target){
                if(nums[low] > target) {
                    if(nums[low] > nums[mid]) high = mid - 1;
                    else low = mid + 1;
                }
                else if(nums[low] < target) high = mid - 1;
            }
            else if(nums[mid] < target){
                if(nums[low] < target) low = mid + 1;
                else if(nums[low] > target) low = mid + 1;
            }
        }
        return -1;
    }
};