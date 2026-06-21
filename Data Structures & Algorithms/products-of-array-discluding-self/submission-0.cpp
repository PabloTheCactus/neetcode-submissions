class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product;
        bool flag = false;
        int tmp = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            tmp = 1;
            flag = false;
            for(int j = 0; j < nums.size(); j++){
                if(j != i){
                    tmp*=nums[j];
                }
                if(j != i && nums[j] != 0){ flag = true; }
            }
            if(flag == false) product.push_back(0);
            else product.push_back(tmp);
        }
        return product;
    }
};
