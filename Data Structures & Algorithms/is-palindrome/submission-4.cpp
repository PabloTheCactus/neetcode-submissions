class Solution {
public:
    bool isPalindrome(string s) {
        char leftptr = 0;
        char rightptr = s.length() - 1;
        while(leftptr < rightptr){
            while (leftptr != rightptr && !isalnum(s[leftptr])){leftptr++;}
            while (leftptr != rightptr && !isalnum(s[rightptr])){rightptr--;}
            if(tolower(s[leftptr]) != tolower(s[rightptr])){
                return false;
            }
            else
            rightptr--;
            leftptr++;
        }
        return true;
    }
};
