class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stack;
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!stack.empty() && stack.top().first < temperatures[i]){
                result[stack.top().second] = i - stack.top().second;
                stack.pop();
            }
            stack.push({temperatures[i], i});
        }
        return result;
    }
};
