/*
O(n) where n is the size of stack same as length of string.

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

link : https://leetcode.com/problems/valid-parentheses/

*/

class Solution {
public:
    bool isValid(string s) {

        stack<char> check;

        //to make the closing bracket correspond to its opening bracket
        unordered_map <char, char> m {
            {')', '('},
            {'}', '{'},
            {']', '['}, 
        };

        for (const auto &c : s) {

            if (m.find(c) != m.end()) {
                
                //for some case it gave runtime error for empty stacks
                if (check.empty()) {
                    return false;
                }
                
                //when we find corresponding open bracket for closed ones
                if(check.top() == m[c]) {
                    check.pop();
                }
                else{
                    return false;
                }
            }
            else {
                //pushing open brackets
                check.push(c);
            }
        }

        //returning if stack came out empty in the end
        return check.empty();
    }
};