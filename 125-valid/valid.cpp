class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (left >= right) {
                return true;
            } else if (tolower(s[left]) != tolower(s[right])) {  // left < right
                return false;
            } else {  // left < right && s[left] == s[right]
                left++;
                right--;
            }
        }
        return true;
    }
};

