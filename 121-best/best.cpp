#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = INT_MIN;
        int min_price = INT_MAX;

        for (const int price : prices) {
            min_price = min(price, min_price);
            max_profit = max(price - min_price, max_profit);
        }

        if (max_profit > 0)
            return max_profit;
        else
            return 0;
    }
};
