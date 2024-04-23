#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_buffer;
        bool result = true;
        for (const char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack_buffer.push(ch);
            } else {
                result = pop_and_check(stack_buffer, ch);  // passing right parenthesis
            }

            if (result == false) {
                return result;
            }
        }
        if (stack_buffer.empty())
            return true;
        else
            return false;
    }

    bool pop_and_check(stack<char>& stack_buffer, char c) {
        if (stack_buffer.empty()) {
            return false;
        }
        
        char top = stack_buffer.top();
        stack_buffer.pop();
        if (c == ')' && top != '(') {
            return false;
        } else if (c == ']' && top != '[') {
            return false;
        } else if (c== '}' && top != '{') {
            return false;
        } else {
            return true;
        }
    }
};
