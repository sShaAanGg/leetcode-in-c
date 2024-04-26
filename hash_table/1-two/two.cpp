#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;  // maps number -> index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = num_map.find(complement);
            if (it != num_map.end()) {  // complement found
                return {it->second, i};  // return complement's index and i
            } else {
                num_map[nums[i]] = i;  // insert the pair (number, index)
            }
        }
        return {};
    }
};
