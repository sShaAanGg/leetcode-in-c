#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> char_count;
        for (char ch : s) {
            auto it = char_count.find(ch);
            if (it != char_count.end()) {  // char found
                it->second = it->second + 1;
            } else {
                char_count[ch] = 1;
            }
        }

        for (char ch : t) {  // iterate through the target
            auto it = char_count.find(ch);
            if (it != char_count.end()) {  // char found
                it->second = it->second - 1;
            } else {
                return false;
            }
        }

        for (const auto &entry : char_count) {
            if (entry.second != 0) {
                return false;
            }
        }
        return true;
    }
};

