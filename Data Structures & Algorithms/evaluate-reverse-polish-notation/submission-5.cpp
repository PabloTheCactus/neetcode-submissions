class Solution {
public:
    stack<int> symb;
    
    int evalRPN(vector<string>& tokens) {
        for(auto i : tokens){
            if(!(i == "+" || i == "-" || i == "*" || i == "/")){
                symb.push(stoi(i));
            }
            else if(i == "+"){
                symb.push(func(symb) + func(symb));
                
            }
            else if(i == "-"){
                int second = func(symb);
                int first = func(symb);
                symb.push(first - second);
            }
            else if(i == "/"){
                int second = func(symb);
                int first = func(symb);
                symb.push(first / second);
            }
            else if(i == "*"){
                symb.push(func(symb) * func(symb));
            }
        }
        return symb.top();
    }
    int func(stack<int>& st){
        int tmp = 0;
        tmp = st.top();
        st.pop();
        return tmp;
    }
};
