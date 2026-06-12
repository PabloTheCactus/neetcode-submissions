class Solution {
public:
    void backtrack(int open, int close, int n, string& stack, vector<string>& result){
        if(open == n && n == close){
            result.push_back(stack);
            return;
        }
        if(open < n){
            stack +="(";
            backtrack(open + 1, close, n, stack, result);
            stack.pop_back();
        }
        if(close < open){
            stack +=")";
            backtrack(open, close + 1, n, stack, result);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string stack;
        vector<string> result;
        backtrack(0,0,n,stack,result);
        return result;
    }
};
